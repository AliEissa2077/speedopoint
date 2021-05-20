#include "qtlisting.h"
#include "flightlisting.h"
#include "hotellisting.h"
#include "cruise.h"
#include "mainwindow.h"


QtListing::QtListing()
{
    QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel("I love QT!"); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *secondarytxt =  new QLabel("Secondary"); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *tertiarytxt =  new QLabel("Tertiary"); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();
    testbut->setText("Details");
    QHBoxLayout *widgetLayout = new QHBoxLayout();
    widgetLayout->addWidget(widgetText);
    widgetLayout->addSpacerItem(spacer);
    widgetLayout->addWidget(secondarytxt);
    widgetLayout->addSpacerItem(spacer1);
    widgetLayout->addWidget(tertiarytxt);
    widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addSpacerItem(spacer2);

    widgetLayout->addWidget(testbut, Qt::AlignRight);
    widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    temp->setSizeHint(widget->sizeHint());
    item = temp;
    wid = widget;




}

QtListing::QtListing(flightlisting* inp, int index)
{
    Ind = index;
    flisting = inp;
    QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel(QString::fromStdString(inp->getAirline().getName())); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString secondaryt = QString::fromStdString(inp->getDepCountry().getCities()[inp->getDepCityIndex()]  + " " + inp->getDepCountry().getName() + " To " + inp->getArrCountry().getCities()[inp->getArrCityIndex()]  + " " + inp->getArrCountry().getName());

    QLabel *secondarytxt =  new QLabel(secondaryt); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString tertia = QString::fromStdString("Dep time:" + inp->getDepTime() + "Arrival time:" + inp->getArrTime());

    QLabel *tertiarytxt =  new QLabel(tertia); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();
    testbut->setText("Details");

    connect(testbut, SIGNAL(released()), this, SLOT(detailsButton()));

    QHBoxLayout *widgetLayout = new QHBoxLayout();
    widgetLayout->addWidget(widgetText);
    widgetLayout->addSpacerItem(spacer);
    widgetLayout->addWidget(secondarytxt);
    widgetLayout->addSpacerItem(spacer1);
    widgetLayout->addWidget(tertiarytxt);
    widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addSpacerItem(spacer2);

    widgetLayout->addWidget(testbut, Qt::AlignRight);
    widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    temp->setSizeHint(widget->sizeHint());
    item = temp;
    wid = widget;
}

QtListing::QtListing(hotellisting* inp, int index)
{
    Ind = index;
    hlisting = inp;
    QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel(QString::fromStdString(inp->getHotel().getName())); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString secondaryt = QString::fromStdString(inp->getLoc().getCities()[inp->getCityIndex()]  + " " + inp->getLoc().getName() + " Price: " + to_string(inp->getPricePerNight()) + "LE ");

    QLabel *secondarytxt =  new QLabel(secondaryt); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString tertia = QString::fromStdString("Rating:" + to_string(inp->getHotelRating()));

    QLabel *tertiarytxt =  new QLabel(tertia); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();
    testbut->setText("Details");

    connect(testbut, SIGNAL(released()), this, SLOT(detailsButton()));

    QHBoxLayout *widgetLayout = new QHBoxLayout();
    widgetLayout->addWidget(widgetText);
    widgetLayout->addSpacerItem(spacer);
    widgetLayout->addWidget(secondarytxt);
    widgetLayout->addSpacerItem(spacer1);
    widgetLayout->addWidget(tertiarytxt);
    widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addSpacerItem(spacer2);

    widgetLayout->addWidget(testbut, Qt::AlignRight);
    widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    temp->setSizeHint(widget->sizeHint());
    item = temp;
    wid = widget;
}

QtListing::QtListing(cruise* inp, int index)
{
    Ind = index;
    clisting = inp;
    QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel(QString::fromStdString(inp->getCompany().getName())); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString secondaryt = QString::fromStdString(inp->getDepCountry().getCities()[inp->getDepIndex()]  + " " + inp->getDepCountry().getName()  + " To: " + + " Price: " + inp->getArrCountry().getCities()[inp->getArrIndex()]  + " " + inp->getArrCountry().getName() + to_string(inp->getPricePerPerson()) + "LE ");

    QLabel *secondarytxt =  new QLabel(secondaryt); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString tertia = QString::fromStdString("Rating:" + to_string(inp->getCompany().getRating()));

    QLabel *tertiarytxt =  new QLabel(tertia); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();
    testbut->setText("Details");

    connect(testbut, SIGNAL(released()), this, SLOT(detailsButton()));

    QHBoxLayout *widgetLayout = new QHBoxLayout();
    widgetLayout->addWidget(widgetText);
    widgetLayout->addSpacerItem(spacer);
    widgetLayout->addWidget(secondarytxt);
    widgetLayout->addSpacerItem(spacer1);
    widgetLayout->addWidget(tertiarytxt);
    widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addSpacerItem(spacer2);

    widgetLayout->addWidget(testbut, Qt::AlignRight);
    widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    temp->setSizeHint(widget->sizeHint());
    item = temp;
    wid = widget;
}

QtListing::QtListing(QWidget* source)
{
    //frame = new QFrame(source);
    //butTest = new QPushButton(frame);
    //butTest->move(50, 10);
    //butTest->setGeometry(10, 10, 50, 10);


}

void QtListing::detailsButton() {
    //set data to text boxes


    QtListing::findChild<QFrame *>("DetailsPage")->raise();
    if (getType() == 1) {
        QtListing::findChild<QFrame *>("HReserve")->show();
        QtListing::findChild<QFrame *>("HReserve")->raise();
        QtListing::findChild<QFrame *>("FReserve")->hide();
        QtListing::findChild<QFrame *>("CReserve")->hide();
    }
    if (getType() == 2) {
        QtListing::findChild<QFrame *>("FReserve")->show();
        QtListing::findChild<QFrame *>("FReserve")->raise();
        QtListing::findChild<QFrame *>("HReserve")->hide();
        QtListing::findChild<QFrame *>("CReserve")->hide();
        QtListing::findChild<QFrame *>("twoway")->setEnabled(!flisting->isOneW());
    }

    mainProg->SetCurrlisting(this);


}

QListWidgetItem* QtListing::getitem() {
    return item;
}
QWidget* QtListing::getwidget() {
    return wid;
}

void QtListing::setMainProg(MainWindow* m) {
    mainProg = m;
}
int QtListing::getType() {
    if (hlisting != NULL) {
        return 1;
    }
    else if (flisting != NULL) {
        return 2;
    }
    else if (clisting != NULL) {
        return 3;
    }

}
hotellisting* QtListing::getHListing() {
    return hlisting;

}
flightlisting* QtListing::getFListing() {
    return flisting;
}
cruise* QtListing::getCListing() {
    return clisting;
}
int QtListing::getIndex() {
    return Ind;
}
