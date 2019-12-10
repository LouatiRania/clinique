#-------------------------------------------------
#
# Project created by QtCreator 2019-11-25T13:18:02
#
#-------------------------------------------------

QT       += core gui sql
QT       += network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ProjetQt
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS



# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    convention.cpp \
    rania.cpp \
    anarad.cpp \
    connexion.cpp \
    equip_affecte_.cpp \
    equipement_para.cpp \
    gerermed.cpp \
    main.cpp \
    medicament.cpp \
    qcustomplot.cpp \
    rdvsa.cpp \
    rsar.cpp \
    smtp.cpp \
    reservation.cpp \
    mainwindow.cpp \
    ordo.cpp \
    sarra.cpp

HEADERS += \
    connexion.h \
    convention.h \
    rania.h \
    anarad.h \
    connexion.h \
    equip_affecte_.h \
    equipement_para.h \
    gerermed.h \
    medicament.h \
    qcustomplot.h \
    rdvsa.h \
    rsar.h \
    smtp.h \
    reservation.h \
    mainwindow.h \
    ordo.h \
    sarra.h

FORMS += \
    rania.ui \
    anarad.ui \
    gerermed.ui \
    modifier.ui \
    rdvsa.ui \
    mainwindow.ui \
    sarra.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Perstfic.qss
