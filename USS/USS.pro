#-------------------------------------------------
#
# Project created by QtCreator 2023-05-31T18:40:28
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = USS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    userwindow.cpp \
    adminwindow.cpp \
    admin_umbrella.cpp \
    admin_umbrella_add.cpp \
    admin_umbrella_dele.cpp \
    admin_user.cpp \
    admin_user_add.cpp \
    admin_user_dele.cpp \
    admin_place.cpp \
    admin_place_add.cpp \
    admin_place_dele.cpp \
    register.cpp \
    user_borrow.cpp \
    user_return.cpp \
    admin_orders.cpp \
    admin_orders_add.cpp \
    admin_orders_dele.cpp

HEADERS += \
        mainwindow.h \
    userwindow.h \
    adminwindow.h \
    admin_umbrella.h \
    admin_umbrella_add.h \
    admin_umbrella_dele.h \
    admin_user.h \
    admin_user_add.h \
    admin_user_dele.h \
    admin_place.h \
    admin_place_add.h \
    admin_place_dele.h \
    register.h \
    user_borrow.h \
    user_return.h \
    admin_orders.h \
    admin_orders_add.h \
    admin_orders_dele.h

FORMS += \
        mainwindow.ui \
    userwindow.ui \
    adminwindow.ui \
    admin_umbrella.ui \
    admin_umbrella_add.ui \
    admin_umbrella_dele.ui \
    admin_user.ui \
    admin_user_add.ui \
    admin_user_dele.ui \
    admin_place.ui \
    admin_place_add.ui \
    admin_place_dele.ui \
    register.ui \
    user_borrow.ui \
    user_return.ui \
    admin_orders.ui \
    admin_orders_add.ui \
    admin_orders_dele.ui
