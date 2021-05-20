#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QtDebug>
#include <QListWidget>
#include "qtlisting.h"
#include "user.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentListing = NULL;
    curUser = NULL;
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

qDebug() << "test ";
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
    curUser = progData.verifyUser(email.toStdString() , pass.toStdString() );
    if (curUser == NULL) {
        MainWindow::findChild<QLabel *>("LoginFail")->show();
    }
    else {
        MainWindow::findChild<QFrame *>("Listings")->raise();
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
    if (progData.UserExists(email.toStdString())) {
         MainWindow::findChild<QLabel *>("SignupFail")->show();
    }
    else {
        user* u = new user(usern.toStdString(), pass.toStdString(), email.toStdString());
        progData.AddUser(u);
        curUser = u;
        MainWindow::findChild<QFrame *>("Listings")->raise();
    }

    //user Newuser(usern, email, pass);

    // add info to database file
    // declare user
    //if verified
    //user newU(usern.toStdString(), pass.toStdString(), email.toStdString());



}

void MainWindow::countryChange1(const QString &text) {
    qDebug() << "test " << text;
    vector<country> temp = progData.getCountries();
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
    vector<country> temp = progData.getCountries();
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
    vector<country> temp = progData.getCountries();
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
    vector<country> temp = progData.getCountries();
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
}
void MainWindow::SortCruises(const QString &text) {
    SortHotels(text);
}


void MainWindow::DisplayFlights() {
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("FlightFrom");
    QComboBox *citydepselect = MainWindow::findChild<QComboBox *>("FromCitySelect");
    QComboBox *arrctrySelect = MainWindow::findChild<QComboBox *>("FlightTo");
    QComboBox *cityarrselect = MainWindow::findChild<QComboBox *>("ToCitySelect");

    vector<Node<flightlisting*>*> mylist = progData.GetFlightsInLoc(ctrySelect->currentText().toStdString(), citydepselect->currentText().toStdString(), arrctrySelect->currentText().toStdString(), cityarrselect->currentText().toStdString());
    //qDebug() << "test " << sort;
    if (sort > 0) {
        int index = 0;
        Node<flightlisting*>* min;
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

    vector<Node<hotellisting*>*> mylist = progData.GetHotelsInLoc(ctrySelect->currentText().toStdString(), htlcity->currentText().toStdString(), persons->currentText().toInt(), pool->isChecked(), pets->isChecked(), beach->isChecked(), bkfast->isChecked(), dinner->isChecked());
    //qDebug() << "test " << sort;
    if (sort > 0) {
        int index = 0;
        Node<hotellisting*>* min;
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
            MainWindow::findChild<QListWidget *>("HotelListings")->insertItem(0, listtest->getitem());
            MainWindow::findChild<QListWidget *>("HotelListings")->setItemWidget(listtest->getitem(), listtest->getwidget());

            mylist.erase(mylist.begin() + index);
        }
    }
    else {
        for (int n = 0; n < mylist.size(); n++) {
            QtListing *listtest = new QtListing(mylist[n]->data, mylist[n]->initialIndex);  // adding an element to the list
            listtest->setMainProg(this);
            MainWindow::findChild<QListWidget *>("HotelListings")->insertItem(0, listtest->getitem());
            MainWindow::findChild<QListWidget *>("HotelListings")->setItemWidget(listtest->getitem(), listtest->getwidget());
        }
    }
}

void MainWindow::DisplayCruises() {
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("CruiseCountry");
    QComboBox *crzcity = MainWindow::findChild<QComboBox *>("CruiseCitySelect");
    //QComboBox *persons = MainWindow::findChild<QComboBox *>("CruisePersonsNum");
    //QCheckBox *pool = MainWindow::findChild<QCheckBox *>("pool_2");
    //QCheckBox *pets = MainWindow::findChild<QCheckBox *>("pets_2");

    vector<Node<cruise*>*> mylist = progData.GetCruisesInLoc(ctrySelect->currentText().toStdString(), crzcity->currentText().toStdString());
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

}
void MainWindow::deleteListing() {
    int type = currentListing->getType();
    int index = currentListing->getIndex();

    if (type == 1) {
        progData.deleteHlisting(index);
    }
    else if (type == 2) {
        progData.deleteFlisting(index);
    }
    else if (type == 3) {
        progData.deleteClisting(index);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

