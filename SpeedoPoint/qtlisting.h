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

class QtListing : public QObject
{
private:
    hotellisting hlisting;
    cruise clisting;
    flightlisting flisting;
    int Ind;
public:
    QListWidgetItem* item;
    QWidget* wid;
    QPushButton *butTest;
    QtListing();
    QtListing(hotellisting inp, int index);
    QtListing(cruise inp, int index);
    QtListing(flightlisting inp, int index);
    QtListing(QWidget* source);
    QListWidgetItem* getitem();
    QWidget *getwidget();

private slots:
    void detailsButton();
};

#endif // QTLISTING_H
