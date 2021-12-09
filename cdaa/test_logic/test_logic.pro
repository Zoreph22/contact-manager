TEMPLATE = app

CONFIG += \
    console c++11

CONFIG -= \
    app_bundle

CONFIG -= \
    qt

SOURCES += \
    main.cpp \
    unit_tests.cpp

HEADERS += \
    unit_tests.h

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
