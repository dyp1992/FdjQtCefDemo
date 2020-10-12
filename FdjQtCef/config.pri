BASE_PATH = $$PWD
THIRD_PATH = $$PWD/ThirdParty

win32{
    CONFIG(debug, debug|release){
        BIN_PATH = $$PWD/bin-debug
    }else{
        BIN_PATH = $$PWD/bin-release
    }

    QMAKE_LFLAGS_RELEASE += /MAP
    QMAKE_CFLAGS_RELEASE += /Zi
    QMAKE_LFLAGS_RELEASE += /debug /opt:ref

}else{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.12
    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/}


DESTDIR = $$BIN_PATH
