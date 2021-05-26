#include "qtlisting.h"
#include "flightlisting.h"
#include "hotellisting.h"
#include "cruise.h"
#include "mainwindow.h"
#include <QMessageBox>
#include  <QtDebug>
#include <QInputDialog>


QtListing::QtListing()
{

}

QtListing::QtListing(flightlisting* inp, int index)
{
    Ind = index;
    flisting = inp;
    hlisting = NULL;
    clisting = NULL;
    //QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel(QString::fromStdString(inp->getAirline()->getName())); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString secondaryt = "Price: " + QString::number(inp->getPriceperTraveller()) + " LE";

    QLabel *secondarytxt =  new QLabel(secondaryt); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString tertia = QString::fromStdString("Dep time:" + inp->getDepTime() + "Arrival time:" + inp->getArrTime());

    QLabel *tertiarytxt =  new QLabel(tertia); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();
    testbut->setText("Details");
    testbut->setMaximumWidth(80);

    connect(testbut, SIGNAL(released()), this, SLOT(detailsButton()));

    QHBoxLayout *widgetLayout = new QHBoxLayout();
    widgetLayout->addWidget(widgetText);
    widgetLayout->addSpacerItem(spacer);
    widgetLayout->addWidget(secondarytxt);
    widgetLayout->addSpacerItem(spacer1);
    widgetLayout->addWidget(tertiarytxt);
    widgetLayout->addSpacerItem(spacer2);
    //widgetLayout->addSpacerItem(spacer2);
    widgetLayout->addStretch();
    widgetLayout->addWidget(testbut, Qt::AlignRight);
    //widgetLayout->addStretch();
    //widgetLayout->addStretch();
    widgetLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    widget->setLayout(widgetLayout);
    //temp->setSizeHint(widget->sizeHint());
    //item = temp;
    wid = widget;
}

QtListing::QtListing(hotellisting* inp, int index)
{
    Ind = index;
    hlisting = inp;
    clisting = NULL;
    flisting = NULL;
    //QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel(QString::fromStdString(inp->getHotel()->getName())); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString secondaryt = QString::fromStdString(inp->getLoc().getCities()[inp->getCityIndex()]  + " " + inp->getLoc().getName() + " Price: " + to_string(inp->getPricePerNight()) + "LE ");

    QLabel *secondarytxt =  new QLabel(secondaryt); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString tertia = QString::fromStdString("Rating:" + to_string(inp->getHotelRating()));

    QLabel *tertiarytxt =  new QLabel(tertia); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();

    testbut->setText("Details");
    testbut->setMaximumWidth(80);

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
    widgetLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    widget->setLayout(widgetLayout);
    //temp->setSizeHint(widget->sizeHint());
    //item = temp;
    wid = widget;
}

