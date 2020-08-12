
CONFIG		+= qtopiaapp
CONFIG		-= buildQuicklaunch
DESTDIR	= /opt/FriendlyARM/mini2440/x86-qtopia/yang

TEMPLATE	= app
HEADERS	= yanglabel.h
SOURCES	= yanglabel.cpp
SOURCES+=main.cpp

INTERFACES	= yang.ui

TARGET		= yanglabel


