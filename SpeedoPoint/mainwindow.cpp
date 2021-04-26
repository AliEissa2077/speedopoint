#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QtDebug>

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

    // add info to database file
    // declare user

}

MainWindow::~MainWindow()
{
    delete ui;
}

