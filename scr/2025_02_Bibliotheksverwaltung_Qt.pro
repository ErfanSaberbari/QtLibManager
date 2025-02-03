QT       += core gui
QT       += core sql
QT       += quick  # Added for QML support
QT       += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++17
CONFIG += c++17 no_qml_debug

SOURCES += \
    book_manager.cpp \
    dbmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlite3.c

HEADERS += \
    book_manager.h \
    dbmanager.h \
    mainwindow.h \
    sqlite3.h

FORMS += \
    mainwindow.ui  # Keep UI file for interchangeability

# LIBS += -lsqlite3

# QML related
QML_IMPORT_PATH += $$PWD/qml
QML_DESIGNER_IMPORT_PATH += $$PWD/qml

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    mainwindow.qml
