#include "qtlisting.h"


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

QtListing::QtListing(QWidget* source)
{
    //frame = new QFrame(source);
    //butTest = new QPushButton(frame);
    //butTest->move(50, 10);
    //butTest->setGeometry(10, 10, 50, 10);


}

QListWidgetItem* QtListing::getitem() {
    return item;
}
QWidget* QtListing::getwidget() {
    return wid;
}

