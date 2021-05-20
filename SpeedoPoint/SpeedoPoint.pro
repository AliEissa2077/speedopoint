QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airline.cpp \
    airport.cpp \
    country.cpp \
    cruise.cpp \
    cruiseReservation.cpp \
    datastore.cpp \
    date.cpp \
    filesystem.cpp \
    flightlisting.cpp \
    flightticket.cpp \
    hotel.cpp \
    hotellisting.cpp \
    main.cpp \
    mainwindow.cpp \
    payment.cpp \
    qtlisting.cpp \
    reservation.cpp \
    stop.cpp \
    user.cpp \
    wallet.cpp

HEADERS += \
    airline.h \
    airport.h \
    country.h \
    cruise.h \
    cruisecompany.h \
    cruisereservation.h \
    datastore.h \
    date.h \
    filesystem.h \
    flightlisting.h \
    flightticket.h \
    hotel.h \
    hotellisting.h \
    mainwindow.h \
    payment.h \
    qtlisting.h \
    reservation.h \
    stop.h \
    user.h \
    wallet.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    SpeedoPoint.pro.user
