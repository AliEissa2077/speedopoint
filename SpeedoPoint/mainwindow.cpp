#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QtDebug>
#include <QListWidget>
#include "qtlisting.h"
#include "user.h"
#include <algorithm>
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentListing = NULL;
    curUser = NULL;
    progData = new dataStore();
    qDebug() << "test ";
    MainWindow::findChild<QLabel *>("LoginFail")->hide();
    MainWindow::findChild<QLabel *>("SignupFail")->hide();
qDebug() << "test ";
    QPushButton *test = MainWindow::findChild<QPushButton *>("LoginSwitch");
    QPushButton *test2 = MainWindow::findChild<QPushButton *>("SignupSwitch");

    connect(test, SIGNAL(released()), this, SLOT(SwitchSignup()));
    connect(test2, SIGNAL(released()), this, SLOT(SwitchLogin()));
qDebug() << "test ";
    QPushButton *loginbut = MainWindow::findChild<QPushButton *>("LoginButton");
    connect(loginbut, SIGNAL(released()), this, SLOT(Login()));

    QPushButton *signupbut = MainWindow::findChild<QPushButton *>("SignupButton");
    connect(signupbut, SIGNAL(released()), this, SLOT(Signup()));

    MainWindow::findChild<QFrame *>("LoginScreen")->raise();

    //MainWindow::findChild<QFrame *>("Listings")->raise();


    /*QtListing *listtest = new QtListing();  // adding an element to the list
    MainWindow::findChild<QListWidget *>("FlightListings")->insertItem(0, listtest->getitem());
    MainWindow::findChild<QListWidget *>("FlightListings")->setItemWidget(listtest->getitem(), listtest->getwidget());*/

    //QtListing *listtest = new QtListing(MainWindow::findChild<QListWidget *>("FlightListings"));

    QComboBox *fromcountrys = MainWindow::findChild<QComboBox *>("FlightFrom");
    connect(fromcountrys, SIGNAL(currentTextChanged(QString)), this, SLOT(countryChange1(QString)));

    QComboBox *tocountrys = MainWindow::findChild<QComboBox *>("FlightTo");
    connect(tocountrys, SIGNAL(currentTextChanged(QString)), this, SLOT(countryChange2(QString)));

    QPushButton *flightsearch = MainWindow::findChild<QPushButton *>("SearchFlights");
    connect(flightsearch, SIGNAL(released()), this, SLOT(DisplayFlights()));

    QComboBox *flightsort = MainWindow::findChild<QComboBox *>("SortBy");
    connect(flightsort, SIGNAL(currentTextChanged(QString)), this, SLOT(SortFlights(QString)));

qDebug() << "test ";
    QPushButton *hotelSearch = MainWindow::findChild<QPushButton *>("SearchHotel");
    connect(hotelSearch, SIGNAL(released()), this, SLOT(DisplayHotels()));

    QComboBox *hotelSort = MainWindow::findChild<QComboBox *>("HotelSort");
    connect(hotelSort, SIGNAL(currentTextChanged(QString)), this, SLOT(SortHotels(QString)));

    QComboBox *hotelctry = MainWindow::findChild<QComboBox *>("HotelCountry");
    connect(hotelctry, SIGNAL(currentTextChanged(QString)), this, SLOT(countryChangeHotel(QString)));


    QPushButton *cruisesearch = MainWindow::findChild<QPushButton *>("SearchCruise");
    connect(cruisesearch, SIGNAL(released()), this, SLOT(DisplayCruises()));

    QComboBox *cruisesort = MainWindow::findChild<QComboBox *>("CruiseSort");
    connect(cruisesort, SIGNAL(currentTextChanged(QString)), this, SLOT(SortCruises(QString)));

    QComboBox *cruisectry = MainWindow::findChild<QComboBox *>("CruiseCountry");
    connect(cruisectry, SIGNAL(currentTextChanged(QString)), this, SLOT(countryChangeCruise(QString)));

    QPushButton *detailsback = MainWindow::findChild<QPushButton *>("DetailsBack");
    connect(detailsback, SIGNAL(released()), this, SLOT(DetailsBack()));

    QPushButton *bookbut = MainWindow::findChild<QPushButton *>("Book");
    connect(bookbut, SIGNAL(released()), this, SLOT(bookListing()));


    QPushButton *depbut = MainWindow::findChild<QPushButton *>("deposit");
    connect(depbut, SIGNAL(released()), this, SLOT(DepositAcc()));



}

