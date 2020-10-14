QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS
include(../config.pri)

INCLUDEPATH += $$THIRD_PATH/cef

CONFIG(debug,debug | release){
    TARGET = QCefDemo_d
    LIBS += -L"$$THIRD_PATH/cef/Debug" -llibcef -llibcef_dll_wrapper
}else{
    TARGET = QCefDemo_r
    LIBS += -L"$$THIRD_PATH/cef/Release" -llibcef -llibcef_dll_wrapper
}

LIBS += shell32.lib \
        kernel32.lib \
        user32.lib \
        ole32.lib \
        oleaut32.lib \
        gdi32.lib

SOURCES += \
    client_app_other.cpp \
    client_app_renderer.cpp \
    client_v8handler.cpp \
    main.cpp \
    simple_app.cc \
    simple_handler.cc \
    widget.cpp

HEADERS += \
    client_app_other.h \
    client_app_renderer.h \
    client_v8handler.h \
    simple_app.h \
    simple_handler.h \
    widget.h

FORMS += \
    widget.ui

DISTFILES +=

RESOURCES += \
    rc.qrc

