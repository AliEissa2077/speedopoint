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
    widgetLayout->addStretch();
    widgetLayout->addWidget(testbut, Qt::AlignRight);
    //widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    //temp->setSizeHint(widget->sizeHint());
    item = temp;
    wid = widget;




}

QtListing::QtListing(flightlisting* inp, int index)
{
    Ind = index;
    flisting = inp;
    //QListWidgetItem* temp = new QListWidgetItem();
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
    widgetLayout->addStretch();
    widgetLayout->addWidget(testbut, Qt::AlignRight);
    //widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    //temp->setSizeHint(widget->sizeHint());
    //item = temp;
    wid = widget;
}

QtListing::QtListing(hotellisting* inp, int index)
{
    Ind = index;
    hlisting = inp;
    //QListWidgetItem* temp = new QListWidgetItem();
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

    QtListing::connect(testbut, SIGNAL(released()), this, SLOT(detailsButton()));

    QHBoxLayout *widgetLayout = new QHBoxLayout();
    widgetLayout->addWidget(widgetText);
    widgetLayout->addSpacerItem(spacer);
    widgetLayout->addWidget(secondarytxt);
    widgetLayout->addSpacerItem(spacer1);
    widgetLayout->addWidget(tertiarytxt);
    widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addStretch();
    widgetLayout->addWidget(testbut, Qt::AlignRight);

    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetFixedSize);
    widget->setLayout(widgetLayout);
    //temp->setSizeHint(widget->sizeHint());
    //item = temp;
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
    QString primary;
    QString secondary;
    QString location;
    QString details;
    QString pricing;
    if (getType() == 1) {
        primary = QString::fromStdString(hlisting->getHotel().getName());
        location = QString::fromStdString(hlisting->getHotel().getCountry().getCities()[hlisting->getHotel().getIndex()] + ", " + hlisting->getHotel().getCountry().getName());
        secondary = "Area: " + QString::number(hlisting->getArea()) + "Meters Square";
        pricing = QString::number(hlisting->getPricePerNight()) + " LE Per Night";
        details = "Pool: ";
        details += hlisting->getHotel().getPool() ? "yes" : "no";
        details += '\n';
        details += "Beach: ";
        details += hlisting->getHotel().getBeach() ? "yes" : "no";
        details += '\n';
        details += "Pets Allowed: ";
        details += hlisting->getPets() ? "yes" : "no";
        details += '\n';
        details += "Breakfast: ";
        details += hlisting->getBfast() ? "yes" : "no";
        details += '\n';
        details += "Dinner: ";
        details += hlisting->getDinner() ? "yes" : "no";
        details += '\n';
        details += "Max Persons: ";
        details += QString::number(hlisting->getMaxPersons());
        details += '\n';
    }
    if (getType() == 2) {
        primary = QString::fromStdString(flisting->getAirline().getName());
        location = QString::fromStdString(flisting->getDepCountry().getCities()[flisting->getDepCityIndex()] + ", " + flisting->getArrCountry().getName() + " To " + flisting->getArrCountry().getCities()[flisting->getArrCityIndex()] + ", " + flisting->getArrCountry().getName());
        secondary = QString::fromStdString("Time: " + flisting->getDepTime());
        pricing = QString::number(flisting->getPriceperTraveller()) + " LE Per Traveller";
        details = "Rating: " + QString::number(flisting->getAirlineRating());
    }
    if (getType() == 3) {
        primary = QString::fromStdString(clisting->getCompany().getName());
        location = QString::fromStdString(clisting->getDepCountry().getCities()[clisting->getDepIndex()] + ", " + clisting->getDepCountry().getName() + " To " + clisting->getArrCountry().getCities()[clisting->getArrIndex()] + ", " + clisting->getArrCountry().getName());
        secondary = "Duration: " + QString::number(clisting->getDuration()) + " Days";
        pricing = QString::number(clisting->getPricePerPerson()) + " LE Per Traveller";
        details = "Rating: " + QString::number(clisting->getCompany().getRating());
        details += '\n';
        details += "Safety Rating: " + QString::number(clisting->getCompany().getSafety());
    }
    mainProg->findChild<QLabel *>("PrimaryText")->setText(primary);
    mainProg->findChild<QLabel *>("DetailInfo1")->setText(location);
    mainProg->findChild<QLabel *>("SecondaryInfo")->setText(secondary);
    mainProg->findChild<QLabel *>("PricingInfo")->setText(pricing);
    mainProg->findChild<QLabel *>("Features")->setText(details);

    mainProg->updateWallet();
    mainProg->findChild<QFrame *>("DetailsPage")->raise();

    if (getType() == 1) {
        qDebug() << "yesy";
        mainProg->findChild<QFrame *>("HReserve")->show();
        mainProg->findChild<QFrame *>("HReserve")->raise();
        mainProg->findChild<QFrame *>("FReserve")->hide();
        mainProg->findChild<QFrame *>("CReserve")->hide();
    }
    else if (getType() == 2) {
        mainProg->findChild<QFrame *>("FReserve")->show();
        mainProg->findChild<QFrame *>("FReserve")->raise();
        mainProg->findChild<QFrame *>("HReserve")->hide();
        mainProg->findChild<QFrame *>("CReserve")->hide();
        mainProg->findChild<QFrame *>("twoway")->setEnabled(!flisting->isOneW());
    }
    else if (getType() == 3) {
        mainProg->findChild<QFrame *>("CReserve")->show();
        mainProg->findChild<QFrame *>("CReserve")->raise();
        mainProg->findChild<QFrame *>("HReserve")->hide();
        mainProg->findChild<QFrame *>("FReserve")->hide();
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
        qDebug() << "yesy";
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
QtListing::~QtListing() {
    delete flisting;
    delete clisting;
    delete mainProg;
    delete hlisting;

}
void QtListing::setnull() {
    wid = NULL;
}