void MainWindow::SwitchLogin() {
    MainWindow::findChild<QFrame *>("SignUpFrame")->setEnabled(false);
    MainWindow::findChild<QFrame *>("SignUpFrame")->setHidden(true);

    MainWindow::findChild<QFrame *>("LoginFrame")->setEnabled(true);
    MainWindow::findChild<QFrame *>("LoginFrame")->raise();
    MainWindow::findChild<QFrame *>("LoginFrame")->setHidden(false);

}

void MainWindow::SwitchSignup() {


    MainWindow::findChild<QFrame *>("LoginFrame")->setEnabled(false);
    MainWindow::findChild<QFrame *>("LoginFrame")->setHidden(true);

    MainWindow::findChild<QFrame *>("SignUpFrame")->setEnabled(true);
    MainWindow::findChild<QFrame *>("SignUpFrame")->raise();
    MainWindow::findChild<QFrame *>("SignUpFrame")->setHidden(false);

}

void MainWindow::Login() {
    QString email;
    QString pass;
    email = MainWindow::findChild<QLineEdit *>("EmailEntryLogin")->text();
    pass = MainWindow::findChild<QLineEdit *>("PasswordEntryLogin")->text();

    //qDebug() << email;
    //qDebug() << pass;

    // check with users database file
    // declare user as the database one
    curUser = progData->verifyUser(email.toStdString() , pass.toStdString() );
    if (curUser == NULL) {
        MainWindow::findChild<QLabel *>("LoginFail")->show();
    }
    else {
        MainWindow::findChild<QFrame *>("Listings")->raise();
        MainWindow::findChild<QLabel *>("WalletAmount")->setText(QString::number(curUser->getWallet()->getAmount()));
    }

}

void MainWindow::Signup() {
    QString email;
    QString pass;
    QString usern;
    email = MainWindow::findChild<QLineEdit *>("EmailEntry")->text();
    pass = MainWindow::findChild<QLineEdit *>("PasswordEntry")->text();
    usern = MainWindow::findChild<QLineEdit *>("UsernameEntry")->text();

    //qDebug() << email;
    //qDebug() << pass;
    //qDebug() << usern;
    //check database first
    if (progData->UserExists(email.toStdString())) {
         MainWindow::findChild<QLabel *>("SignupFail")->show();
    }
    else {
        //user* u =

        curUser = new user(usern.toStdString(), pass.toStdString(), email.toStdString());
        progData->AddUser(curUser);
        MainWindow::findChild<QFrame *>("Listings")->raise();
        //MainWindow::findChild<QFrame *>("DetailsPage")->raise();
        MainWindow::findChild<QLabel *>("WalletAmount")->setText(QString::number(curUser->getWallet()->getAmount()));
    }

    //user Newuser(usern, email, pass);

    // add info to database file
    // declare user
    //if verified
    //user newU(usern.toStdString(), pass.toStdString(), email.toStdString());



}

void MainWindow::countryChange1(const QString &text) {
    qDebug() << "test " << text;
    vector<country> temp = progData->getCountries();
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i].getName().compare(text.toStdString()) == 0) {
            QComboBox *cities = MainWindow::findChild<QComboBox *>("FromCitySelect");
            cities->clear();
            for (int n =0; n < temp[i].getCities().size(); n++) {
                cities->addItem(QString::fromStdString(temp[i].getCities()[n]));
            }
            return;
        }
    }
}

void MainWindow::countryChange2(const QString &text) {
    vector<country> temp = progData->getCountries();
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i].getName().compare(text.toStdString()) == 0) {
            QComboBox *cities = MainWindow::findChild<QComboBox *>("ToCitySelect");
            cities->clear();
            for (int n =0; n < temp[i].getCities().size(); n++) {
                cities->addItem(QString::fromStdString(temp[i].getCities()[n]));
            }
            return;
        }
    }
}
void MainWindow::countryChangeHotel(const QString &text) {
    vector<country> temp = progData->getCountries();
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i].getName().compare(text.toStdString()) == 0) {
            QComboBox *cities = MainWindow::findChild<QComboBox *>("HotelCitySelect");
            cities->clear();
            for (int n =0; n < temp[i].getCities().size(); n++) {
                cities->addItem(QString::fromStdString(temp[i].getCities()[n]));
            }
            return;
        }
    }
}
void MainWindow::countryChangeCruise(const QString &text) {
    vector<country> temp = progData->getCountries();
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i].getName().compare(text.toStdString()) == 0) {
            QComboBox *cities = MainWindow::findChild<QComboBox *>("CruiseCitySelect");
            cities->clear();
            for (int n =0; n < temp[i].getCities().size(); n++) {
                cities->addItem(QString::fromStdString(temp[i].getCities()[n]));
            }
            return;
        }
    }
}
void MainWindow::SortFlights(const QString &text) {
    if (text.compare(QString::fromStdString("Price")) == 0) {
        sort = 1;
    }
    else if (text.compare(QString::fromStdString("Rating")) == 0) {
        sort = 2;
    }
    else if (text.compare(QString::fromStdString("Distance")) == 0) {
        sort = 3;
    }
    else {
        sort = 0;
    }
}

