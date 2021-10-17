TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        appmodel.cpp \
        date.cpp \
        fichemodel.cpp \
        interactioncollection.cpp \
        interactionmodel.cpp \
        main.cpp \
        requetefiche.cpp \
        todomodel.cpp

HEADERS += \
    appmodel.h \
    date.h \
    fichemodel.h \
    interactioncollection.h \
    interactionmodel.h \
    requete.h \
    requete_impl.h \
    requetefiche.h \
    todomodel.h
