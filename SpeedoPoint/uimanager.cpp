#include "uimanager.h"
#include <QPushButton>

UiManager::UiManager(QObject *parent = Q_NULL_PTR)  : QObject(parent)
{

    QPushButton *test;
    QObject::connect(test, SIGNAL(clicked()), &QPushButton::clicked, SLOT(insert()));

}
