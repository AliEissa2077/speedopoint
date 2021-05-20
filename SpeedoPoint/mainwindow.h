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
    void deleteListing(int type, int index);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    dataStore progData;
    int sort = 0;
    QtListing* currentListing;

private slots:
    void SwitchLogin();
    void SwitchSignup();
    void Login();
    void Signup();

    void countryChange1(const QString &text, QString type);
    void countryChange2(const QString &text, QString type);
    void countryChangeHotel(const QString &text, QString type);
    void countryChangeCruise(const QString &text, QString type);
    void SortCruises(const QString &text);
    void DisplayFlights();
    void DisplayHotels();
    void DisplayCruises();

    void SortFlights(const QString &text);
    void SortHotels(const QString &text);
    void DetailsBack();

};
#endif // MAINWINDOW_H
