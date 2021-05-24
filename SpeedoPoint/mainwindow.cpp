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
#include <queue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentListing = NULL;
    curUser = NULL;
    progData = new dataStore();
    MainWindow::findChild<QLabel *>("LoginFail")->hide();
    MainWindow::findChild<QLabel *>("SignupFail")->hide();
    QPushButton *test = MainWindow::findChild<QPushButton *>("LoginSwitch");
    QPushButton *test2 = MainWindow::findChild<QPushButton *>("SignupSwitch");

    connect(test, SIGNAL(released()), this, SLOT(SwitchSignup()));
    connect(test2, SIGNAL(released()), this, SLOT(SwitchLogin()));
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


    MainWindow::findChild<QVBoxLayout *>("testlist")->setAlignment(Qt::AlignTop);


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
    for (std::vector<int>::size_type i = 0; i < temp.size(); i++) {
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
int sortt;

template <class T>
class cmp {
public:
    bool operator() (Node<T*>* A, Node<T*>* B)
    {
        //qDebug() << sortt << "sortt";
        if (sortt == 1) {
            if (A->priceRankIndex > B->priceRankIndex)
                return true;

        }
        if (sortt == 2) {
            if (A->ratingRankIndex > B->ratingRankIndex)
                return true;

        }
        if (sortt == 3) {
            if (A->DistRankIndex < B->DistRankIndex)
                return true;

        }
        return false;
    }
};


void MainWindow::DisplayFlights() {
    sortt = sort;
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("FlightFrom");
    QComboBox *citydepselect = MainWindow::findChild<QComboBox *>("FromCitySelect");
    QComboBox *arrctrySelect = MainWindow::findChild<QComboBox *>("FlightTo");
    QComboBox *cityarrselect = MainWindow::findChild<QComboBox *>("ToCitySelect");

    QVBoxLayout* testlist = MainWindow::findChild<QVBoxLayout *>("flightlist");

    for (int i = 0; i < listings.size(); i++) {
        testlist->removeWidget(listings[i]->getwidget());
        listings[i]->getwidget()->setVisible(false);
    }
    vector<Node<flightlisting*>*> mylist = progData->GetFlightsInLoc(ctrySelect->currentText().toStdString(), citydepselect->currentText().toStdString(), arrctrySelect->currentText().toStdString(), cityarrselect->currentText().toStdString(), MainWindow::findChild<QCheckBox *>("Refundable")->isChecked(), !MainWindow::findChild<QCheckBox *>("TwoWay")->isChecked());

    if (mylist.empty()) {
        return;
    }

    if (sort > 0) {

        priority_queue<Node<flightlisting*>*, vector<Node<flightlisting*>*>, cmp<flightlisting>> queuetest;
        for (int n = 0; n < mylist.size(); n++) {
            queuetest.push(mylist[n]);
            qDebug() << mylist[n]->priceRankIndex << "rank" << mylist[n]->data->getPriceperTraveller();
        }
        while (!queuetest.empty()) {

            QtListing *listtest = new QtListing(queuetest.top()->data, queuetest.top()->initialIndex);  // adding an element to the list
            listings.push_back(listtest);
            listtest->setMainProg(this);
            testlist->addWidget(listtest->getwidget());
            queuetest.pop();
        }

    }
    else {
        for (int n = 0; n < mylist.size(); n++) {
            QtListing *listtest = new QtListing(mylist[n]->data, mylist[n]->initialIndex);  // adding an element to the list
            listings.push_back(listtest);
            listtest->setMainProg(this);
            testlist->addWidget(listtest->getwidget());
        }
    }
}

void MainWindow::DisplayHotels() {
    sortt = sort;
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("HotelCountry");
    QComboBox *htlcity = MainWindow::findChild<QComboBox *>("HotelCitySelect");
    QComboBox *persons = MainWindow::findChild<QComboBox *>("HotelPersonsNum");
    QCheckBox *pool = MainWindow::findChild<QCheckBox *>("pool");
    QCheckBox *pets = MainWindow::findChild<QCheckBox *>("pets");
    QCheckBox *beach = MainWindow::findChild<QCheckBox *>("beach");
    QCheckBox *bkfast = MainWindow::findChild<QCheckBox *>("breakfast");
    QCheckBox *dinner = MainWindow::findChild<QCheckBox *>("dinner");

    qDebug() << htlcity->currentText();
    vector<Node<hotellisting*>*> mylist = progData->GetHotelsInLoc(ctrySelect->currentText().toStdString(), htlcity->currentText().toStdString(), persons->currentText().toInt(), pool->isChecked(), pets->isChecked(), beach->isChecked(), bkfast->isChecked(), dinner->isChecked());

    //MainWindow::findChild<QListWidget *>("HotelListings")->clear();

    //QListWidget* mListWidget = MainWindow::findChild<QListWidget *>("HotelListings");
    //testlist
    QVBoxLayout* testlist = MainWindow::findChild<QVBoxLayout *>("testlist");

    //mListWidget->clear();

    //QListWidgetItem *item = NULL;
    for (int i = 0; i < listings.size(); i++) {
        //mListWidget->removeItemWidget(mListWidget->item(i));
        //mListWidget->item(i)->setVisible(false);


        //QWidget *item = testlist->wid(I)
        testlist->removeWidget(listings[i]->getwidget());
        listings[i]->getwidget()->setVisible(false);

        //delete listings[i]->getwidget());
        //listings[i]->setnull();
        //delete listings[i];


        //remove(mListWidget->takeItem(i))
        //mListWidget->editItem(item);

        //item = mListWidget->takeItem(0);
    }


    //qDebug() << "testw " << mListWidget->count();
    //qDebug() << pool->isChecked() << pets->isChecked() << beach->isChecked() << bkfast->isChecked() << dinner->isChecked();
    //qDebug() << "test " << sort;
    if (sort > 0) {
        priority_queue<Node<hotellisting*>*, vector<Node<hotellisting*>*>, cmp<hotellisting>> queuetest;
        for (int n = 0; n < mylist.size(); n++) {
            queuetest.push(mylist[n]);
            qDebug() << mylist[n]->priceRankIndex << "rank" << mylist[n]->data->getPricePerNight();
        }
        while (!queuetest.empty()) {

            QtListing *listtest = new QtListing(queuetest.top()->data, queuetest.top()->initialIndex);  // adding an element to the list
            listings.push_back(listtest);
            listtest->setMainProg(this);
            testlist->addWidget(listtest->getwidget());
            queuetest.pop();
        }
        /*
        int testval = 0;
        while(testval < mylist.size()) {
            min = mylist[0];
            for (int n = 0; n < mylist.size(); n++) {
                if (min != NULL) {
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
            }
            qDebug() << "test " << mylist.size();
            QtListing *listtest = new QtListing(min->data, min->initialIndex);  // adding an element to the list
            listings.push_back(listtest);
            listtest->setMainProg(this);
            testlist->addWidget(listtest->getwidget());
            min = NULL;

            //mListWidget->insertItem(0, listtest->getitem());

            //mListWidget->item(testval)->setSizeHint(listtest->getwidget()->sizeHint());
            //mListWidget->setItemWidget(mListWidget->item(testval), listtest->getwidget());
            testval++;
            qDebug() << "test ";
            //mylist.erase(mylist.begin() + index);
        }*/
    }
    else {
        for (std::vector<int>::size_type n = 0; n < mylist.size(); n++) {
            if (mylist[n] != NULL) {
                qDebug() << "thi is it ";
                QtListing *listtest = new QtListing(mylist[n]->data, mylist[n]->initialIndex);  // adding an element to the list
                listings.push_back(listtest);
                listtest->setMainProg(this);
                testlist->addWidget(listtest->getwidget());


                //mListWidget->insertItem(0, listtest->getitem());
                //mListWidget->item(n)->setSizeHint(listtest->getwidget()->sizeHint());

                //mListWidget->item(n)->setSizeHint(listtest->getwidget()->sizeHint());
                //mListWidget->setItemWidget(mListWidget->item(n), listtest->getwidget());


                //delete mListWidget->takeItem(1);


                //mListWidget->repaint();

            }
        }

    }
    qDebug() << "testy ";
}

void MainWindow::DisplayCruises() {
    sortt = sort;
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("CruiseCountry");
    QComboBox *crzcity = MainWindow::findChild<QComboBox *>("CruiseCitySelect");
    //QComboBox *persons = MainWindow::findChild<QComboBox *>("CruisePersonsNum");
    //QCheckBox *pool = MainWindow::findChild<QCheckBox *>("pool_2");
    //QCheckBox *pets = MainWindow::findChild<QCheckBox *>("pets_2");

    vector<Node<cruise*>*> mylist = progData->GetCruisesInLoc(ctrySelect->currentText().toStdString(), crzcity->currentText().toStdString());

    QVBoxLayout* testlist = MainWindow::findChild<QVBoxLayout *>("cruiselist");

    for (int i = 0; i < listings.size(); i++) {
        testlist->removeWidget(listings[i]->getwidget());
        listings[i]->getwidget()->setVisible(false);
    }

    if (sort > 0) {
        priority_queue<Node<cruise*>*, vector<Node<cruise*>*>, cmp<cruise>> queuetest;
        for (int n = 0; n < mylist.size(); n++) {
            queuetest.push(mylist[n]);
            qDebug() << mylist[n]->priceRankIndex << "rank" << mylist[n]->data->getPricePerPerson();
        }
        while (!queuetest.empty()) {

            QtListing *listtest = new QtListing(queuetest.top()->data, queuetest.top()->initialIndex);  // adding an element to the list
            listings.push_back(listtest);
            listtest->setMainProg(this);
            testlist->addWidget(listtest->getwidget());
            queuetest.pop();
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

