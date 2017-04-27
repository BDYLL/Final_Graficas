#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T09:29:05
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rubik_Cube_Solver
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += I/usr/include/   #Change this path for Ubuntu: /usr/local/include
INCLUDEPATH += /usr/include/python2.7/
LIBS += -L/usr/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc -lglut -lGLU -lGL -lGLEW
LIBS += -L/usr/lib -lpython2.7

SOURCES += main.cpp\
        mainwindow.cpp \
    rubikscanner.cpp \
    hsvcolorrange.cpp \
    rubikpreview.cpp \
    solverwindow.cpp \
    main_gl.cpp \
    openglcontext.cpp \
    rubiksolveralgorithms.cpp

HEADERS  += \
    mainwindow.h \
    cvimagewidget.h \
    rubikscanner.h \
    hsvcolorrange.h \
    rubikpreview.h \
    solverwindow.h \
    openglcontext.h \
    constans.h \
    rubiksolveralgorithms.h \
    pyhelper.h

FORMS    += mainwindow.ui \
    solverwindow.ui

DISTFILES += \
    rubiks.py
