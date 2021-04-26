#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>
#include <QWidget>
#include<QPointer>
#include <winsock2.h> // pour les fonctions socket
#include <cstdio> // Pour les Sprintf
#include <QTimer>
#include <QObject>
#include <iostream>


class UiManager : public QObject
{
    Q_OBJECT
public:
    UiManager(QObject *parent = Q_NULL_PTR);
};

#endif // UIMANAGER_H
