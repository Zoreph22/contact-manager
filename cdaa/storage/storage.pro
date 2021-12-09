QT -= \
    gui

TEMPLATE = lib

DEFINES += \
    STORAGE_LIBRARY

CONFIG += \
    c++11

SOURCES += \
    idao.cpp

HEADERS += \
    storage_global.h \
    idao.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
