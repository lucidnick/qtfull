TARGET = view_rotation  
TEMPLATE = app  
  
HEADERS += \  
     
  
SOURCES += \  
    main.cpp \  
    
  
QT       += core gui  
  
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  
#fix no GL/glut.h
#https://stackoverflow.com/questions/8892251/undefined-reference-to-symbol-glulookat
#include <GL/freeglut.h>
LIBS += -lglut -lGL -lGLU
LIBS += -L/usr/local/include/
QT       += opengl


