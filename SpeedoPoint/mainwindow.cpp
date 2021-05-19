#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QtDebug>
#include <QListWidget>
#include "qtlisting.h"
#include "user.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *test = MainWindow::findChild<QPushButton *>("LoginSwitch");
    QPushButton *test2 = MainWindow::findChild<QPushButton *>("SignupSwitch");

    connect(test, SIGNAL(released()), this, SLOT(SwitchSignup()));
    connect(test2, SIGNAL(released()), this, SLOT(SwitchLogin()));

    QPushButton *loginbut = MainWindow::findChild<QPushButton *>("LoginButton");
    connect(loginbut, SIGNAL(released()), this, SLOT(Login()));

    QPushButton *signupbut = MainWindow::findChild<QPushButton *>("SignupButton");
    connect(signupbut, SIGNAL(released()), this, SLOT(Signup()));

    MainWindow::findChild<QFrame *>("LoginScreen")->raise();

    MainWindow::findChild<QFrame *>("Listings")->raise();


    QtListing *listtest = new QtListing();  // adding an element to the list
    MainWindow::findChild<QListWidget *>("FlightListings")->insertItem(0, listtest->getitem());
    MainWindow::findChild<QListWidget *>("FlightListings")->setItemWidget(listtest->getitem(), listtest->getwidget());

    //QtListing *listtest = new QtListing(MainWindow::findChild<QListWidget *>("FlightListings"));

    QComboBox *fromcountrys = MainWindow::findChild<QComboBox *>("FlightFrom");
    connect(fromcountrys, SIGNAL(QComboBox::currentTextChanged(const QString &text)), this, SLOT(countryChange1(const QString &text)));

    QComboBox *tocountrys = MainWindow::findChild<QComboBox *>("FlightTo");
    connect(fromcountrys, SIGNAL(QComboBox::currentTextChanged(const QString &text)), this, SLOT(countryChange2(const QString &text)));

    QPushButton *flightsearch = MainWindow::findChild<QPushButton *>("SearchFlights");
    connect(flightsearch, SIGNAL(released()), this, SLOT(DisplayFlights()));

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
    qDebug() << "test " << text;
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

void MainWindow::DisplayFlights() {
    QComboBox *ctrySelect = MainWindow::findChild<QComboBox *>("FlightFrom");
    QComboBox *citydepselect = MainWindow::findChild<QComboBox *>("FromCitySelect");
    QComboBox *arrctrySelect = MainWindow::findChild<QComboBox *>("FlightTo");
    QComboBox *cityarrselect = MainWindow::findChild<QComboBox *>("ToCitySelect");

    vector<flightlisting> mylist = progData.GetFlightsInLoc(ctrySelect->currentText().toStdString(), citydepselect->currentText().toStdString(), arrctrySelect->currentText().toStdString(), cityarrselect->currentText().toStdString());

    for (int i = 0; i < mylist.size(); i++) {
        QtListing *listtest = new QtListing(mylist[i]);  // adding an element to the list
        MainWindow::findChild<QListWidget *>("FlightListings")->insertItem(0, listtest->getitem());
        MainWindow::findChild<QListWidget *>("FlightListings")->setItemWidget(listtest->getitem(), listtest->getwidget());
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

