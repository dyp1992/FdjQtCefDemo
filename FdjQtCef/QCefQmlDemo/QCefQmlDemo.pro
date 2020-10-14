QT += quick

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
# 只关闭打印输出，并不能关闭QML调试器
DEFINES += QT_QML_DEBUG_NO_WARNING
include(../config.pri)

SOURCES += \
        main.cpp

RESOURCES += qml.qrc



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

CONFIG(debug,debug | release){
    TARGET = QCefQmlDemo_d
    LIBS += -L"$$THIRD_PATH/cef/Debug" -llibcef -llibcef_dll_wrapper
}else{
    TARGET = QCefQmlDemo_r
    LIBS += -L"$$THIRD_PATH/cef/Release" -llibcef -llibcef_dll_wrapper
}

DISTFILES +=
