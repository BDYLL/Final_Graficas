#include "openglcontext.h"
#include <iostream>
#include <cmath>

#include <vector>
#include "Cubo.h"

using namespace std;

OpenGLContext::OpenGLContext(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->idOfCubes  = {1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 11, 12, 13, 14, 15, 16, 17, 18,
            19, 20, 21, 22, 23, 24, 25, 26, 27};

}

void OpenGLContext::initializeGL(){
    //rubikCube.resize(27);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glColor3f(1.f, 1.f, 1.f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);

    GLfloat colorRed[]    = {1.0,   0,   0 };
    GLfloat colorGreen[]  = {  0, 1.0,   0 };
    GLfloat colorBlue[]   = {  0,   0, 1.0 };
    GLfloat colorOrange[] = {1.0, 0.5, 0.18};
    GLfloat colorYellow[] = {1.0, 1.0,   0 };
    GLfloat colorWhite[]  = {1.0, 1.0, 1.0 };
    GLfloat colorBlack[]  = {  0,   0,   0 };

    rubikCube.push_back(Cube(colorRed, colorBlack, colorBlack, colorBlue, colorWhite,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorRed, colorBlack, colorBlack, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorRed, colorBlack, colorGreen, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorBlack, colorBlack, colorBlack, colorBlue, colorWhite,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorBlack, colorBlack, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorBlack, colorGreen, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorBlack, colorOrange, colorBlack, colorBlue, colorWhite,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorOrange, colorBlack, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorOrange, colorGreen, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorRed, colorBlack, colorBlack, colorBlue, colorBlack,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorRed, colorBlack, colorBlack, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorRed, colorBlack, colorGreen, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorBlack, colorBlack, colorBlack, colorBlue, colorBlack,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorBlack, colorBlack, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorBlack, colorGreen, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorBlack, colorOrange, colorBlack, colorBlue, colorBlack,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorOrange, colorBlack, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorOrange, colorGreen, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorRed, colorBlack, colorBlack, colorBlue, colorBlack,colorYellow, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorRed, colorBlack, colorBlack, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorRed, colorBlack, colorGreen, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorBlack, colorBlack, colorBlack, colorBlue, colorBlack,colorYellow, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorBlack, colorBlack, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorBlack, colorGreen, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0));

    rubikCube.push_back(Cube(colorBlack, colorOrange, colorBlack, colorBlue, colorBlack,colorYellow, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorOrange, colorBlack, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0));
    rubikCube.push_back(Cube(colorBlack, colorOrange, colorGreen, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0));
}

void OpenGLContext::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se limpian los buffers con el color activo definido por glClearColor

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Transformación de vista
    glTranslatef(panX, panY, zoomZ);
    glRotatef(rotY, 1.0, 0.0, 0.0);
    glRotatef(rotX, 0.0, 1.0, 0.0);
    // Escena

    //##############
    //      Pinta el primer nivel
    //##############

    rubikCube[0].paint();

    glPushMatrix();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        rubikCube[1].paint();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        rubikCube[2].paint();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.f,0.f,-spaceBetweenCubes);
        rubikCube[3].paint();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        rubikCube[4].paint();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        rubikCube[5].paint();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
        rubikCube[6].paint();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        rubikCube[7].paint();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        rubikCube[8].paint();
    glPopMatrix();

    //##############
    //      Pinta el segundo nivel
    //##############
    glPushMatrix();
        glTranslatef(0.f, spaceBetweenCubes, 0.f);
        rubikCube[9].paint();
        glPushMatrix();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[10].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[11].paint();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes);
            rubikCube[12].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[13].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[14].paint();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
            rubikCube[15].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[16].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[17].paint();
        glPopMatrix();
    glPopMatrix();

    //##############
    //      Pinta el tercer nivel
    //##############
    glPushMatrix();
        glTranslatef(0.f, spaceBetweenCubes*2, 0.f);
        rubikCube[18].paint();

        glPushMatrix();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[19].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[20].paint();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes);
            rubikCube[21].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[22].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[23].paint();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
            rubikCube[24].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[25].paint();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            rubikCube[26].paint();
        glPopMatrix();
    glPopMatrix();

    //glutSwapBuffers();			// Se intercambian buffers
}

void OpenGLContext::resizeGL(int w, int h){
    if (h == 0)
    {
        h = 1;
    }
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);      // Transf. de Proyección en Perspectiva
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);   								// Transf. de Viewport (mapeo al área de dibujo)
}

