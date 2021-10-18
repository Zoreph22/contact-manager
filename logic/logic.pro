TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        appmodel.cpp \
        contactcollection.cpp \
        contactmodel.cpp \
        date.cpp \
        interactioncollection.cpp \
        interactionmodel.cpp \
        main.cpp \
        todocollection.cpp \
        todomodel.cpp

HEADERS += \
    appmodel.h \
    contactcollection.h \
    contactmodel.h \
    date.h \
    interactioncollection.h \
    interactionmodel.h \
    todocollection.h \
    todomodel.h
