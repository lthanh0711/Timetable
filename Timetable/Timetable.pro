QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CSV.cpp \
    Subjects.cpp \
    displaymodel.cpp \
    main.cpp \
    mainwindow.cpp \
    searchui.cpp \
    timetable.cpp \
    tkb.cpp

HEADERS += \
    CSV.h \
    CustomDataTypes.h \
    displaymodel.h \
    mainwindow.h \
    searchui.h \
    tkb.h

FORMS += \
    mainwindow.ui \
    searchui.ui \
    tkb.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Raw - Copy.csv \
    ../build-Timetable-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/Raw - Copy.csv \

RESOURCES += \
    Data.qrc

INCLUDEPATH += .