void OpenGLContext::mousePressEvent(QMouseEvent *e){
    mouseButton = e->button();
    mouseRotate = false;
    mouseZoom = false;
    mousePan = false;
    xClick = e->x();
    yClick = e->y();

    if(mouseButton == Qt::LeftButton){
        mouseRotate = true;
        xAux = rotX;
        yAux = rotY;
    }
    else if(mouseButton == Qt::RightButton){
        mouseZoom = true;
        xAux = zoomZ;
    }
    else if(mouseButton== Qt::MiddleButton){
        mousePan = true;
        xAux = panX;
        yAux = panY;
    }

}

void OpenGLContext::mouseMoveEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();

    if(mouseRotate == true){
        if(mouseButton == Qt::LeftButton){
            if ((x - xClick + xAux) > 360.0)
            {
                xAux = xAux - 360.0;
            }
            if ((x - xClick + xAux) < 0.0)
            {
                xAux = xAux + 360.0;
            }
            if ((y - yClick + yAux) > 360.0)
            {
                yAux = yAux - 360.0;
            }
            if ((y - yClick + yAux) < 0.0)
            {
                yAux = yAux + 360.0;
            }
            rotX = x - xClick + xAux;
            rotY = y - yClick + yAux;
        }
    }
    else if(mouseZoom == true){
        if(mouseButton == Qt::RightButton){
            zoomZ = ((x - xClick) / 10.0) + xAux;
        }
    }
    else if(mousePan == true){
        if(mouseButton == Qt::MiddleButton){
            panX = ((x - xClick) / 63.0) + xAux;
            panY = ((y - yClick) / (-63.0)) + yAux;
        }
    }

    //glutPostRedisplay();
    updateGL();
}

void OpenGLContext::keyPressEvent(QKeyEvent *event){
    cout << "Key pressed: "<< event->key() << endl;
    int key = event->key();

    if( event->key() == Qt::Key_F1){
        rotateRight(true);
        cout << "Rotate right" << endl;
    }else if(key == Qt::Key_F2){
        rotateRight(false);
    }else if(key == Qt::Key_F3){
        rotateLeft(true);
    }else if(key == Qt::Key_F4){
        rotateLeft(false);
    }else if(key == Qt::Key_F5){
        rotateFront(true);
    }else if(key == Qt::Key_F6){
        rotateFront(false);
    }else if(key == Qt::Key_F7){
        rotateBack(true);
    }else if(key == Qt::Key_F8){
        rotateBack(false);
    }else if(key == Qt::Key_F9){
        rotateUp(true);
    }else if(key == Qt::Key_F10){
        rotateUp(false);
    }else if(key == Qt::Key_F11){
        rotateDown(true);
    }else if(key == Qt::Key_F12){
        rotateDown(false);
    }
    //glutPostRedisplay();
    updateGL();
}


void OpenGLContext::rotateRight(bool clockWise){
    if(clockWise){
        Cube tmp1 = rubikCube[1];
        Cube tmp2 = rubikCube[0];
        Cube tmp3 = rubikCube[9];
        Cube tmp4 = rubikCube[18];

        rubikCube[0]  = rubikCube[2];
        rubikCube[1]  = rubikCube[11];
        rubikCube[2]  = rubikCube[20];
        rubikCube[9]  = tmp1;
        rubikCube[10] = rubikCube[10];
        rubikCube[11] = rubikCube[19];
        rubikCube[18] = tmp2;
        rubikCube[19] = tmp3;
        rubikCube[20] = tmp4;

        rubikCube[0].increase_rots(0.0, 0.0, -90.0);
        rubikCube[1].increase_rots(0.0, 0.0, -90.0);
        rubikCube[2].increase_rots(0.0, 0.0, -90.0);
        rubikCube[9].increase_rots(0.0, 0.0, -90.0);
        rubikCube[10].increase_rots(0.0, 0.0, -90.0);
        rubikCube[11].increase_rots(0.0, 0.0, -90.0);
        rubikCube[18].increase_rots(0.0, 0.0, -90.0);
        rubikCube[19].increase_rots(0.0, 0.0, -90.0);
        rubikCube[20].increase_rots(0.0, 0.0, -90.0);
    }else{
        Cube tmp1 = rubikCube[0];
        Cube tmp2 = rubikCube[1];
        Cube tmp3 = rubikCube[11];
        Cube tmp4 = rubikCube[2];

        rubikCube[0]  = rubikCube[18];
        rubikCube[1]  = rubikCube[9];
        rubikCube[2]  = tmp1;
        rubikCube[9]  = rubikCube[19];
        rubikCube[10] = rubikCube[10];
        rubikCube[11] = tmp2;
        rubikCube[18] = rubikCube[20];
        rubikCube[19] = tmp3;
        rubikCube[20] = tmp4;

        rubikCube[0].increase_rots(0.0, 0.0, 90.0);
        rubikCube[1].increase_rots(0.0, 0.0, 90.0);
        rubikCube[2].increase_rots(0.0, 0.0, 90.0);
        rubikCube[9].increase_rots(0.0, 0.0, 90.0);
        rubikCube[10].increase_rots(0.0, 0.0, 90.0);
        rubikCube[11].increase_rots(0.0, 0.0, 90.0);
        rubikCube[18].increase_rots(0.0, 0.0, 90.0);
        rubikCube[19].increase_rots(0.0, 0.0, 90.0);
        rubikCube[20].increase_rots(0.0, 0.0, 90.0);
    }
}

