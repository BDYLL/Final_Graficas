#include "openglcontext.h"

OpenGLContext::OpenGLContext(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->idOfCubes  = {1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 11, 12, 13, 14, 15, 16, 17, 18,
            19, 20, 21, 22, 23, 24, 25, 26, 27};

}

void OpenGLContext::initializeGL(){
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glColor3f(1.f, 1.f, 1.f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
}

void OpenGLContext::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Se limpian los buffers con el color activo definido por glClearColor

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Transformación de vista
    glTranslatef(panX, panY, zoomZ);
    glRotatef(rotY, 1.0, 0.0, 0.0);
    glRotatef(rotX, 0.0, 1.0, 0.0);

    // Escena
    geomCoordSys(2.f);


    //##############
    //		Pinta el primer nivel
    //##############


    //glutTexturedCube1(1);
    drawCurrentCube(idOfCubes[0]);

    glPushMatrix();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube2(1);
        drawCurrentCube(idOfCubes[1]);
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube3(1);
        drawCurrentCube(idOfCubes[2]);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.f,0.f,-spaceBetweenCubes);
        //glutTexturedCube4(1);
        drawCurrentCube(idOfCubes[3]);
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube5(1);
        drawCurrentCube(idOfCubes[4]);
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube6(1);
        drawCurrentCube(idOfCubes[5]);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
        //glutTexturedCube7(1);
        drawCurrentCube(idOfCubes[6]);
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube8(1);
        drawCurrentCube(idOfCubes[7]);
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube9(1);
        drawCurrentCube(idOfCubes[8]);
    glPopMatrix();

    //##############
    //		Pinta el segundo nivel
    //##############
    glPushMatrix();
        glTranslatef(0.f, spaceBetweenCubes, 0.f);
        //glutTexturedCube10(1);
        drawCurrentCube(idOfCubes[9]);

        glPushMatrix();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube11(1);
            drawCurrentCube(idOfCubes[10]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube12(1);
            drawCurrentCube(idOfCubes[11]);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes);
            //glutTexturedCube13(1);
            drawCurrentCube(idOfCubes[12]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube14(1);
            drawCurrentCube(idOfCubes[13]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube15(1);
            drawCurrentCube(idOfCubes[14]);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
            //glutTexturedCube16(1);
            drawCurrentCube(idOfCubes[15]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube17(1);
            drawCurrentCube(idOfCubes[16]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube18(1);
            drawCurrentCube(idOfCubes[17]);
        glPopMatrix();
        //##############
        //		Pinta el tercer nivel
        //##############
        glTranslatef(0.f, spaceBetweenCubes, 0.f);
        //glutTexturedCube19(1);
        drawCurrentCube(idOfCubes[18]);

        glPushMatrix();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube20(1);
            drawCurrentCube(idOfCubes[19]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube21(1);
            drawCurrentCube(idOfCubes[20]);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes);
            //glutTexturedCube22(1);
            drawCurrentCube(idOfCubes[21]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube23(1);
            drawCurrentCube(idOfCubes[22]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube24(1);
            drawCurrentCube(idOfCubes[23]);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
            //glutTexturedCube25(1);
            drawCurrentCube(idOfCubes[24]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube26(1);
            drawCurrentCube(idOfCubes[25]);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube27(1);
            drawCurrentCube(idOfCubes[26]);
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
    perspectiveGL(25.f, (float)width / height, 0.1f, 1000.f);		// Transf. de Proyección en Perspectiva
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);								// Transf. de Viewport (mapeo al área de dibujo)
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

    if( event->key() == Qt::Key_F1){
        rotateRight(true);
        cout << "Rotate right" << endl;
    }
    //glutPostRedisplay();
    updateGL();
}

void OpenGLContext::glutTexturedCubeBase(GLdouble size, GLfloat* color1, GLfloat* color2, GLfloat* color3,
                                        GLfloat* color4,GLfloat* color5, GLfloat* color6){

GLfloat color[] = {
    color1[0], color1[1], color1[2],
    color1[0], color1[1], color1[2],
    color1[0], color1[1], color1[2],
    color1[0], color1[1], color1[2],
    color1[0], color1[1], color1[2],
    color1[0], color1[1], color1[2],

    color2[0], color2[1], color2[2],
    color2[0], color2[1], color2[2],
    color2[0], color2[1], color2[2],
    color2[0], color2[1], color2[2],
    color2[0], color2[1], color2[2],
    color2[0], color2[1], color2[2],

    color3[0], color3[1], color3[2],
    color3[0], color3[1], color3[2],
    color3[0], color3[1], color3[2],
    color3[0], color3[1], color3[2],
    color3[0], color3[1], color3[2],
    color3[0], color3[1], color3[2],

    color4[0], color4[1], color4[2],
    color4[0], color4[1], color4[2],
    color4[0], color4[1], color4[2],
    color4[0], color4[1], color4[2],
    color4[0], color4[1], color4[2],
    color4[0], color4[1], color4[2],

    color5[0], color5[1], color5[2],
    color5[0], color5[1], color5[2],
    color5[0], color5[1], color5[2],
    color5[0], color5[1], color5[2],
    color5[0], color5[1], color5[2],
    color5[0], color5[1], color5[2],

    color6[0], color6[1], color6[2],
    color6[0], color6[1], color6[2],
    color6[0], color6[1], color6[2],
    color6[0], color6[1], color6[2],
    color6[0], color6[1], color6[2],
    color6[0], color6[1], color6[2],
};

    GLfloat vert[] = {
        // top (+z)
        -1, -1,  1,
         1, -1,  1,
        -1,  1,  1,
        -1,  1,  1,
         1, -1,  1,
         1,  1,  1,

        // bottom (-z)
        -1, -1, -1,
        -1,  1, -1,
         1, -1, -1,
         1, -1, -1,
        -1,  1, -1,
         1,  1, -1,

        // right (+x)
         1, -1, -1,
         1,  1, -1,
         1, -1,  1,
         1, -1,  1,
         1,  1, -1,
         1,  1,  1,

        // left (-x)
        -1, -1, -1,
        -1, -1,  1,
        -1,  1, -1,
        -1,  1, -1,
        -1, -1,  1,
        -1,  1,  1,

        // front (+y)
        -1, -1, -1,
         1, -1, -1,
        -1, -1,  1,
        -1, -1,  1,
         1, -1, -1,
         1, -1,  1,

        // back (-y)
        -1,  1, -1,
        -1,  1,  1,
         1,  1, -1,
         1,  1, -1,
        -1,  1,  1,
         1,  1,  1,
    };

    GLushort idxs[] = {
         0, 1, 2,
         3, 4, 5,

         6, 7, 8,
         9,10,11,

        12,13,14,
        15,16,17,

        18,19,20,
        21,22,23,

        24,25,26,
        27,28,29,

        30,31,32,
        33,34,35
    };

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, color);
    glVertexPointer(3, GL_FLOAT, 0, vert);

    glPushMatrix();
    glColor4f(1, 1, 1, 1);
    glScaled(size, size, size);
    glDrawElements(GL_TRIANGLES, sizeof(idxs)/sizeof(idxs[0]), GL_UNSIGNED_SHORT, idxs);
    glPopMatrix();

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

//Blue White Red
void OpenGLContext::glutTexturedCube1(GLdouble size)
{
    GLfloat color1[] = { 255,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,	0,	 0 };
    GLfloat color4[] = {   0,	0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Red
void OpenGLContext::glutTexturedCube2(GLdouble size)
{
    GLfloat color1[] = { 255,	0,	 0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,	0,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Red Green
void OpenGLContext::glutTexturedCube3(GLdouble size)
{
    GLfloat color1[] = { 255,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0, 255,	 0 };
    GLfloat color4[] = {   0,	0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue White
void OpenGLContext::glutTexturedCube4(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,   0,	 0 };
    GLfloat color4[] = {   0,	0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White
void OpenGLContext::glutTexturedCube5(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,   0,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Green
void OpenGLContext::glutTexturedCube6(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0, 255,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Orange Blue
void OpenGLContext::glutTexturedCube7(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Orange
void OpenGLContext::glutTexturedCube8(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Green Orange
void OpenGLContext::glutTexturedCube9(GLdouble size)
{
    GLfloat color1[] = {   0, 	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue Red
void OpenGLContext::glutTexturedCube10(GLdouble size)
{
    GLfloat color1[] = { 255,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,	0,	 0 };
    GLfloat color4[] = {   0,	0, 255 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Red
void OpenGLContext::glutTexturedCube11(GLdouble size)
{
    GLfloat color1[] = { 255,	0,	 0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,	0,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Red Green
void OpenGLContext::glutTexturedCube12(GLdouble size)
{
    GLfloat color1[] = { 255,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0, 255,	 0 };
    GLfloat color4[] = {   0,	0,   0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue
void OpenGLContext::glutTexturedCube13(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,   0,	 0 };
    GLfloat color4[] = {   0,	0, 255 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//El centro del cubo rubik
void OpenGLContext::glutTexturedCube14(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,   0,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Green
void OpenGLContext::glutTexturedCube15(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0, 255,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Orange Blue
void OpenGLContext::glutTexturedCube16(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0, 255 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Orange
void OpenGLContext::glutTexturedCube17(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Green Orange
void OpenGLContext::glutTexturedCube18(GLdouble size)
{
    GLfloat color1[] = {   0, 	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue Yellow Red
void OpenGLContext::glutTexturedCube19(GLdouble size)
{
    GLfloat color1[] = { 255,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,	0,	 0 };
    GLfloat color4[] = {   0,	0, 255 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Red
void OpenGLContext::glutTexturedCube20(GLdouble size)
{
    GLfloat color1[] = { 255,	0,	 0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,	0,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Red Green
void OpenGLContext::glutTexturedCube21(GLdouble size)
{
    GLfloat color1[] = { 255,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0, 255,	 0 };
    GLfloat color4[] = {   0,	0,   0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue Yellow
void OpenGLContext::glutTexturedCube22(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,   0,	 0 };
    GLfloat color4[] = {   0,	0, 255 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow
void OpenGLContext::glutTexturedCube23(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0,   0,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Green
void OpenGLContext::glutTexturedCube24(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   0,	0,   0 };
    GLfloat color3[] = {   0, 255,	 0 };
    GLfloat color4[] = {   0,	0,	 0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Orange Blue
void OpenGLContext::glutTexturedCube25(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0, 255 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Orange
void OpenGLContext::glutTexturedCube26(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Orange Green
void OpenGLContext::glutTexturedCube27(GLdouble size)
{
    GLfloat color1[] = {   0, 	0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

void OpenGLContext::rotateRight(bool clockWise){
    if(clockWise){
        int tmp1 = idOfCubes[1];
        int tmp2 = idOfCubes[2];
        int tmp3 = idOfCubes[19];

        idOfCubes[1]  = idOfCubes[3];
        idOfCubes[3]  = idOfCubes[21];
        idOfCubes[21] = idOfCubes[19];
        idOfCubes[19] = tmp1;
        idOfCubes[2]  = idOfCubes[12];
        idOfCubes[12] = idOfCubes[20];
        idOfCubes[20] = idOfCubes[10];
        idOfCubes[10] = tmp2;
        idOfCubes[21] = tmp3;
    }else{
        int tmp1 = idOfCubes[1];
        int tmp2 = idOfCubes[21];
        int tmp3 = idOfCubes[20];

        idOfCubes[1]  = idOfCubes[19];
        idOfCubes[19] = idOfCubes[21];
        idOfCubes[21] = idOfCubes[3];
        idOfCubes[3]  = tmp1;
        idOfCubes[2]  = idOfCubes[10];
        idOfCubes[10] = idOfCubes[20];
        idOfCubes[20] = idOfCubes[12];
        idOfCubes[12] = tmp2;
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

void OpenGLContext::drawCurrentCube(int indexCube){
    if(indexCube==1){
        glutTexturedCube1(1);
    }else if(indexCube==2){
        glutTexturedCube2(1);
    }else if(indexCube==3){
        glutTexturedCube3(1);
    }else if(indexCube==4){
        glutTexturedCube4(1);
    }else if(indexCube==5){
        glutTexturedCube5(1);
    }else if(indexCube==6){
        glutTexturedCube6(1);
    }else if(indexCube==7){
        glutTexturedCube7(1);
    }else if(indexCube==8){
        glutTexturedCube8(1);
    }else if(indexCube==9){
        glutTexturedCube9(1);
    }else if(indexCube==10){
        glutTexturedCube10(1);
    }else if(indexCube==11){
        glutTexturedCube11(1);
    }else if(indexCube==12){
        glutTexturedCube12(1);
    }else if(indexCube==13){
        glutTexturedCube13(1);
    }else if(indexCube==14){
        glutTexturedCube14(1);
    }else if(indexCube==15){
        glutTexturedCube15(1);
    }else if(indexCube==16){
        glutTexturedCube16(1);
    }else if(indexCube==17){
        glutTexturedCube17(1);
    }else if(indexCube==18){
        glutTexturedCube18(1);
    }else if(indexCube==19){
        glutTexturedCube19(1);
    }else if(indexCube==20){
        glutTexturedCube20(1);
    }else if(indexCube==21){
        glutTexturedCube21(1);
    }else if(indexCube==22){
        glutTexturedCube22(1);
    }else if(indexCube==23){
        glutTexturedCube23(1);
    }else if(indexCube==24){
        glutTexturedCube24(1);
    }else if(indexCube==25){
        glutTexturedCube25(1);
    }else if(indexCube==26){
        glutTexturedCube26(1);
    }else if(indexCube==27){
        glutTexturedCube27(1);
    }
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
