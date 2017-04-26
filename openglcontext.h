#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class OpenGLContext : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLContext(QWidget *parent = 0);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:

private:
    void glutTexturedCubeBase(GLdouble size, GLfloat* color1, GLfloat* color2, GLfloat* color3,
                                            GLfloat* color4,GLfloat* color5, GLfloat* color6);
    void glutTexturedCube1(GLdouble size);
    void glutTexturedCube2(GLdouble size);
    void glutTexturedCube3(GLdouble size);
    void glutTexturedCube4(GLdouble size);
    void glutTexturedCube5(GLdouble size);
    void glutTexturedCube6(GLdouble size);
    void glutTexturedCube7(GLdouble size);
    void glutTexturedCube8(GLdouble size);
    void glutTexturedCube9(GLdouble size);
    void glutTexturedCube10(GLdouble size);
    void glutTexturedCube11(GLdouble size);
    void glutTexturedCube12(GLdouble size);
    void glutTexturedCube13(GLdouble size);
    void glutTexturedCube14(GLdouble size);
    void glutTexturedCube15(GLdouble size);
    void glutTexturedCube16(GLdouble size);
    void glutTexturedCube17(GLdouble size);
    void glutTexturedCube18(GLdouble size);
    void glutTexturedCube19(GLdouble size);
    void glutTexturedCube20(GLdouble size);
    void glutTexturedCube21(GLdouble size);
    void glutTexturedCube22(GLdouble size);
    void glutTexturedCube23(GLdouble size);
    void glutTexturedCube24(GLdouble size);
    void glutTexturedCube25(GLdouble size);
    void glutTexturedCube26(GLdouble size);
    void glutTexturedCube27(GLdouble size);
    void rotateRight(bool clockWise);
    void geomCoordSys(GLfloat size);
    void drawCurrentCube(int indexCube);
    void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );



private:
    // Tamaño de la ventana
    GLint width = 800;
    GLint height = 600;

    // Parámetros de la cámara virtual
    GLint mouseButton = 0;
    GLboolean mouseRotate = false;
    GLboolean mouseZoom = false;
    GLboolean mousePan = false;
    GLint xClick = 0;
    GLint yClick = 0;
    GLint xAux = 0;
    GLint yAux = 0;
    GLfloat rotX = 0.f;
    GLfloat rotY = 0.f;
    GLfloat panX = -2.f;
    GLfloat panY = -3.f;
    GLfloat zoomZ = -55.f;

    GLfloat rot = 0.;
    float spaceBetweenCubes = 2.1f;


    vector<int> idOfCubes;

    /*
    GLfloat colorRed[]    = {255,	0,	0};
    GLfloat colorGreen[]  = {  0,255,  0};
    GLfloat colorBlue[]   = {	0,	0,255};
    GLfloat colorOrange[] = {255,127, 39};
    GLfloat colorYellow[] = {255,255,	0};
    GLfloat colorWhite[]  = {255,255,255};
    GLfloat colorBlack[]  = {  0,	0,	0};
    */
};

#endif // OPENGLCONTEXT_H
