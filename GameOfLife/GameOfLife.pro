TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += \
        main.cpp \
    grid.cpp \
    anime.cpp

HEADERS += \
    grid.h \
    anime.h \
    const.h \
    note.h

#CONFIG += c++11

#SOURCES += \
#        main.cpp \
#        mainwindow.cpp

#HEADERS += \
#        mainwindow.h

#FORMS += \
#        mainwindow.ui

LIBS += -L"/Users/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH =+ "/Users/local/include"
DEPENDPATH += "/Users/local/include"