void OpenGLContext::rotateLeft(bool clockWise){
    if(clockWise){
        Cube tmp1 = rubikCube[7];
        Cube tmp2 = rubikCube[6];
        Cube tmp3 = rubikCube[15];
        Cube tmp4 = rubikCube[24];

        rubikCube[6]  = rubikCube[8];
        rubikCube[7]  = rubikCube[17];
        rubikCube[8] = rubikCube[26];
        rubikCube[15] = tmp1;
        rubikCube[16] = rubikCube[16];
        rubikCube[17] = rubikCube[25];
        rubikCube[24] = tmp2;
        rubikCube[25] = tmp3;
        rubikCube[26] = tmp4;

        rubikCube[6].increase_rots(0.0, 0.0, -90.0);
        rubikCube[7].increase_rots(0.0, 0.0, -90.0);
        rubikCube[8].increase_rots(0.0, 0.0, -90.0);
        rubikCube[15].increase_rots(0.0, 0.0, -90.0);
        rubikCube[16].increase_rots(0.0, 0.0, -90.0);
        rubikCube[17].increase_rots(0.0, 0.0, -90.0);
        rubikCube[24].increase_rots(0.0, 0.0, -90.0);
        rubikCube[25].increase_rots(0.0, 0.0, -90.0);
        rubikCube[26].increase_rots(0.0, 0.0, -90.0);
    }else{
        Cube tmp1 = rubikCube[6];
        Cube tmp2 = rubikCube[7];
        Cube tmp3 = rubikCube[17];
        Cube tmp4 = rubikCube[8];

        rubikCube[6]  = rubikCube[24];
        rubikCube[7]  = rubikCube[15];
        rubikCube[8]  = tmp1;
        rubikCube[15] = rubikCube[25];
        rubikCube[16] = rubikCube[16];
        rubikCube[17] = tmp2;
        rubikCube[24] = rubikCube[26];
        rubikCube[25] = tmp3;
        rubikCube[26] = tmp4;

        rubikCube[6].increase_rots(0.0, 0.0, 90.0);
        rubikCube[7].increase_rots(0.0, 0.0, 90.0);
        rubikCube[8].increase_rots(0.0, 0.0, 90.0);
        rubikCube[15].increase_rots(0.0, 0.0, 90.0);
        rubikCube[16].increase_rots(0.0, 0.0, 90.0);
        rubikCube[17].increase_rots(0.0, 0.0, 90.0);
        rubikCube[24].increase_rots(0.0, 0.0, 90.0);
        rubikCube[25].increase_rots(0.0, 0.0, 90.0);
        rubikCube[26].increase_rots(0.0, 0.0, 90.0);
    }
}

void OpenGLContext::rotateFront(bool clockWise){
    if(clockWise){
        Cube tmp1 = rubikCube[3];
        Cube tmp2 = rubikCube[6];
        Cube tmp3 = rubikCube[15];
        Cube tmp4 = rubikCube[24];

        rubikCube[6]  = rubikCube[0];
        rubikCube[3]  = rubikCube[9];
        rubikCube[0]  = rubikCube[18];
        rubikCube[15]  = tmp1;
        rubikCube[12] = rubikCube[12];
        rubikCube[9] = rubikCube[21];
        rubikCube[24] = tmp2;
        rubikCube[21] = tmp3;
        rubikCube[18] = tmp4;

        rubikCube[6].increase_rots(90.0, 0.0, 0.0);
        rubikCube[3].increase_rots(90.0, 0.0, 0.0);
        rubikCube[0].increase_rots(90.0, 0.0, 0.0);
        rubikCube[15].increase_rots(90.0, 0.0, 0.0);
        rubikCube[12].increase_rots(90.0, 0.0, 0.0);
        rubikCube[9].increase_rots(90.0, 0.0, 0.0);
        rubikCube[24].increase_rots(90.0, 0.0, 0.0);
        rubikCube[21].increase_rots(90.0, 0.0, 0.0);
        rubikCube[18].increase_rots(90.0, 0.0, 0.0);
    }else{
        Cube tmp1 = rubikCube[6];
        Cube tmp2 = rubikCube[3];
        Cube tmp3 = rubikCube[9];
        Cube tmp4 = rubikCube[0];

        rubikCube[6]  = rubikCube[24];
        rubikCube[3]  = rubikCube[15];
        rubikCube[0]  = tmp1;
        rubikCube[15]  = rubikCube[21];
        rubikCube[12] = rubikCube[12];
        rubikCube[9] = tmp2;
        rubikCube[24] = rubikCube[18];
        rubikCube[21] = tmp3;
        rubikCube[18] = tmp4;

        rubikCube[6].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[3].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[0].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[15].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[12].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[9].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[24].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[21].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[18].increase_rots(-90.0, 0.0, 0.0);
    }
}

