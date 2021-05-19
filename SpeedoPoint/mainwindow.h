#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    user* mainUser;


private slots:
    void SwitchLogin();
    void SwitchSignup();
    void Login();
    void Signup();

    void countryChange1(const QString &text);

};
#endif // MAINWINDOW_H
