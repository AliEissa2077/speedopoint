#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *test = MainWindow::findChild<QPushButton *>("LoginSwitch");
    QPushButton *test2 = MainWindow::findChild<QPushButton *>("SignupSwitch");
    connect(test, SIGNAL(released()), this, SLOT(SwitchSignup()));
    connect(test2, SIGNAL(released()), this, SLOT(SwitchLogin()));

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

MainWindow::~MainWindow()
{
    delete ui;
}

