/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *LoginScreen;
    QGraphicsView *LoginBackground;
    QFrame *LoginFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *loginLabel;
    QLabel *emailLabel_2;
    QLineEdit *EmailEntryLogin;
    QLabel *PassLabel_2;
    QLineEdit *PasswordEntryLogin;
    QPushButton *LoginButton;
    QPushButton *LoginSwitch;
    QLabel *loginFail;
    QFrame *SignUpFrame;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *Signuplabel;
    QLabel *UsernameLabel;
    QLineEdit *UsernameEntry;
    QLabel *emailLabel;
    QLineEdit *EmailEntry;
    QLabel *PassLabel;
    QLineEdit *PasswordEntry;
    QPushButton *SignupButton;
    QPushButton *SignupSwitch;
    QFrame *Listings;
    QGraphicsView *ProgramBackground;
    QLabel *Speedopointtxt;
    QTabWidget *Tabs;
    QWidget *Flights;
    QLabel *fromtext;
    QComboBox *FlightFrom;
    QComboBox *FlightTo;
    QLabel *totext;
    QCheckBox *TwoWay;
    QPushButton *SearchFlights;
    QListWidget *FlightListings;
    QLabel *sorttext;
    QComboBox *SortBy;
    QComboBox *FromCitySelect;
    QComboBox *ToCitySelect;
    QWidget *Hotels;
    QListWidget *HotelListings;
    QLabel *label_5;
    QComboBox *HotelCountry;
    QLabel *label_6;
    QPushButton *SearchHotel;
    QComboBox *HotelPersonsNum;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *HotelSort;
    QCheckBox *pool;
    QCheckBox *pets;
    QCheckBox *beach;
    QCheckBox *breakfast;
    QCheckBox *dinner;
    QComboBox *HotelCitySelect;
    QWidget *Cruises;
    QComboBox *CruiseCitySelect;
    QComboBox *CruisePersonsNum;
    QPushButton *SearchCruise;
    QListWidget *CruiseListings;
    QLabel *label_10;
    QCheckBox *pool_2;
    QComboBox *CruiseCountry;
    QComboBox *CruiseSort;
    QCheckBox *pets_2;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_9;
    QFrame *DetailsPage;
    QGraphicsView *ProgramBackground_2;
    QLabel *Speedopointtxt_2;
    QPushButton *DetailsBack;
    QLabel *PrimaryText;
    QLabel *DetailInfo1;
    QLabel *PricingInfo;
    QLabel *Features;
    QLabel *SecondaryInfo;
    QLabel *SecondaryInfo2;
    QPushButton *Book;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1098, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LoginScreen = new QFrame(centralwidget);
        LoginScreen->setObjectName(QString::fromUtf8("LoginScreen"));
        LoginScreen->setGeometry(QRect(0, 0, 1101, 571));
        LoginScreen->setFrameShape(QFrame::NoFrame);
        LoginScreen->setFrameShadow(QFrame::Raised);
        LoginScreen->setLineWidth(0);
        LoginBackground = new QGraphicsView(LoginScreen);
        LoginBackground->setObjectName(QString::fromUtf8("LoginBackground"));
        LoginBackground->setGeometry(QRect(0, 0, 1101, 571));
        LoginFrame = new QFrame(LoginScreen);
        LoginFrame->setObjectName(QString::fromUtf8("LoginFrame"));
        LoginFrame->setEnabled(true);
        LoginFrame->setGeometry(QRect(330, 170, 391, 271));
        LoginFrame->setFrameShape(QFrame::NoFrame);
        LoginFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(LoginFrame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 20, 291, 215));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        loginLabel = new QLabel(verticalLayoutWidget);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        QFont font;
        font.setBold(true);
        loginLabel->setFont(font);
        loginLabel->setLayoutDirection(Qt::LeftToRight);
        loginLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loginLabel);

        emailLabel_2 = new QLabel(verticalLayoutWidget);
        emailLabel_2->setObjectName(QString::fromUtf8("emailLabel_2"));

        verticalLayout->addWidget(emailLabel_2);

        EmailEntryLogin = new QLineEdit(verticalLayoutWidget);
        EmailEntryLogin->setObjectName(QString::fromUtf8("EmailEntryLogin"));

        verticalLayout->addWidget(EmailEntryLogin);

        PassLabel_2 = new QLabel(verticalLayoutWidget);
        PassLabel_2->setObjectName(QString::fromUtf8("PassLabel_2"));

        verticalLayout->addWidget(PassLabel_2);

        PasswordEntryLogin = new QLineEdit(verticalLayoutWidget);
        PasswordEntryLogin->setObjectName(QString::fromUtf8("PasswordEntryLogin"));

        verticalLayout->addWidget(PasswordEntryLogin);

        LoginButton = new QPushButton(verticalLayoutWidget);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));

        verticalLayout->addWidget(LoginButton);

        LoginSwitch = new QPushButton(verticalLayoutWidget);
        LoginSwitch->setObjectName(QString::fromUtf8("LoginSwitch"));

        verticalLayout->addWidget(LoginSwitch);

        loginFail = new QLabel(verticalLayoutWidget);
        loginFail->setObjectName(QString::fromUtf8("loginFail"));

        verticalLayout->addWidget(loginFail);

        SignUpFrame = new QFrame(LoginScreen);
        SignUpFrame->setObjectName(QString::fromUtf8("SignUpFrame"));
        SignUpFrame->setEnabled(true);
        SignUpFrame->setGeometry(QRect(330, 170, 391, 311));
        SignUpFrame->setFrameShape(QFrame::NoFrame);
        SignUpFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_3 = new QWidget(SignUpFrame);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(50, 20, 291, 267));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Signuplabel = new QLabel(verticalLayoutWidget_3);
        Signuplabel->setObjectName(QString::fromUtf8("Signuplabel"));
        Signuplabel->setFont(font);
        Signuplabel->setLayoutDirection(Qt::LeftToRight);
        Signuplabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(Signuplabel);

        UsernameLabel = new QLabel(verticalLayoutWidget_3);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));

        verticalLayout_3->addWidget(UsernameLabel);

        UsernameEntry = new QLineEdit(verticalLayoutWidget_3);
        UsernameEntry->setObjectName(QString::fromUtf8("UsernameEntry"));

        verticalLayout_3->addWidget(UsernameEntry);

        emailLabel = new QLabel(verticalLayoutWidget_3);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        verticalLayout_3->addWidget(emailLabel);

        EmailEntry = new QLineEdit(verticalLayoutWidget_3);
        EmailEntry->setObjectName(QString::fromUtf8("EmailEntry"));

        verticalLayout_3->addWidget(EmailEntry);

        PassLabel = new QLabel(verticalLayoutWidget_3);
        PassLabel->setObjectName(QString::fromUtf8("PassLabel"));

        verticalLayout_3->addWidget(PassLabel);

        PasswordEntry = new QLineEdit(verticalLayoutWidget_3);
        PasswordEntry->setObjectName(QString::fromUtf8("PasswordEntry"));

        verticalLayout_3->addWidget(PasswordEntry);

        SignupButton = new QPushButton(verticalLayoutWidget_3);
        SignupButton->setObjectName(QString::fromUtf8("SignupButton"));

        verticalLayout_3->addWidget(SignupButton);

        SignupSwitch = new QPushButton(verticalLayoutWidget_3);
        SignupSwitch->setObjectName(QString::fromUtf8("SignupSwitch"));

        verticalLayout_3->addWidget(SignupSwitch);

        SignUpFrame->raise();
        LoginBackground->raise();
        LoginFrame->raise();
        Listings = new QFrame(centralwidget);
        Listings->setObjectName(QString::fromUtf8("Listings"));
        Listings->setGeometry(QRect(0, -1, 1101, 581));
        Listings->setFrameShape(QFrame::StyledPanel);
        Listings->setFrameShadow(QFrame::Raised);
        ProgramBackground = new QGraphicsView(Listings);
        ProgramBackground->setObjectName(QString::fromUtf8("ProgramBackground"));
        ProgramBackground->setGeometry(QRect(10, 10, 1091, 561));
        Speedopointtxt = new QLabel(Listings);
        Speedopointtxt->setObjectName(QString::fromUtf8("Speedopointtxt"));
        Speedopointtxt->setGeometry(QRect(30, 20, 161, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        Speedopointtxt->setFont(font1);
        Tabs = new QTabWidget(Listings);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Tabs->setGeometry(QRect(14, 90, 1041, 451));
        Flights = new QWidget();
        Flights->setObjectName(QString::fromUtf8("Flights"));
        fromtext = new QLabel(Flights);
        fromtext->setObjectName(QString::fromUtf8("fromtext"));
        fromtext->setGeometry(QRect(40, 20, 141, 31));
        QFont font2;
        font2.setPointSize(12);
        fromtext->setFont(font2);
        FlightFrom = new QComboBox(Flights);
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->addItem(QString());
        FlightFrom->setObjectName(QString::fromUtf8("FlightFrom"));
        FlightFrom->setGeometry(QRect(150, 20, 131, 31));
        FlightTo = new QComboBox(Flights);
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->addItem(QString());
        FlightTo->setObjectName(QString::fromUtf8("FlightTo"));
        FlightTo->setGeometry(QRect(510, 20, 101, 31));
        totext = new QLabel(Flights);
        totext->setObjectName(QString::fromUtf8("totext"));
        totext->setGeometry(QRect(460, 20, 71, 31));
        QFont font3;
        font3.setPointSize(11);
        totext->setFont(font3);
        TwoWay = new QCheckBox(Flights);
        TwoWay->setObjectName(QString::fromUtf8("TwoWay"));
        TwoWay->setGeometry(QRect(740, 20, 111, 31));
        SearchFlights = new QPushButton(Flights);
        SearchFlights->setObjectName(QString::fromUtf8("SearchFlights"));
        SearchFlights->setGeometry(QRect(900, 20, 93, 31));
        FlightListings = new QListWidget(Flights);
        FlightListings->setObjectName(QString::fromUtf8("FlightListings"));
        FlightListings->setGeometry(QRect(170, 80, 851, 341));
        sorttext = new QLabel(Flights);
        sorttext->setObjectName(QString::fromUtf8("sorttext"));
        sorttext->setGeometry(QRect(20, 80, 55, 16));
        SortBy = new QComboBox(Flights);
        SortBy->addItem(QString());
        SortBy->addItem(QString());
        SortBy->addItem(QString());
        SortBy->addItem(QString());
        SortBy->setObjectName(QString::fromUtf8("SortBy"));
        SortBy->setGeometry(QRect(70, 80, 81, 22));
        FromCitySelect = new QComboBox(Flights);
        FromCitySelect->setObjectName(QString::fromUtf8("FromCitySelect"));
        FromCitySelect->setGeometry(QRect(310, 20, 101, 31));
        ToCitySelect = new QComboBox(Flights);
        ToCitySelect->setObjectName(QString::fromUtf8("ToCitySelect"));
        ToCitySelect->setGeometry(QRect(630, 20, 91, 31));
        Tabs->addTab(Flights, QString());
        Hotels = new QWidget();
        Hotels->setObjectName(QString::fromUtf8("Hotels"));
        HotelListings = new QListWidget(Hotels);
        HotelListings->setObjectName(QString::fromUtf8("HotelListings"));
        HotelListings->setGeometry(QRect(140, 70, 891, 351));
        label_5 = new QLabel(Hotels);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 20, 91, 21));
        HotelCountry = new QComboBox(Hotels);
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->addItem(QString());
        HotelCountry->setObjectName(QString::fromUtf8("HotelCountry"));
        HotelCountry->setGeometry(QRect(230, 20, 91, 21));
        label_6 = new QLabel(Hotels);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(362, 20, 31, 21));
        SearchHotel = new QPushButton(Hotels);
        SearchHotel->setObjectName(QString::fromUtf8("SearchHotel"));
        SearchHotel->setGeometry(QRect(900, 20, 71, 21));
        HotelPersonsNum = new QComboBox(Hotels);
        HotelPersonsNum->addItem(QString());
        HotelPersonsNum->addItem(QString());
        HotelPersonsNum->addItem(QString());
        HotelPersonsNum->addItem(QString());
        HotelPersonsNum->addItem(QString());
        HotelPersonsNum->addItem(QString());
        HotelPersonsNum->setObjectName(QString::fromUtf8("HotelPersonsNum"));
        HotelPersonsNum->setGeometry(QRect(570, 20, 51, 22));
        label_7 = new QLabel(Hotels);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(510, 20, 55, 21));
        label_8 = new QLabel(Hotels);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 70, 41, 21));
        HotelSort = new QComboBox(Hotels);
        HotelSort->addItem(QString());
        HotelSort->addItem(QString());
        HotelSort->addItem(QString());
        HotelSort->setObjectName(QString::fromUtf8("HotelSort"));
        HotelSort->setGeometry(QRect(40, 70, 91, 22));
        pool = new QCheckBox(Hotels);
        pool->setObjectName(QString::fromUtf8("pool"));
        pool->setGeometry(QRect(20, 120, 81, 20));
        pets = new QCheckBox(Hotels);
        pets->setObjectName(QString::fromUtf8("pets"));
        pets->setGeometry(QRect(20, 150, 101, 20));
        beach = new QCheckBox(Hotels);
        beach->setObjectName(QString::fromUtf8("beach"));
        beach->setGeometry(QRect(20, 180, 111, 20));
        breakfast = new QCheckBox(Hotels);
        breakfast->setObjectName(QString::fromUtf8("breakfast"));
        breakfast->setGeometry(QRect(20, 210, 81, 20));
        dinner = new QCheckBox(Hotels);
        dinner->setObjectName(QString::fromUtf8("dinner"));
        dinner->setGeometry(QRect(20, 240, 81, 20));
        HotelCitySelect = new QComboBox(Hotels);
        HotelCitySelect->setObjectName(QString::fromUtf8("HotelCitySelect"));
        HotelCitySelect->setGeometry(QRect(400, 20, 73, 22));
        Tabs->addTab(Hotels, QString());
        Cruises = new QWidget();
        Cruises->setObjectName(QString::fromUtf8("Cruises"));
        CruiseCitySelect = new QComboBox(Cruises);
        CruiseCitySelect->setObjectName(QString::fromUtf8("CruiseCitySelect"));
        CruiseCitySelect->setGeometry(QRect(400, 10, 73, 22));
        CruisePersonsNum = new QComboBox(Cruises);
        CruisePersonsNum->addItem(QString());
        CruisePersonsNum->addItem(QString());
        CruisePersonsNum->addItem(QString());
        CruisePersonsNum->addItem(QString());
        CruisePersonsNum->addItem(QString());
        CruisePersonsNum->addItem(QString());
        CruisePersonsNum->setObjectName(QString::fromUtf8("CruisePersonsNum"));
        CruisePersonsNum->setGeometry(QRect(570, 10, 51, 22));
        SearchCruise = new QPushButton(Cruises);
        SearchCruise->setObjectName(QString::fromUtf8("SearchCruise"));
        SearchCruise->setGeometry(QRect(900, 10, 71, 21));
        CruiseListings = new QListWidget(Cruises);
        CruiseListings->setObjectName(QString::fromUtf8("CruiseListings"));
        CruiseListings->setGeometry(QRect(140, 60, 891, 351));
        label_10 = new QLabel(Cruises);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(510, 10, 55, 21));
        pool_2 = new QCheckBox(Cruises);
        pool_2->setObjectName(QString::fromUtf8("pool_2"));
        pool_2->setGeometry(QRect(20, 110, 81, 20));
        CruiseCountry = new QComboBox(Cruises);
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->addItem(QString());
        CruiseCountry->setObjectName(QString::fromUtf8("CruiseCountry"));
        CruiseCountry->setGeometry(QRect(230, 10, 91, 21));
        CruiseSort = new QComboBox(Cruises);
        CruiseSort->addItem(QString());
        CruiseSort->addItem(QString());
        CruiseSort->addItem(QString());
        CruiseSort->setObjectName(QString::fromUtf8("CruiseSort"));
        CruiseSort->setGeometry(QRect(40, 60, 91, 22));
        pets_2 = new QCheckBox(Cruises);
        pets_2->setObjectName(QString::fromUtf8("pets_2"));
        pets_2->setGeometry(QRect(20, 140, 101, 20));
        label_12 = new QLabel(Cruises);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 10, 91, 21));
        label_11 = new QLabel(Cruises);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 60, 41, 21));
        label_9 = new QLabel(Cruises);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(362, 10, 31, 21));
        Tabs->addTab(Cruises, QString());
        DetailsPage = new QFrame(centralwidget);
        DetailsPage->setObjectName(QString::fromUtf8("DetailsPage"));
        DetailsPage->setGeometry(QRect(9, 9, 1091, 531));
        DetailsPage->setFrameShape(QFrame::StyledPanel);
        DetailsPage->setFrameShadow(QFrame::Raised);
        ProgramBackground_2 = new QGraphicsView(DetailsPage);
        ProgramBackground_2->setObjectName(QString::fromUtf8("ProgramBackground_2"));
        ProgramBackground_2->setGeometry(QRect(0, 0, 1091, 561));
        Speedopointtxt_2 = new QLabel(DetailsPage);
        Speedopointtxt_2->setObjectName(QString::fromUtf8("Speedopointtxt_2"));
        Speedopointtxt_2->setGeometry(QRect(20, 10, 161, 51));
        Speedopointtxt_2->setFont(font1);
        DetailsBack = new QPushButton(DetailsPage);
        DetailsBack->setObjectName(QString::fromUtf8("DetailsBack"));
        DetailsBack->setGeometry(QRect(20, 70, 61, 28));
        PrimaryText = new QLabel(DetailsPage);
        PrimaryText->setObjectName(QString::fromUtf8("PrimaryText"));
        PrimaryText->setGeometry(QRect(70, 120, 301, 41));
        QFont font4;
        font4.setPointSize(16);
        PrimaryText->setFont(font4);
        DetailInfo1 = new QLabel(DetailsPage);
        DetailInfo1->setObjectName(QString::fromUtf8("DetailInfo1"));
        DetailInfo1->setGeometry(QRect(70, 160, 171, 16));
        PricingInfo = new QLabel(DetailsPage);
        PricingInfo->setObjectName(QString::fromUtf8("PricingInfo"));
        PricingInfo->setGeometry(QRect(610, 130, 141, 31));
        PricingInfo->setFont(font2);
        Features = new QLabel(DetailsPage);
        Features->setObjectName(QString::fromUtf8("Features"));
        Features->setGeometry(QRect(70, 230, 81, 181));
        SecondaryInfo = new QLabel(DetailsPage);
        SecondaryInfo->setObjectName(QString::fromUtf8("SecondaryInfo"));
        SecondaryInfo->setGeometry(QRect(220, 220, 391, 51));
        QFont font5;
        font5.setPointSize(10);
        SecondaryInfo->setFont(font5);
        SecondaryInfo2 = new QLabel(DetailsPage);
        SecondaryInfo2->setObjectName(QString::fromUtf8("SecondaryInfo2"));
        SecondaryInfo2->setGeometry(QRect(224, 286, 341, 171));
        SecondaryInfo2->setFont(font5);
        Book = new QPushButton(DetailsPage);
        Book->setObjectName(QString::fromUtf8("Book"));
        Book->setGeometry(QRect(890, 130, 101, 41));
        Book->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1098, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginLabel->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        emailLabel_2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        PassLabel_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        LoginSwitch->setText(QCoreApplication::translate("MainWindow", "New here? Sign Up", nullptr));
        loginFail->setText(QCoreApplication::translate("MainWindow", "Login failed. Please try again.", nullptr));
        Signuplabel->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        UsernameLabel->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        emailLabel->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        PassLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        SignupButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        SignupSwitch->setText(QCoreApplication::translate("MainWindow", "Already have an account? Login", nullptr));
        Speedopointtxt->setText(QCoreApplication::translate("MainWindow", "SpeedOPoint", nullptr));
        fromtext->setText(QCoreApplication::translate("MainWindow", "Fly From", nullptr));
        FlightFrom->setItemText(0, QCoreApplication::translate("MainWindow", "Argentina", nullptr));
        FlightFrom->setItemText(1, QCoreApplication::translate("MainWindow", "Niger", nullptr));
        FlightFrom->setItemText(2, QCoreApplication::translate("MainWindow", "Palestine", nullptr));
        FlightFrom->setItemText(3, QCoreApplication::translate("MainWindow", "Japan", nullptr));
        FlightFrom->setItemText(4, QCoreApplication::translate("MainWindow", "Austria", nullptr));
        FlightFrom->setItemText(5, QCoreApplication::translate("MainWindow", "Bahamas", nullptr));
        FlightFrom->setItemText(6, QCoreApplication::translate("MainWindow", "Bahrain", nullptr));
        FlightFrom->setItemText(7, QCoreApplication::translate("MainWindow", "Belgium", nullptr));
        FlightFrom->setItemText(8, QCoreApplication::translate("MainWindow", "Bolivia", nullptr));
        FlightFrom->setItemText(9, QCoreApplication::translate("MainWindow", "Brazil", nullptr));
        FlightFrom->setItemText(10, QCoreApplication::translate("MainWindow", "Canada", nullptr));
        FlightFrom->setItemText(11, QCoreApplication::translate("MainWindow", "Chile", nullptr));
        FlightFrom->setItemText(12, QCoreApplication::translate("MainWindow", "Costa Rica", nullptr));
        FlightFrom->setItemText(13, QCoreApplication::translate("MainWindow", "Egypt", nullptr));
        FlightFrom->setItemText(14, QCoreApplication::translate("MainWindow", "Estonia", nullptr));
        FlightFrom->setItemText(15, QCoreApplication::translate("MainWindow", "Finland", nullptr));
        FlightFrom->setItemText(16, QCoreApplication::translate("MainWindow", "France", nullptr));
        FlightFrom->setItemText(17, QCoreApplication::translate("MainWindow", "Greece", nullptr));
        FlightFrom->setItemText(18, QCoreApplication::translate("MainWindow", "Italy", nullptr));
        FlightFrom->setItemText(19, QCoreApplication::translate("MainWindow", "Germany", nullptr));

        FlightTo->setItemText(0, QCoreApplication::translate("MainWindow", "Austria", nullptr));
        FlightTo->setItemText(1, QCoreApplication::translate("MainWindow", "Bahamas", nullptr));
        FlightTo->setItemText(2, QCoreApplication::translate("MainWindow", "Argentina", nullptr));
        FlightTo->setItemText(3, QCoreApplication::translate("MainWindow", "Bahrain", nullptr));
        FlightTo->setItemText(4, QCoreApplication::translate("MainWindow", "Belgium", nullptr));
        FlightTo->setItemText(5, QCoreApplication::translate("MainWindow", "Bolivia", nullptr));
        FlightTo->setItemText(6, QCoreApplication::translate("MainWindow", "Brazil", nullptr));
        FlightTo->setItemText(7, QCoreApplication::translate("MainWindow", "Canada", nullptr));
        FlightTo->setItemText(8, QCoreApplication::translate("MainWindow", "Chile", nullptr));
        FlightTo->setItemText(9, QCoreApplication::translate("MainWindow", "Costa Rica", nullptr));
        FlightTo->setItemText(10, QCoreApplication::translate("MainWindow", "Egypt", nullptr));
        FlightTo->setItemText(11, QCoreApplication::translate("MainWindow", "Estonia", nullptr));
        FlightTo->setItemText(12, QCoreApplication::translate("MainWindow", "Finland", nullptr));
        FlightTo->setItemText(13, QCoreApplication::translate("MainWindow", "France", nullptr));
        FlightTo->setItemText(14, QCoreApplication::translate("MainWindow", "Germany", nullptr));
        FlightTo->setItemText(15, QCoreApplication::translate("MainWindow", "Greece", nullptr));
        FlightTo->setItemText(16, QCoreApplication::translate("MainWindow", "Italy", nullptr));
        FlightTo->setItemText(17, QCoreApplication::translate("MainWindow", "Japan", nullptr));
        FlightTo->setItemText(18, QCoreApplication::translate("MainWindow", "Niger", nullptr));
        FlightTo->setItemText(19, QCoreApplication::translate("MainWindow", "Palestine", nullptr));

        totext->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        TwoWay->setText(QCoreApplication::translate("MainWindow", "Two-way flight", nullptr));
        SearchFlights->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        sorttext->setText(QCoreApplication::translate("MainWindow", "Sort by:", nullptr));
        SortBy->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        SortBy->setItemText(1, QCoreApplication::translate("MainWindow", "Price", nullptr));
        SortBy->setItemText(2, QCoreApplication::translate("MainWindow", "Rating", nullptr));
        SortBy->setItemText(3, QCoreApplication::translate("MainWindow", "Distance", nullptr));

        Tabs->setTabText(Tabs->indexOf(Flights), QCoreApplication::translate("MainWindow", "Flights", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Select country", nullptr));
        HotelCountry->setItemText(0, QCoreApplication::translate("MainWindow", "Argentina", nullptr));
        HotelCountry->setItemText(1, QCoreApplication::translate("MainWindow", "Austria", nullptr));
        HotelCountry->setItemText(2, QCoreApplication::translate("MainWindow", "Bahamas", nullptr));
        HotelCountry->setItemText(3, QCoreApplication::translate("MainWindow", "Bahrain", nullptr));
        HotelCountry->setItemText(4, QCoreApplication::translate("MainWindow", "Belgium", nullptr));
        HotelCountry->setItemText(5, QCoreApplication::translate("MainWindow", "Bolivia", nullptr));
        HotelCountry->setItemText(6, QCoreApplication::translate("MainWindow", "Brazil", nullptr));
        HotelCountry->setItemText(7, QCoreApplication::translate("MainWindow", "Canada", nullptr));
        HotelCountry->setItemText(8, QCoreApplication::translate("MainWindow", "Chile", nullptr));
        HotelCountry->setItemText(9, QCoreApplication::translate("MainWindow", "Costa Rica", nullptr));
        HotelCountry->setItemText(10, QCoreApplication::translate("MainWindow", "Egypt", nullptr));
        HotelCountry->setItemText(11, QCoreApplication::translate("MainWindow", "Estonia", nullptr));
        HotelCountry->setItemText(12, QCoreApplication::translate("MainWindow", "Finland", nullptr));
        HotelCountry->setItemText(13, QCoreApplication::translate("MainWindow", "France", nullptr));
        HotelCountry->setItemText(14, QCoreApplication::translate("MainWindow", "Germany ", nullptr));
        HotelCountry->setItemText(15, QCoreApplication::translate("MainWindow", "Greece", nullptr));
        HotelCountry->setItemText(16, QCoreApplication::translate("MainWindow", "Italy", nullptr));
        HotelCountry->setItemText(17, QCoreApplication::translate("MainWindow", "Japan", nullptr));
        HotelCountry->setItemText(18, QCoreApplication::translate("MainWindow", "Niger", nullptr));
        HotelCountry->setItemText(19, QCoreApplication::translate("MainWindow", "Palestine", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        SearchHotel->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        HotelPersonsNum->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        HotelPersonsNum->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        HotelPersonsNum->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        HotelPersonsNum->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        HotelPersonsNum->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        HotelPersonsNum->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Persons", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        HotelSort->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        HotelSort->setItemText(1, QCoreApplication::translate("MainWindow", "Price", nullptr));
        HotelSort->setItemText(2, QCoreApplication::translate("MainWindow", "Rating", nullptr));

        pool->setText(QCoreApplication::translate("MainWindow", "Pool", nullptr));
        pets->setText(QCoreApplication::translate("MainWindow", "Pets Allowed", nullptr));
        beach->setText(QCoreApplication::translate("MainWindow", "Private beach", nullptr));
        breakfast->setText(QCoreApplication::translate("MainWindow", "Breakfast", nullptr));
        dinner->setText(QCoreApplication::translate("MainWindow", "Dinner", nullptr));
        Tabs->setTabText(Tabs->indexOf(Hotels), QCoreApplication::translate("MainWindow", "Hotels", nullptr));
        CruisePersonsNum->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        CruisePersonsNum->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        CruisePersonsNum->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        CruisePersonsNum->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        CruisePersonsNum->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        CruisePersonsNum->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));

        SearchCruise->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Persons", nullptr));
        pool_2->setText(QCoreApplication::translate("MainWindow", "Pool", nullptr));
        CruiseCountry->setItemText(0, QCoreApplication::translate("MainWindow", "Argentina", nullptr));
        CruiseCountry->setItemText(1, QCoreApplication::translate("MainWindow", "Austria", nullptr));
        CruiseCountry->setItemText(2, QCoreApplication::translate("MainWindow", "Bahamas", nullptr));
        CruiseCountry->setItemText(3, QCoreApplication::translate("MainWindow", "Bahrain", nullptr));
        CruiseCountry->setItemText(4, QCoreApplication::translate("MainWindow", "Belgium", nullptr));
        CruiseCountry->setItemText(5, QCoreApplication::translate("MainWindow", "Bolivia", nullptr));
        CruiseCountry->setItemText(6, QCoreApplication::translate("MainWindow", "Brazil", nullptr));
        CruiseCountry->setItemText(7, QCoreApplication::translate("MainWindow", "Canada", nullptr));
        CruiseCountry->setItemText(8, QCoreApplication::translate("MainWindow", "Chile", nullptr));
        CruiseCountry->setItemText(9, QCoreApplication::translate("MainWindow", "Costa Rica", nullptr));
        CruiseCountry->setItemText(10, QCoreApplication::translate("MainWindow", "Egypt", nullptr));
        CruiseCountry->setItemText(11, QCoreApplication::translate("MainWindow", "Estonia", nullptr));
        CruiseCountry->setItemText(12, QCoreApplication::translate("MainWindow", "Finland", nullptr));
        CruiseCountry->setItemText(13, QCoreApplication::translate("MainWindow", "France", nullptr));
        CruiseCountry->setItemText(14, QCoreApplication::translate("MainWindow", "Germany ", nullptr));
        CruiseCountry->setItemText(15, QCoreApplication::translate("MainWindow", "Greece", nullptr));
        CruiseCountry->setItemText(16, QCoreApplication::translate("MainWindow", "Italy", nullptr));
        CruiseCountry->setItemText(17, QCoreApplication::translate("MainWindow", "Japan", nullptr));
        CruiseCountry->setItemText(18, QCoreApplication::translate("MainWindow", "Niger", nullptr));
        CruiseCountry->setItemText(19, QCoreApplication::translate("MainWindow", "Palestine", nullptr));

        CruiseSort->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        CruiseSort->setItemText(1, QCoreApplication::translate("MainWindow", "Price", nullptr));
        CruiseSort->setItemText(2, QCoreApplication::translate("MainWindow", "Rating", nullptr));

        pets_2->setText(QCoreApplication::translate("MainWindow", "Pets Allowed", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Select country", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        Tabs->setTabText(Tabs->indexOf(Cruises), QCoreApplication::translate("MainWindow", "Cruises", nullptr));
        Speedopointtxt_2->setText(QCoreApplication::translate("MainWindow", "SpeedOPoint", nullptr));
        DetailsBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        PrimaryText->setText(QCoreApplication::translate("MainWindow", "Main title", nullptr));
        DetailInfo1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        PricingInfo->setText(QCoreApplication::translate("MainWindow", "Pricing info", nullptr));
        Features->setText(QCoreApplication::translate("MainWindow", "Features", nullptr));
        SecondaryInfo->setText(QCoreApplication::translate("MainWindow", "Secondary", nullptr));
        SecondaryInfo2->setText(QCoreApplication::translate("MainWindow", "Secondary 2", nullptr));
        Book->setText(QCoreApplication::translate("MainWindow", "Book now", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