void OpenGLContext::rotateBack(bool clockWise){
    if(clockWise){
        Cube tmp1 = rubikCube[5];
        Cube tmp2 = rubikCube[2];
        Cube tmp3 = rubikCube[11];
        Cube tmp4 = rubikCube[20];

        rubikCube[2]  = rubikCube[8];
        rubikCube[5]  = rubikCube[17];
        rubikCube[8]  = rubikCube[26];
        rubikCube[11] = tmp1;
        rubikCube[14] = rubikCube[14];
        rubikCube[17] = rubikCube[23];
        rubikCube[20] = tmp2;
        rubikCube[23] = tmp3;
        rubikCube[26] = tmp4;

        rubikCube[2].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[5].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[8].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[11].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[14].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[17].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[20].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[23].increase_rots(-90.0, 0.0, 0.0);
        rubikCube[26].increase_rots(-90.0, 0.0, 0.0);
    }else{
        Cube tmp1 = rubikCube[2];
        Cube tmp2 = rubikCube[5];
        Cube tmp3 = rubikCube[17];
        Cube tmp4 = rubikCube[8];

        rubikCube[2]  = rubikCube[20];
        rubikCube[5]  = rubikCube[11];
        rubikCube[8]  = tmp1;
        rubikCube[11]  = rubikCube[23];
        rubikCube[14] = rubikCube[14];
        rubikCube[17] = tmp2;
        rubikCube[20] = rubikCube[26];
        rubikCube[23] = tmp3;
        rubikCube[26] = tmp4;

        rubikCube[2].increase_rots(90.0, 0.0, 0.0);
        rubikCube[5].increase_rots(90.0, 0.0, 0.0);
        rubikCube[8].increase_rots(90.0, 0.0, 0.0);
        rubikCube[11].increase_rots(90.0, 0.0, 0.0);
        rubikCube[14].increase_rots(90.0, 0.0, 0.0);
        rubikCube[17].increase_rots(90.0, 0.0, 0.0);
        rubikCube[20].increase_rots(90.0, 0.0, 0.0);
        rubikCube[23].increase_rots(90.0, 0.0, 0.0);
        rubikCube[26].increase_rots(90.0, 0.0, 0.0);
    }
}

void OpenGLContext::rotateUp(bool clockWise){
    if(clockWise){
        Cube tmp1 = rubikCube[19];
        Cube tmp2 = rubikCube[18];
        Cube tmp3 = rubikCube[21];
        Cube tmp4 = rubikCube[24];

        rubikCube[18]  = rubikCube[20];
        rubikCube[19]  = rubikCube[23];
        rubikCube[20]  = rubikCube[26];
        rubikCube[21]  = tmp1;
        rubikCube[22] = rubikCube[22];
        rubikCube[23] = rubikCube[25];
        rubikCube[24] = tmp2;
        rubikCube[25] = tmp3;
        rubikCube[26] = tmp4;

        rubikCube[18].increase_rots(0.0, -90.0, 0.0);
        rubikCube[19].increase_rots(0.0, -90.0, 0.0);
        rubikCube[20].increase_rots(0.0, -90.0, 0.0);
        rubikCube[21].increase_rots(0.0, -90.0, 0.0);
        rubikCube[22].increase_rots(0.0, -90.0, 0.0);
        rubikCube[23].increase_rots(0.0, -90.0, 0.0);
        rubikCube[24].increase_rots(0.0, -90.0, 0.0);
        rubikCube[25].increase_rots(0.0, -90.0, 0.0);
        rubikCube[26].increase_rots(0.0, -90.0, 0.0);

    }else{
        Cube tmp1 = rubikCube[18];
        Cube tmp2 = rubikCube[19];
        Cube tmp3 = rubikCube[23];
        Cube tmp4 = rubikCube[20];

        rubikCube[18]  = rubikCube[24];
        rubikCube[19]  = rubikCube[21];
        rubikCube[20]  = tmp1;
        rubikCube[21]  = rubikCube[25];
        rubikCube[22] = rubikCube[22];
        rubikCube[23] = tmp2;
        rubikCube[24] = rubikCube[26];
        rubikCube[25] = tmp3;
        rubikCube[26] = tmp4;

        rubikCube[18].increase_rots(0.0, 90.0, 0.0);
        rubikCube[19].increase_rots(0.0, 90.0, 0.0);
        rubikCube[20].increase_rots(0.0, 90.0, 0.0);
        rubikCube[21].increase_rots(0.0, 90.0, 0.0);
        rubikCube[22].increase_rots(0.0, 90.0, 0.0);
        rubikCube[23].increase_rots(0.0, 90.0, 0.0);
        rubikCube[24].increase_rots(0.0, 90.0, 0.0);
        rubikCube[25].increase_rots(0.0, 90.0, 0.0);
        rubikCube[26].increase_rots(0.0, 90.0, 0.0);
    }
}

