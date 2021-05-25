#ifndef QTLISTING_H
#define QTLISTING_H
#include <QFrame>
#include <QPushButton>
#include <QListWidgetItem>
#include <QSize>
#include <QLabel>
#include <QHBoxLayout>
#include <QLayout>
#include "flightlisting.h"
#include "hotellisting.h"
#include "cruise.h"

class MainWindow;

class QtListing : public QObject
{
    Q_OBJECT
private:
    MainWindow* mainProg;
    hotellisting* hlisting;
    cruise* clisting;
    flightlisting* flisting;
    QWidget* invoice;

    reservation* hreserv;
    cruisereservation* creserv;
    flightticket* freserv;

    int Ind;
public:
    QListWidgetItem* item;
    QWidget* wid;

    QPushButton *butTest;
    QtListing();
    QtListing(hotellisting* inp, int index);
    QtListing(cruise* inp, int index);
    QtListing(flightlisting* inp, int index);
    QtListing(QWidget* source);
    QListWidgetItem* getitem();
    QWidget *getwidget();
    hotellisting* getHListing();
    flightlisting* getFListing();
    cruise* getCListing();
    void setReserv(reservation* x);
    void setReserv(flightticket* x);
    void setReserv(cruisereservation* x);

    void setMainProg(MainWindow* m);
    int getIndex();
    int getType();
    void setnull();
    ~QtListing();

private slots:
    void detailsButton();
    void reservationDetails();
    void cancelReservation();
};

#endif // QTLISTING_H
