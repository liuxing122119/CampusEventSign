QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activityeditview.cpp \
    adminview.cpp \
    client.cpp \
    idatabase.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    sponsorview.cpp \
    studentview.cpp \
    thread.cpp \
    usereditview.cpp

HEADERS += \
    activityeditview.h \
    adminview.h \
    client.h \
    idatabase.h \
    loginview.h \
    masterview.h \
    sponsorview.h \
    studentview.h \
    thread.h \
    usereditview.h

FORMS += \
    activityeditview.ui \
    adminview.ui \
    loginview.ui \
    masterview.ui \
    sponsorview.ui \
    studentview.ui \
    usereditview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
