#-------------------------------------------------
#
# Project created by QtCreator 2017-06-12T00:43:10
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
# SerialPort是该模块的基础类，提供了一系列基础的方法和属性来访问串口资源
# SerialPortInfo是一个帮助类。它提供了系统上可用的串口的信息
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YangQingZigbee
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


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
