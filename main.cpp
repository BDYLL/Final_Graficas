#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>

using namespace std;

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
GLfloat panX = 0.f;
GLfloat panY = 0.f;
GLfloat zoomZ = -25.f;

GLfloat rot = 0.;
float spaceBetweenCubes = 2.1f;

/*
GLfloat colorRed[]    = {255,	0,	0};
GLfloat colorGreen[]  = {  0,255,  0};
GLfloat colorBlue[]   = {	0,	0,255};
GLfloat colorOrange[] = {255,127, 39};
GLfloat colorYellow[] = {255,255,	0};
GLfloat colorWhite[]  = {255,255,255};
GLfloat colorBlack[]  = {  0,	0,	0};
*/


void glutTexturedCubeBase(GLdouble size, GLfloat* color1, GLfloat* color2, GLfloat* color3,
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
void glutTexturedCube1(GLdouble size)
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
void glutTexturedCube2(GLdouble size)
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
void glutTexturedCube3(GLdouble size)
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
void glutTexturedCube4(GLdouble size)
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
void glutTexturedCube5(GLdouble size)
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
void glutTexturedCube6(GLdouble size)
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
void glutTexturedCube7(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    //GLfloat color2[] = { 255, 127,  39 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Orange
void glutTexturedCube8(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//White Green Orange
void glutTexturedCube9(GLdouble size)
{
    GLfloat color1[] = {   0, 	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue Red
void glutTexturedCube10(GLdouble size)
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
void glutTexturedCube11(GLdouble size)
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
void glutTexturedCube12(GLdouble size)
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
void glutTexturedCube13(GLdouble size)
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
void glutTexturedCube14(GLdouble size)
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
void glutTexturedCube15(GLdouble size)
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
void glutTexturedCube16(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0, 255 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Orange
void glutTexturedCube17(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Green Orange
void glutTexturedCube18(GLdouble size)
{
    GLfloat color1[] = {   0, 	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,   0 };
    GLfloat color6[] = {   0,	0,	 0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Blue Yellow Red
void glutTexturedCube19(GLdouble size)
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
void glutTexturedCube20(GLdouble size)
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
void glutTexturedCube21(GLdouble size)
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
void glutTexturedCube22(GLdouble size)
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
void glutTexturedCube23(GLdouble size)
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
void glutTexturedCube24(GLdouble size)
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
void glutTexturedCube25(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0, 255 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Orange
void glutTexturedCube26(GLdouble size)
{
    GLfloat color1[] = {   0,	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0,	0,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

//Yellow Orange Green
void glutTexturedCube27(GLdouble size)
{
    GLfloat color1[] = {   0, 	0,   0 };
    GLfloat color2[] = { 255,   0, 255 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0, 	0,   0 };
    GLfloat color5[] = {   0,	0,	 0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
}

// Función que inicializa el Contexto OpenGL y la geometría de la escena
void init()
{
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glColor3f(1.f, 1.f, 1.f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
}

// Función que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
    if (h == 0)
    {
        h = 1;
    }
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);		// Transf. de Proyección en Perspectiva
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);								// Transf. de Viewport (mapeo al área de dibujo)
}

// Geometría sistema coordenado
void geomCoordSys(GLfloat size)
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

// Función que se invoca cada vez que se dibuja
void render()
{
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
    glutTexturedCube1(1);

    glPushMatrix();
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube2(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube3(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-spaceBetweenCubes);
    glutTexturedCube4(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube5(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube6(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
    glutTexturedCube7(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube8(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube9(1);
    glPopMatrix();

    //##############
    //		Pinta el segundo nivel
    //##############
    glPushMatrix();
    glTranslatef(0.f, spaceBetweenCubes, 0.f);
    glutTexturedCube10(1);

    glPushMatrix();
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube11(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube12(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-spaceBetweenCubes);
    glutTexturedCube13(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube14(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube15(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
    glutTexturedCube16(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube17(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube18(1);
    glPopMatrix();
    //##############
    //		Pinta el tercer nivel
    //##############
    glTranslatef(0.f, spaceBetweenCubes, 0.f);
    glutTexturedCube19(1);

    glPushMatrix();
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube20(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube21(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-spaceBetweenCubes);
    glutTexturedCube22(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube23(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube24(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
    glutTexturedCube25(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube26(1);
    glTranslatef(spaceBetweenCubes,0.f,0.f);
    glutTexturedCube27(1);
    glPopMatrix();
    glPopMatrix();


    glutSwapBuffers();			// Se intercambian buffers
}

void mouse(int button, int state, int x, int y)
{
    mouseButton = button;
    mouseRotate = false;
    mouseZoom = false;
    mousePan = false;
    xClick = x;
    yClick = y;
    if (button == GLUT_LEFT_BUTTON)
    {
        mouseRotate = true;
        xAux = rotX;
        yAux = rotY;
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        mouseZoom = true;
        xAux = zoomZ;
    }
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        mousePan = true;
        xAux = panX;
        yAux = panY;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseRotate == true)
    {
        if (mouseButton == GLUT_LEFT_BUTTON)
        {
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
    else if (mouseZoom == true)
    {
        if (mouseButton == GLUT_RIGHT_BUTTON)
        {
            zoomZ = ((x - xClick) / 10.0) + xAux;
        }
    }
    else if (mousePan == true)
    {
        if (mouseButton == GLUT_MIDDLE_BUTTON)
        {
            panX = ((x - xClick) / 63.0) + xAux;
            panY = ((y - yClick) / (-63.0)) + yAux;
        }
    }
    glutPostRedisplay();
}

int main(GLint argc, GLchar **argv)
{
    // 1. Se crea una ventana y un contexto OpenGL usando GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Rubik tests");

    // 1.2 Se definen las funciones callback para el manejo de eventos
    glutReshapeFunc(resize);
    glutDisplayFunc(render);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    // 2. Se direcciona a las funciones correctas del API de OpenGL
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        return false;
    }

    // 3. Se inicializa el contexto de OpenGL y la geometría de la escena
    init();

    // 4. Se inicia el ciclo de escucha de eventos
    glutMainLoop();
    return 0;
}