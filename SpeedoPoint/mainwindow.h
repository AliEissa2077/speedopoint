#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datastore.h"
#include "qtlisting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void SetCurrlisting(QtListing* l);
    void deleteListing();
    void updateWallet();
    int getSort() {return sort;}
    void updateUserP();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    dataStore* progData;
    vector<QtListing *> listings;
    vector<QtListing *> madereservs;
    int sort = 0;
    QtListing* currentListing;
    user* curUser;

private slots:
    void SwitchLogin();
    void SwitchSignup();
    void Login();
    void Signup();

    void countryChange1(const QString &text);
    void countryChange2(const QString &text);
    void countryChangeHotel(const QString &text);
    void countryChangeCruise(const QString &text);
    void SortCruises(const QString &text);
    void DisplayFlights();
    void DisplayHotels();
    void DisplayCruises();

    void SortFlights(const QString &text);
    void SortHotels(const QString &text);
    void DetailsBack();

    void bookListing();

    void DepositAcc();
    void UserBack();
    void UserOpen();
    void updateInfo();

};
#endif // MAINWINDOW_H
