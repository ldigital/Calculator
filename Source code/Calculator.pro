#-------------------------------------------------
#
# Project created by Leon Harvey 2015-11-07T13:13:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        calculator.cpp \
    calculator_data.cpp

HEADERS  += calculator.h \
    calculator_data.h

FORMS    += calculator.ui
