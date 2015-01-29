TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vec4.cpp \
    mat4.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../mat4.h \
    ../../vec4.h \
    vec4.h \
    mat4.h

