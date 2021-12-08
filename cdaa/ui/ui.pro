QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += \
    c++11 \
    qtc_runnable

SOURCES += \
    contacteditwindow.cpp \
    interactioneditwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    requetewindow.cpp

HEADERS += \
    contacteditwindow.h \
    interactioneditwindow.h \
    mainwindow.h \
    requetewindow.h

FORMS += \
    contacteditwindow.ui \
    interactioneditwindow.ui \
    mainwindow.ui \
    requetewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Libraries.
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logic/debug/ -llogic
else:unix: LIBS += -L$$OUT_PWD/../logic/ -llogic

INCLUDEPATH += \
    $$PWD/../logic

DEPENDPATH += \
    $$PWD/../logic