void MainWindow::SortHotels(const QString &text) {
    if (text.compare(QString::fromStdString("Price")) == 0) {
        sort = 1;
    }
    else if (text.compare(QString::fromStdString("Rating")) == 0) {
        sort = 2;
    }
    else {
        sort = 0;
    }
    //qDebug() << "test " << sort;
}
void MainWindow::SortCruises(const QString &text) {
    SortHotels(text);
}


void MainWindow::DisplayFlights() {
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("FlightFrom");
    QComboBox *citydepselect = MainWindow::findChild<QComboBox *>("FromCitySelect");
    QComboBox *arrctrySelect = MainWindow::findChild<QComboBox *>("FlightTo");
    QComboBox *cityarrselect = MainWindow::findChild<QComboBox *>("ToCitySelect");

    qDebug() << "test " << sort;
    vector<Node<flightlisting*>*> mylist = progData->GetFlightsInLoc(ctrySelect->currentText().toStdString(), citydepselect->currentText().toStdString(), arrctrySelect->currentText().toStdString(), cityarrselect->currentText().toStdString(), MainWindow::findChild<QCheckBox *>("Refundable")->isChecked(), MainWindow::findChild<QCheckBox *>("OneWay")->isChecked());
    qDebug() << "test " << sort;
    if (sort > 0) {
        int index = 0;
        Node<flightlisting*>* min;
        if (mylist.size() > 0) {
            min = mylist[0];
        }
        while(!mylist.empty()) {
            qDebug() << "test " << sort;
            for (int n = 0; n < mylist.size(); n++) {

                if (sort == 1) {
                    if (min->priceRankIndex > mylist[n]->priceRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
                if (sort == 2) {
                    if (min->ratingRankIndex > mylist[n]->ratingRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
                if (sort == 3) {
                    if (min->DistRankIndex > mylist[n]->DistRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }

            }
            QtListing *listtest = new QtListing(min->data, min->initialIndex);  // adding an element to the list
            listtest->setMainProg(this);
            MainWindow::findChild<QListWidget *>("FlightListings")->insertItem(0, listtest->getitem());
            MainWindow::findChild<QListWidget *>("FlightListings")->setItemWidget(listtest->getitem(), listtest->getwidget());

            mylist.erase(mylist.begin() + index);

        }
    }
    else {
        for (int n = 0; n < mylist.size(); n++) {
            QtListing *listtest = new QtListing(mylist[n]->data, mylist[n]->initialIndex);  // adding an element to the list
            listtest->setMainProg(this);
            MainWindow::findChild<QListWidget *>("FlightListings")->insertItem(0, listtest->getitem());
            MainWindow::findChild<QListWidget *>("FlightListings")->setItemWidget(listtest->getitem(), listtest->getwidget());
        }
    }
}

void MainWindow::DisplayHotels() {
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("HotelCountry");
    QComboBox *htlcity = MainWindow::findChild<QComboBox *>("HotelCitySelect");
    QComboBox *persons = MainWindow::findChild<QComboBox *>("HotelPersonsNum");
    QCheckBox *pool = MainWindow::findChild<QCheckBox *>("pool");
    QCheckBox *pets = MainWindow::findChild<QCheckBox *>("pets");
    QCheckBox *beach = MainWindow::findChild<QCheckBox *>("beach");
    QCheckBox *bkfast = MainWindow::findChild<QCheckBox *>("breakfast");
    QCheckBox *dinner = MainWindow::findChild<QCheckBox *>("dinner");

    vector<Node<hotellisting*>*> mylist = progData->GetHotelsInLoc(ctrySelect->currentText().toStdString(), htlcity->currentText().toStdString(), persons->currentText().toInt(), pool->isChecked(), pets->isChecked(), beach->isChecked(), bkfast->isChecked(), dinner->isChecked());

    //MainWindow::findChild<QListWidget *>("HotelListings")->clear();

    QListWidget* mListWidget = MainWindow::findChild<QListWidget *>("HotelListings");

    //mListWidget->clear();

    int num = mListWidget->count();
    QListWidgetItem *item = NULL;
    for (int i = 0; i < num; i++) {
        item = mListWidget->item(0);
        //delete mListWidget->itemWidget(item);
        //mListWidget->editItem(item);

        //item = mListWidget->takeItem(0);
    }



    mListWidget->repaint();

    qDebug() << "testw " << mListWidget->count();
    qDebug() << pool->isChecked() << pets->isChecked() << beach->isChecked() << bkfast->isChecked() << dinner->isChecked();
    //qDebug() << "test " << sort;
    if (sort > 0) {
        int index = 0;
        Node<hotellisting*>* min;
        if (mylist.size() > 0) {
            min = mylist[0];
        }
        while(!mylist.empty()) {
            min = mylist[0];
            for (int n = 0; n < mylist.size(); n++) {
                qDebug() << min->priceRankIndex <<"to " << mylist[n]->priceRankIndex;
                if (sort == 1) {
                    if (min->priceRankIndex > mylist[n]->priceRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
                if (sort == 2) {
                    if (min->ratingRankIndex > mylist[n]->ratingRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
                if (sort == 3) {
                    if (min->DistRankIndex > mylist[n]->DistRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
            }
            qDebug() << "test " << mylist.size();
            QtListing *listtest = new QtListing(min->data, min->initialIndex);  // adding an element to the list
            listtest->setMainProg(this);

            mListWidget->insertItem(0, listtest->getitem());

            mListWidget->setItemWidget(listtest->getitem(), listtest->getwidget());
            qDebug() << "test ";
            mylist.erase(mylist.begin() + index);
        }
    }
    else {
        for (int n = 0; n < mylist.size(); n++) {
            if (mylist[n] != NULL) {
                qDebug() << "thi is it ";
                QtListing *listtest = new QtListing(mylist[n]->data, mylist[n]->initialIndex);  // adding an element to the list
                listings.push_back(listtest);
                listtest->setMainProg(this);
                qDebug() << "test ";

                mListWidget->insertItem(0, listtest->getitem());

                mListWidget->setItemWidget(listtest->getitem(), listtest->getwidget());

                //delete mListWidget->takeItem(1);


                mListWidget->repaint();

            }
        }

    }
    qDebug() << "testy ";
}

void MainWindow::DisplayCruises() {
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("CruiseCountry");
    QComboBox *crzcity = MainWindow::findChild<QComboBox *>("CruiseCitySelect");
    //QComboBox *persons = MainWindow::findChild<QComboBox *>("CruisePersonsNum");
    //QCheckBox *pool = MainWindow::findChild<QCheckBox *>("pool_2");
    //QCheckBox *pets = MainWindow::findChild<QCheckBox *>("pets_2");

    vector<Node<cruise*>*> mylist = progData->GetCruisesInLoc(ctrySelect->currentText().toStdString(), crzcity->currentText().toStdString());
    //qDebug() << "test " << sort;
    if (sort > 0) {
        int index = 0;
        Node<cruise*>* min;
        if (mylist.size() > 0) {
            min = mylist[0];
        }
        while(!mylist.empty()) {
            for (int n = 0; n < mylist.size(); n++) {

                if (sort == 1) {
                    if (min->priceRankIndex > mylist[n]->priceRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
                if (sort == 2) {
                    if (min->ratingRankIndex > mylist[n]->ratingRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
                if (sort == 3) {
                    if (min->DistRankIndex > mylist[n]->DistRankIndex) {
                        min = mylist[n];
                        index = n;
                    }
                }
            }
            QtListing *listtest = new QtListing(min->data, min->initialIndex);  // adding an element to the list
            listtest->setMainProg(this);
            MainWindow::findChild<QListWidget *>("CruiseListings")->insertItem(0, listtest->getitem());
            MainWindow::findChild<QListWidget *>("CruiseListings")->setItemWidget(listtest->getitem(), listtest->getwidget());

            mylist.erase(mylist.begin() + index);
        }
    }
    else {
        for (int n = 0; n < mylist.size(); n++) {
            QtListing *listtest = new QtListing(mylist[n]->data,  mylist[n]->initialIndex);  // adding an element to the list
            listtest->setMainProg(this);
            MainWindow::findChild<QListWidget *>("CruiseListings")->insertItem(0, listtest->getitem());
            MainWindow::findChild<QListWidget *>("CruiseListings")->setItemWidget(listtest->getitem(), listtest->getwidget());
        }
    }
}

void MainWindow::DetailsBack() {
    MainWindow::findChild<QFrame *>("Listings")->raise();
}

void MainWindow::SetCurrlisting(QtListing* l) {
    currentListing = l;
}
void MainWindow::bookListing() {
    if (currentListing->getType() == 1) {
        qDebug() << "book but press";
        hotellisting* htllist = currentListing->getHListing();
        date d(MainWindow::findChild<QLineEdit *>("Hdays")->text().toInt(), MainWindow::findChild<QLineEdit *>("Hmonth")->text().toInt(), MainWindow::findChild<QLineEdit *>("Hyear")->text().toInt());


        //(user* acc, date d, int days, int adults, int children)
        reservation* r = htllist->reserve(curUser, d, MainWindow::findChild<QComboBox *>("Hdaysnum")->currentText().toInt(), MainWindow::findChild<QComboBox *>("Hadults")->currentText().toInt(), MainWindow::findChild<QComboBox *>("Hchild")->currentText().toInt());
        if (r == NULL) {
            return;
        }

        curUser->updateReservations(r);
        qDebug() << "before delet list";
        deleteListing();

    }
    else if (currentListing->getType() == 2) {
        flightlisting* flist = currentListing->getFListing();
        date d(MainWindow::findChild<QLineEdit *>("Fday")->text().toInt(), MainWindow::findChild<QLineEdit *>("Fmonth")->text().toInt(), MainWindow::findChild<QLineEdit *>("Fyear")->text().toInt(), MainWindow::findChild<QLineEdit *>("Fhour")->text().toInt(), MainWindow::findChild<QLineEdit *>("Fminute")->text().toInt());

        date d2(MainWindow::findChild<QLineEdit *>("FdayR")->text().toInt(), MainWindow::findChild<QLineEdit *>("FmonthR")->text().toInt(), MainWindow::findChild<QLineEdit *>("FyearR")->text().toInt());
        //(user* acc, int adults, int children, date d, date d2)
        flightticket* r;

        if (flist->isOneW()) {
            r = flist->reserve(curUser, MainWindow::findChild<QComboBox *>("Hadults")->currentText().toInt(), MainWindow::findChild<QComboBox *>("Hchild")->currentText().toInt(), d);
        }
        else {
            r = flist->reserve(curUser, MainWindow::findChild<QComboBox *>("Hadults")->currentText().toInt(), MainWindow::findChild<QComboBox *>("Hchild")->currentText().toInt(), d, d2);
        }
        if (r == NULL) {
            return;
        }
        curUser->updateTickets(r);

        deleteListing();
    }
    else if (currentListing->getType() == 3) {
        cruise* htllist = currentListing->getCListing();
        date d(MainWindow::findChild<QLineEdit *>("Hdays")->text().toInt(), MainWindow::findChild<QLineEdit *>("Hmonth")->text().toInt(), MainWindow::findChild<QLineEdit *>("Hyear")->text().toInt());

        //(user* acc, int adults, int children)
        cruisereservation* r = htllist->reserve(curUser, MainWindow::findChild<QComboBox *>("Cadults")->currentText().toInt(), MainWindow::findChild<QComboBox *>("Cchild")->currentText().toInt());
        if (r == NULL) {
            return;
        }


        curUser->updateCruiseReservations(r);

        deleteListing();
    }


}
void MainWindow::deleteListing() {
    int type = currentListing->getType();
    int index = currentListing->getIndex();

    if (type == 1) {
        qDebug() << "list del";
        progData->deleteHlisting(index);
        qDebug() << "list del";
    }
    else if (type == 2) {
        progData->deleteFlisting(index);
    }
    else if (type == 3) {
        progData->deleteClisting(index);
    }


    QMessageBox* confirm = new QMessageBox(0);
    QMessageBox::StandardButton reply1;
    //confirm->exec();
    reply1 = QMessageBox::information(confirm, "Success!", "Reservation made successfully!",
        QMessageBox::Ok);
    if (reply1 == QMessageBox::Ok) {
        DetailsBack();
    }

}

void MainWindow::DepositAcc() {

    bool ok;
    QString text = QInputDialog::getText(this, tr("Deposit money"),
                                         tr("Amount:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
        curUser->getWallet()->deposit(text.toFloat());

    qDebug() << curUser->getWallet()->getAmount();
    MainWindow::findChild<QLabel *>("WalletAmount")->setText(QString::number(curUser->getWallet()->getAmount()));
}
void MainWindow::updateWallet() {
    MainWindow::findChild<QLabel *>("WalletAmount")->setText(QString::number(curUser->getWallet()->getAmount()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

