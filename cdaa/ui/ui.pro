QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 qtc_runnable

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

RESOURCES += \
    resource.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Libraries.
win32:CONFIG(release, debug|release): \
    LIBS += \
        -L$$OUT_PWD/../logic/release/ -llogic \
        -L$$OUT_PWD/../storage/release/ -lstorage

else:win32:CONFIG(debug, debug|release): \
    LIBS += \
        -L$$OUT_PWD/../logic/debug/ -llogic \
        -L$$OUT_PWD/../storage/debug/ -lstorage

else:unix: \
    LIBS += \
        -L$$OUT_PWD/../logic/ -llogic \
        -L$$OUT_PWD/../storage/ -lstorage

INCLUDEPATH += \
    $$PWD/../logic \
    $$PWD/../storage

DEPENDPATH += \
    $$PWD/../logic \
    $$PWD/../storage
