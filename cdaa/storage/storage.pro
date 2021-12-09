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

# Libraries.
win32:CONFIG(release, debug|release): \
    LIBS += \
        -L$$OUT_PWD/../logic/release/ -llogic

else:win32:CONFIG(debug, debug|release): \
    LIBS += \
        -L$$OUT_PWD/../logic/debug/ -llogic

else:unix: \
    LIBS += \
        -L$$OUT_PWD/../logic/ -llogic

INCLUDEPATH += \
    $$PWD/../logic

DEPENDPATH += \
    $$PWD/../logic
