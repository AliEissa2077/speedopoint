#ifndef QTLISTING_H
#define QTLISTING_H
#include <QFrame>
#include <QPushButton>
#include <QListWidgetItem>
#include <QSize>
#include <QLabel>
#include <QHBoxLayout>
#include <QLayout>

class QtListing
{
public:
    QListWidgetItem* item;
    QWidget* wid;
    QPushButton *butTest;
    QtListing();
    QtListing(QWidget* source);
    QListWidgetItem* getitem();
    QWidget *getwidget();
};

#endif // QTLISTING_H