QtListing::QtListing(cruise* inp, int index)
{
    Ind = index;
    clisting = inp;
    hlisting = NULL;
    flisting = NULL;
    QListWidgetItem* temp = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QLabel *widgetText =  new QLabel(QString::fromStdString(inp->getCompany()->getName())); // primary text
    QSpacerItem *spacer = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString secondaryt = QString::fromStdString(inp->getDepCountry().getCities()[inp->getDepIndex()]  + " " + inp->getDepCountry().getName()  + " To: " + + " Price: " + inp->getArrCountry().getCities()[inp->getArrIndex()]  + " " + inp->getArrCountry().getName() + to_string(inp->getPricePerPerson()) + "LE ");

    QLabel *secondarytxt =  new QLabel(secondaryt); // secondary text info
    QSpacerItem *spacer1 = new QSpacerItem(20,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString tertia = QString::fromStdString("Rating:" + to_string(inp->getCompany()->getRating()));

    QLabel *tertiarytxt =  new QLabel(tertia); // tertiary text info
    QSpacerItem *spacer2 = new QSpacerItem(140,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *testbut = new QPushButton();
    testbut->setText("Details");
    testbut->setMaximumWidth(80);

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
    qDebug() << "here!";
    qDebug() << getType();
    QString primary;
    QString secondary;
    QString location;
    QString details;
    QString pricing;

    if (getType() == 1) {
        primary = QString::fromStdString(hlisting->getHotel()->getName());
        location = QString::fromStdString(hlisting->getHotel()->getCountry().getCities()[hlisting->getHotel()->getIndex()] + ", " + hlisting->getHotel()->getCountry().getName());
        secondary = "Area: " + QString::number(hlisting->getArea()) + "Meters Square";
        pricing = QString::number(hlisting->getPricePerNight()) + " LE Per Night";
        details = "Pool: ";
        details += hlisting->getHotel()->getPool() ? "yes" : "no";
        details += '\n';
        details += "Beach: ";
        details += hlisting->getHotel()->getBeach() ? "yes" : "no";
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
        primary = QString::fromStdString(flisting->getAirline()->getName());
        location = QString::fromStdString(flisting->getDepCountry().getCities()[flisting->getDepCityIndex()] + ", " + flisting->getArrCountry().getName() + " To " + flisting->getArrCountry().getCities()[flisting->getArrCityIndex()] + ", " + flisting->getArrCountry().getName());
        secondary = QString::fromStdString("Time: " + flisting->getDepTime());
        pricing = QString::number(flisting->getPriceperTraveller()) + " LE Per Traveller";
        details = "Rating: " + QString::number(flisting->getAirlineRating());
        qDebug() << " info set";
    }
    if (getType() == 3) {
        primary = QString::fromStdString(clisting->getCompany()->getName());
        location = QString::fromStdString(clisting->getDepCountry().getCities()[clisting->getDepIndex()] + ", " + clisting->getDepCountry().getName() + " To " + clisting->getArrCountry().getCities()[clisting->getArrIndex()] + ", " + clisting->getArrCountry().getName());
        secondary = "Duration: " + QString::number(clisting->getDuration()) + " Days";
        pricing = QString::number(clisting->getPricePerPerson()) + " LE Per Traveller";
        details = "Rating: " + QString::number(clisting->getCompany()->getRating());
        details += '\n';
        details += "Safety Rating: " + QString::number(clisting->getCompany()->getSafety());
    }
    mainProg->findChild<QLabel *>("PrimaryText")->setText(primary);
    mainProg->findChild<QLabel *>("DetailInfo1")->setText(location);
    mainProg->findChild<QLabel *>("SecondaryInfo")->setText(secondary);
    mainProg->findChild<QLabel *>("PricingInfo")->setText(pricing);
    mainProg->findChild<QLabel *>("Features")->setText(details);

    mainProg->updateWallet();
    mainProg->findChild<QFrame *>("DetailsPage")->raise();

    if (getType() == 1) {

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

    qDebug() <<"done";
}
void QtListing::setReserv(reservation* x) {
    hreserv = x;
}
void QtListing::setReserv(flightticket* x) {
    freserv = x;
}
void QtListing::setReserv(cruisereservation* x) {
    creserv = x;
}
void QtListing::reservationDetails() {
    QWidget* confirm = new QWidget();
    QLabel* type = new QLabel;
    QLabel* payed = new QLabel;
    QLabel* adults = new QLabel;
    QLabel* childs = new QLabel;
    QLabel* dat = new QLabel;

    if (getType() == 1) {
        type->setText("Hotel Reservation");
        payed->setText("For: " + QString::number(hreserv->getPaymentVal()) + " LE");
        string temp = to_string(hreserv->getDate().getDay()) + "/" + to_string(hreserv->getDate().getMonth()) + "/" + to_string(hreserv->getDate().getYear());
        dat->setText("Staring Date: " + QString::fromStdString(temp));
        adults->setText("Adults: " + QString::number(hreserv->getAdults()));
        childs->setText("Children: " + QString::number(hreserv->getChildren()));
        rated = hreserv->rated;
    }
    if (getType() == 2) {
        type->setText("Flight Ticket");

        payed->setText("For: " + QString::number(freserv->getPaymentVal()) + " LE");
        string temp = to_string(freserv->getDate().getDay()) + "/" + to_string(freserv->getDate().getMonth()) + "/" + to_string(freserv->getDate().getYear());
        dat->setText("Departure Date: " + QString::fromStdString(temp));
        adults->setText("Adults: " + QString::number(freserv->getAdults()));
        childs->setText("Children: " + QString::number(freserv->getChildren()));


        rated = freserv->rated;
    }
    if (getType() == 3) {
        type->setText("Cruise Reservation");

        payed->setText("For: " + QString::number(creserv->getPaymentValue()) + " LE");
        string temp = to_string(creserv->getDate().getDay()) + "/" + to_string(creserv->getDate().getMonth()) + "/" + to_string(creserv->getDate().getYear());
        dat->setText("Departure Date: " + QString::fromStdString(temp));
        adults->setText("Adults: " + QString::number(creserv->getAdults()));
        childs->setText("Children: " + QString::number(creserv->getChildren()));

        rated = creserv->rated;
    }
    QPushButton* cancelRes = new QPushButton("Cancel Reservation");
    QPushButton* giveRating = new QPushButton("Give Rating");
    QVBoxLayout* widLayout = new QVBoxLayout;

    if (rated) {
        giveRating->setEnabled(false);

    }
    qDebug() << "yes";
    connect(giveRating, SIGNAL(released()), this, SLOT(rateReservation()));
    connect(cancelRes, SIGNAL(released()), this, SLOT(cancelReservation()));

    widLayout->addWidget(type);
    widLayout->addWidget(payed);
    widLayout->addWidget(dat);
    widLayout->addWidget(adults);
    widLayout->addWidget(childs);
    widLayout->addStretch();
    widLayout->addWidget(giveRating);
    widLayout->addWidget(cancelRes);
    widLayout->setSizeConstraint(QLayout::SetFixedSize);
    confirm->setLayout(widLayout);
    invoice = confirm;
    confirm->show();

}
void QtListing::cancelReservation() {

    QMessageBox* confirm = new QMessageBox(0);
    QMessageBox::StandardButton reply1;
    //confirm->exec();
    QString s1 = "Are you sure you want to cancel your reservation?";
    if (!hreserv->getListing()->getRefundable()) {
        s1 += " It is not refundable.";
    }
    reply1 = QMessageBox::question(confirm, "Cancel?", s1,
        QMessageBox::Yes | QMessageBox::No);
    if (reply1 == QMessageBox::No) {
        return;
    }


    if (getType() == 1) {
        if (hreserv->getListing()->getRefundable()) {
            hreserv->getUser()->getWallet()->deposit(hreserv->getPaymentVal());
        }
        vector<reservation*>* reservs = hreserv->getUser()->getReservations();
        for(int i = 0; i < reservs->size(); i++) {
            if (reservs[0][i] == hreserv) {
                mainProg->updateUserP();
                reservs->erase(reservs->begin() + i);
                delete hreserv;
                hreserv = NULL;
                delete invoice;
                //invoice->close();
                invoice = NULL;
                qDebug() << "reserv cancel";

                return;
            }
        }
    }
    if (getType() == 2) {
        if (freserv->getListing()->isRefundable()) {
            freserv->getUser()->getWallet()->deposit(freserv->getPaymentVal());
        }
        vector<flightticket*>* reservs = freserv->getUser()->getTickets();
        for(int i = 0; i < reservs->size(); i++) {
            if (reservs[0][i] == freserv) {
                mainProg->updateUserP();
                reservs->erase(reservs->begin() + i);
                delete freserv;
                freserv = NULL;
                delete invoice;
                //invoice->close();
                invoice = NULL;
                qDebug() << "reserv cancel";

                return;
            }
        }
    }
    if (getType() == 3) {
        if (creserv->getListing()->isRefundable()) {
            creserv->getUser()->getWallet()->deposit(creserv->getPaymentValue());
        }
        vector<cruisereservation*>* reservs = creserv->getUser()->getCruisereservations();
        for(int i = 0; i < reservs->size(); i++) {
            if (reservs[0][i] == creserv) {
                mainProg->updateUserP();
                reservs->erase(reservs->begin() + i);
                delete creserv;
                creserv = NULL;
                delete invoice;
                //invoice->close();
                invoice = NULL;
                qDebug() << "reserv cancel";

                return;
            }
        }
    }

}
void QtListing::rateReservation() {
    bool ok;
    QString text = QInputDialog::getText(mainProg, tr("Rate"), tr("Rating:(x/5)"), QLineEdit::Normal, "5", &ok);
    if (ok && !text.isEmpty()) {
        float v = text.toFloat();
        if (v > 5) {
            v = 5;
        }
        if (getType() == 1) {
            hlisting->getHotel()->updateRating(v);
            hreserv->rated = true;
        }
        if (getType() == 2) {
            flisting->getAirline()->updateRating(v);
            freserv->rated = true;
        }
        if (getType() == 3) {
            clisting->getCompany()->updateRating(v);
            creserv->rated = true;
        }
        invoice->close();
    }


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
QtListing::~QtListing() {
    delete flisting;
    delete clisting;
    delete mainProg;
    delete hlisting;

}
void QtListing::setnull() {
    wid = NULL;
}