void OpenGLContext::rotateDown(bool clockWise){
    if(clockWise){
        Cube tmp1 = rubikCube[1];
        Cube tmp2 = rubikCube[0];
        Cube tmp3 = rubikCube[3];
        Cube tmp4 = rubikCube[6];

        rubikCube[0]  = rubikCube[2];
        rubikCube[1]  = rubikCube[5];
        rubikCube[2]  = rubikCube[8];
        rubikCube[3]  = tmp1;
        rubikCube[4] = rubikCube[4];
        rubikCube[5] = rubikCube[7];
        rubikCube[6] = tmp2;
        rubikCube[7] = tmp3;
        rubikCube[8] = tmp4;

        rubikCube[0].increase_rots(0.0, -90.0, 0.0);
        rubikCube[1].increase_rots(0.0, -90.0, 0.0);
        rubikCube[2].increase_rots(0.0, -90.0, 0.0);
        rubikCube[3].increase_rots(0.0, -90.0, 0.0);
        rubikCube[4].increase_rots(0.0, -90.0, 0.0);
        rubikCube[5].increase_rots(0.0, -90.0, 0.0);
        rubikCube[6].increase_rots(0.0, -90.0, 0.0);
        rubikCube[7].increase_rots(0.0, -90.0, 0.0);
        rubikCube[8].increase_rots(0.0, -90.0, 0.0);
    }else{
        Cube tmp1 = rubikCube[0];
        Cube tmp2 = rubikCube[1];
        Cube tmp3 = rubikCube[5];
        Cube tmp4 = rubikCube[2];

        rubikCube[0]  = rubikCube[6];
        rubikCube[1]  = rubikCube[3];
        rubikCube[2]  = tmp1;
        rubikCube[3]  = rubikCube[7];
        rubikCube[4] = rubikCube[4];
        rubikCube[5] = tmp2;
        rubikCube[6] = rubikCube[8];
        rubikCube[7] = tmp3;
        rubikCube[8] = tmp4;

        rubikCube[0].increase_rots(0.0, 90.0, 0.0);
        rubikCube[1].increase_rots(0.0, 90.0, 0.0);
        rubikCube[2].increase_rots(0.0, 90.0, 0.0);
        rubikCube[3].increase_rots(0.0, 90.0, 0.0);
        rubikCube[4].increase_rots(0.0, 90.0, 0.0);
        rubikCube[5].increase_rots(0.0, 90.0, 0.0);
        rubikCube[6].increase_rots(0.0, 90.0, 0.0);
        rubikCube[7].increase_rots(0.0, 90.0, 0.0);
        rubikCube[8].increase_rots(0.0, 90.0, 0.0);
    }
}

void OpenGLContext::geomCoordSys(GLfloat size)
{
    float currentColor[4];
    glGetFloatv(GL_CURRENT_COLOR, currentColor);

    // Eje X (Rojo)
    glColor3f(1., 0., 0.);
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(size, 0., 0.);
    glEnd();

    // Eje Y (Verde))
    glColor3f(0., 1., 0.);
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(0., size, 0.);
    glEnd();

    // Eje Z (Azul)
    glColor3f(0., 0., 1.);
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(0., 0., size);
    glEnd();

    glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

void OpenGLContext::perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;

    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}
