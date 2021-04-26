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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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

        LoginFrame->raise();
        LoginBackground->raise();
        SignUpFrame->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1098, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

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
        Signuplabel->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        UsernameLabel->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        emailLabel->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        PassLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        SignupButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        SignupSwitch->setText(QCoreApplication::translate("MainWindow", "Already have an account? Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
