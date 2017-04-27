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
GLfloat panX = -2.f;
GLfloat panY = -3.f;
GLfloat zoomZ = -55.f;

GLfloat rot = 0.;
float spaceBetweenCubes = 2.1f;

int idOfCubes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                10, 11, 12, 13, 14, 15, 16, 17, 18,
                19, 20, 21, 22, 23, 24, 25, 26, 27};

/*
GLfloat colorRed[]    = {255,   0,  0};
GLfloat colorGreen[]  = {  0,255,  0};
GLfloat colorBlue[]   = {   0,  0,255};
GLfloat colorOrange[] = {255,127, 39};
GLfloat colorYellow[] = {255,255,   0};
GLfloat colorWhite[]  = {255,255,255};
GLfloat colorBlack[]  = {  0,   0,  0};
*/

class Cube {
    GLfloat color[];
    float rotX;
    float rotY;
    float rotZ;

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

  public:
    Cube (GLfloat*,GLfloat*,GLfloat*,GLfloat*,GLfloat*,GLfloat*,float, float, float);
    // GLfloat representa el color de una de las caras: {1.0, 1.0, 1.0}
    void set_colors (GLfloat*,GLfloat*,GLfloat*,GLfloat*,GLfloat*,GLfloat*);
    void set_colors (float, float, float);
    void paint () {
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, color);
        glVertexPointer(3, GL_FLOAT, 0, vert);

        glPushMatrix();
        glColor4f(1, 1, 1, 1);
        glScaled(1, 1, 1);
        glRotatef(rotX, 1.0, 0.0, 0.0);
        glRotatef(rotY, 0.0, 1.0, 0.0);
        glRotatef(rotZ, 0.0, 0.0, 1.0);
        glDrawElements(GL_TRIANGLES, sizeof(idxs)/sizeof(idxs[0]), GL_UNSIGNED_SHORT, idxs);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

Cube::Cube (GLfloat* color1, GLfloat* color2, GLfloat* color3,
            GLfloat* color4,GLfloat* color5, GLfloat* color6, float rX, float rY, float rZ) {
    rotX = rX;
    rotY = rY;
    rotZ = rZ;

    color[] = {
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

}

void Cube::set_colors (GLfloat* color1, GLfloat* color2, GLfloat* color3,
                    GLfloat* color4,GLfloat* color5, GLfloat* color6) {
    color[] = {
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
}

void Cube::set_rots (float rX, float rY, float rZ) {
    rotX = rx;
    rotY = rY;
    rotZ = rZ;
}




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


}


//Blue White Red
void glutTexturedCube1(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };

    if(position==1){
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6); 
    }else if(position==3){
        glRotatef(90, 0.0, 0.0, 1.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-90, 0.0, 0.0, 1.0);
    }else if(position==7){
        glRotatef(-90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 1.0, 0.0);
    }else if(position==9){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }
    else if(position==19){
        glRotatef(-90, 0.0, 0.0, 1.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 0.0, 1.0);   
    }else if(position==21){
        glRotatef(-180, 0.0, 0.0, 1.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(180, 0.0, 0.0, 1.0);
    }else if(position==25){
        glRotatef(-90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 1.0, 0.0);
    }else if(position==27){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }
} 

//White Red
void glutTexturedCube2(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };

    if(position==2){
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6); 
    }else if(position==4){
        glRotatef(90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-90, 0.0, 1.0, 0.0);
    }else if(position==6){
        glRotatef(-90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 1.0, 0.0);
    }else if(position==8){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }
    else if(position==10){
        glRotatef(-90, 0.0, 0.0, 1.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 0.0, 1.0);   
    }else if(position==12){
        glRotatef(90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-90, 0.0, 1.0, 0.0);
    }else if(position==16){
        glRotatef(-90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 1.0, 0.0);
    }else if(position==18){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }else if(position==20){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }else if(position==22){
        glRotatef(-90, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(90, 0.0, 1.0, 0.0);
    }else if(position==24){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }else if(position==26){
        glRotatef(180, 0.0, 1.0, 0.0);
        glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
        glRotatef(-180, 0.0, 1.0, 0.0);
    }   
} 

//White Red Green
void glutTexturedCube3(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Blue White
void glutTexturedCube4(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//White
void glutTexturedCube5(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//White Green
void glutTexturedCube6(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//White Orange Blue
void glutTexturedCube7(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//White Orange
void glutTexturedCube8(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//White Green Orange
void glutTexturedCube9(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = { 255, 255, 255 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Blue Red
void glutTexturedCube10(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Red
void glutTexturedCube11(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Red Green
void glutTexturedCube12(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Blue
void glutTexturedCube13(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//El centro del cubo rubik
void glutTexturedCube14(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Green
void glutTexturedCube15(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Orange Blue
void glutTexturedCube16(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Orange
void glutTexturedCube17(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Green Orange
void glutTexturedCube18(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = {   0,   0,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Blue Yellow Red
void glutTexturedCube19(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow Red
void glutTexturedCube20(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow Red Green
void glutTexturedCube21(GLdouble size, int position)
{
    GLfloat color1[] = { 255,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Blue Yellow
void glutTexturedCube22(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow
void glutTexturedCube23(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow Green
void glutTexturedCube24(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   0,   0,   0 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow Orange Blue
void glutTexturedCube25(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0, 255 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow Orange
void glutTexturedCube26(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0,   0,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

//Yellow Orange Green
void glutTexturedCube27(GLdouble size, int position)
{
    GLfloat color1[] = {   0,   0,   0 };
    GLfloat color2[] = {   1,0.54,0.18 };
    GLfloat color3[] = {   0, 255,   0 };
    GLfloat color4[] = {   0,   0,   0 };
    GLfloat color5[] = {   0,   0,   0 };
    GLfloat color6[] = { 255, 255,   0 };
    glutTexturedCubeBase(size, color1, color2, color3, color4, color5, color6);
} 

void rotateRight(bool clockWise){
    if(clockWise){      
        int tmp1 = idOfCubes[1];
        int tmp2 = idOfCubes[0];
        int tmp3 = idOfCubes[9];
        int tmp4 = idOfCubes[18];

        idOfCubes[0]  = idOfCubes[2];
        idOfCubes[1]  = idOfCubes[11];
        idOfCubes[2]  = idOfCubes[20];
        idOfCubes[9]  = tmp1;
        idOfCubes[10] = idOfCubes[10];
        idOfCubes[11] = idOfCubes[19];      
        idOfCubes[18] = tmp2;
        idOfCubes[19] = tmp3;
        idOfCubes[20] = tmp4;
    }else{
        int tmp1 = idOfCubes[0];
        int tmp2 = idOfCubes[1];
        int tmp3 = idOfCubes[11];
        int tmp4 = idOfCubes[2];

        idOfCubes[0]  = idOfCubes[18];
        idOfCubes[1]  = idOfCubes[9];
        idOfCubes[2]  = tmp1;
        idOfCubes[9]  = idOfCubes[19];
        idOfCubes[10] = idOfCubes[10];
        idOfCubes[11] = tmp2;
        idOfCubes[18] = idOfCubes[20];
        idOfCubes[19] = tmp3;
        idOfCubes[20] = tmp4;       
    }
}

void rotateLeft(bool clockWise){
    if(clockWise){      
        int tmp1 = idOfCubes[7];
        int tmp2 = idOfCubes[6];
        int tmp3 = idOfCubes[15];
        int tmp4 = idOfCubes[24];

        idOfCubes[6]  = idOfCubes[8];
        idOfCubes[7]  = idOfCubes[17];
        idOfCubes[8] = idOfCubes[26];
        idOfCubes[15] = tmp1;
        idOfCubes[16] = idOfCubes[16];
        idOfCubes[17] = idOfCubes[25];      
        idOfCubes[24] = tmp2;
        idOfCubes[25] = tmp3;
        idOfCubes[26] = tmp4;
    }else{
        int tmp1 = idOfCubes[6];
        int tmp2 = idOfCubes[7];
        int tmp3 = idOfCubes[17];
        int tmp4 = idOfCubes[8];

        idOfCubes[6]  = idOfCubes[24];
        idOfCubes[7]  = idOfCubes[15];
        idOfCubes[8]  = tmp1;
        idOfCubes[15] = idOfCubes[25];
        idOfCubes[16] = idOfCubes[16];
        idOfCubes[17] = tmp2;
        idOfCubes[24] = idOfCubes[26];
        idOfCubes[25] = tmp3;
        idOfCubes[26] = tmp4;       
    }
}

void rotateFront(bool clockWise){
    if(clockWise){      
        int tmp1 = idOfCubes[3];
        int tmp2 = idOfCubes[6];
        int tmp3 = idOfCubes[15];
        int tmp4 = idOfCubes[24];

        idOfCubes[6]  = idOfCubes[0];
        idOfCubes[3]  = idOfCubes[9];
        idOfCubes[0]  = idOfCubes[18];
        idOfCubes[15]  = tmp1;
        idOfCubes[10] = idOfCubes[10];
        idOfCubes[9] = idOfCubes[21];       
        idOfCubes[24] = tmp2;
        idOfCubes[21] = tmp3;
        idOfCubes[18] = tmp4;
    }else{
        int tmp1 = idOfCubes[6];
        int tmp2 = idOfCubes[3];
        int tmp3 = idOfCubes[9];
        int tmp4 = idOfCubes[0];

        idOfCubes[6]  = idOfCubes[24];
        idOfCubes[3]  = idOfCubes[15];
        idOfCubes[0]  = tmp1;
        idOfCubes[15]  = idOfCubes[21];
        idOfCubes[10] = idOfCubes[10];
        idOfCubes[9] = tmp2;
        idOfCubes[24] = idOfCubes[18];
        idOfCubes[21] = tmp3;
        idOfCubes[18] = tmp4;       
    }
}

void rotateBack(bool clockWise){
    if(clockWise){      
        int tmp1 = idOfCubes[5];
        int tmp2 = idOfCubes[2];
        int tmp3 = idOfCubes[11];
        int tmp4 = idOfCubes[20];

        idOfCubes[2]  = idOfCubes[8];
        idOfCubes[5]  = idOfCubes[17];
        idOfCubes[8]  = idOfCubes[26];
        idOfCubes[11]  = tmp1;
        idOfCubes[14] = idOfCubes[14];
        idOfCubes[17] = idOfCubes[23];      
        idOfCubes[20] = tmp2;
        idOfCubes[23] = tmp3;
        idOfCubes[26] = tmp4;
    }else{
        int tmp1 = idOfCubes[2];
        int tmp2 = idOfCubes[5];
        int tmp3 = idOfCubes[17];
        int tmp4 = idOfCubes[8];

        idOfCubes[2]  = idOfCubes[20];
        idOfCubes[5]  = idOfCubes[11];
        idOfCubes[8]  = tmp1;
        idOfCubes[11]  = idOfCubes[23];
        idOfCubes[14] = idOfCubes[14];
        idOfCubes[17] = tmp2;
        idOfCubes[20] = idOfCubes[26];
        idOfCubes[23] = tmp3;
        idOfCubes[26] = tmp4;       
    }
}

void rotateUp(bool clockWise){
    if(clockWise){      
        int tmp1 = idOfCubes[19];
        int tmp2 = idOfCubes[18];
        int tmp3 = idOfCubes[21];
        int tmp4 = idOfCubes[24];

        idOfCubes[18]  = idOfCubes[20];
        idOfCubes[19]  = idOfCubes[23];
        idOfCubes[20]  = idOfCubes[26];
        idOfCubes[21]  = tmp1;
        idOfCubes[22] = idOfCubes[22];
        idOfCubes[23] = idOfCubes[25];      
        idOfCubes[24] = tmp2;
        idOfCubes[25] = tmp3;
        idOfCubes[26] = tmp4;
    }else{
        int tmp1 = idOfCubes[18];
        int tmp2 = idOfCubes[19];
        int tmp3 = idOfCubes[23];
        int tmp4 = idOfCubes[20];

        idOfCubes[18]  = idOfCubes[24];
        idOfCubes[19]  = idOfCubes[21];
        idOfCubes[20]  = tmp1;
        idOfCubes[21]  = idOfCubes[25];
        idOfCubes[22] = idOfCubes[22];
        idOfCubes[23] = tmp2;
        idOfCubes[24] = idOfCubes[26];
        idOfCubes[25] = tmp3;
        idOfCubes[26] = tmp4;       
    }
}

void rotateDown(bool clockWise){
    if(clockWise){      
        int tmp1 = idOfCubes[1];
        int tmp2 = idOfCubes[0];
        int tmp3 = idOfCubes[3];
        int tmp4 = idOfCubes[6];

        idOfCubes[0]  = idOfCubes[2];
        idOfCubes[1]  = idOfCubes[5];
        idOfCubes[2]  = idOfCubes[8];
        idOfCubes[3]  = tmp1;
        idOfCubes[4] = idOfCubes[4];
        idOfCubes[5] = idOfCubes[7];        
        idOfCubes[6] = tmp2;
        idOfCubes[7] = tmp3;
        idOfCubes[8] = tmp4;
    }else{
        int tmp1 = idOfCubes[0];
        int tmp2 = idOfCubes[1];
        int tmp3 = idOfCubes[5];
        int tmp4 = idOfCubes[2];

        idOfCubes[0]  = idOfCubes[6];
        idOfCubes[1]  = idOfCubes[3];
        idOfCubes[2]  = tmp1;
        idOfCubes[3]  = idOfCubes[7];
        idOfCubes[4] = idOfCubes[4];
        idOfCubes[5] = tmp2;
        idOfCubes[6] = idOfCubes[8];
        idOfCubes[7] = tmp3;
        idOfCubes[8] = tmp4;        
    }
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
    gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);      // Transf. de Proyección en Perspectiva
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);                                // Transf. de Viewport (mapeo al área de dibujo)
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

void drawCurrentCube(int indexCube, int position){
    if(indexCube==1){
        glutTexturedCube1(1, position);
    }else if(indexCube==2){
        glutTexturedCube2(1, position);
    }else if(indexCube==3){
        glutTexturedCube3(1, position);
    }else if(indexCube==4){
        glutTexturedCube4(1, position);
    }else if(indexCube==5){
        glutTexturedCube5(1, position);
    }else if(indexCube==6){
        glutTexturedCube6(1, position);
    }else if(indexCube==7){
        glutTexturedCube7(1, position);
    }else if(indexCube==8){
        glutTexturedCube8(1, position);
    }else if(indexCube==9){
        glutTexturedCube9(1, position);
    }else if(indexCube==10){
        glutTexturedCube10(1, position);
    }else if(indexCube==11){
        glutTexturedCube11(1, position);
    }else if(indexCube==12){
        glutTexturedCube12(1, position);
    }else if(indexCube==13){
        glutTexturedCube13(1, position);
    }else if(indexCube==14){
        glutTexturedCube14(1, position);
    }else if(indexCube==15){
        glutTexturedCube15(1, position);
    }else if(indexCube==16){
        glutTexturedCube16(1, position);
    }else if(indexCube==17){
        glutTexturedCube17(1, position);
    }else if(indexCube==18){
        glutTexturedCube18(1, position);
    }else if(indexCube==19){
        glutTexturedCube19(1, position);
    }else if(indexCube==20){
        glutTexturedCube20(1, position);
    }else if(indexCube==21){
        glutTexturedCube21(1, position);
    }else if(indexCube==22){
        glutTexturedCube22(1, position);
    }else if(indexCube==23){
        glutTexturedCube23(1, position);
    }else if(indexCube==24){
        glutTexturedCube24(1, position);
    }else if(indexCube==25){
        glutTexturedCube25(1, position);
    }else if(indexCube==26){
        glutTexturedCube26(1, position);
    }else if(indexCube==27){
        glutTexturedCube27(1, position);
    }
}

// Función que se invoca cada vez que se dibuja
void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se limpian los buffers con el color activo definido por glClearColor

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Transformación de vista
    glTranslatef(panX, panY, zoomZ);
    glRotatef(rotY, 1.0, 0.0, 0.0);
    glRotatef(rotX, 0.0, 1.0, 0.0);

    // Escena
    geomCoordSys(2.f);  


    //##############
    //      Pinta el primer nivel
    //##############


    //glutTexturedCube1(1);
    drawCurrentCube(idOfCubes[0],1);    

    glPushMatrix();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube2(1);
        drawCurrentCube(idOfCubes[1],2);        
        glTranslatef(spaceBetweenCubes,0.f,0.f);        
        //glutTexturedCube3(1);
        drawCurrentCube(idOfCubes[2],3);        
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.f,0.f,-spaceBetweenCubes);
        //glutTexturedCube4(1);     
        drawCurrentCube(idOfCubes[3],4);
        glTranslatef(spaceBetweenCubes,0.f,0.f);    
        //glutTexturedCube5(1);
        drawCurrentCube(idOfCubes[4],5);            
        glTranslatef(spaceBetweenCubes,0.f,0.f);        
        //glutTexturedCube6(1);
        drawCurrentCube(idOfCubes[5],6);            
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
        //glutTexturedCube7(1);
        drawCurrentCube(idOfCubes[6],7);    
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube8(1);
        drawCurrentCube(idOfCubes[7],8);    
        glTranslatef(spaceBetweenCubes,0.f,0.f);        
        //glutTexturedCube9(1);     
        drawCurrentCube(idOfCubes[8],9);    
    glPopMatrix();

    //##############
    //      Pinta el segundo nivel
    //##############
    glPushMatrix();
        glTranslatef(0.f, spaceBetweenCubes, 0.f);
        //glutTexturedCube10(1);
        drawCurrentCube(idOfCubes[9],10);   

        glPushMatrix();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube11(1);
            drawCurrentCube(idOfCubes[10],11);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);        
            //glutTexturedCube12(1);
            drawCurrentCube(idOfCubes[11],12);  
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes);
            //glutTexturedCube13(1);
            drawCurrentCube(idOfCubes[12],13);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube14(1);
            drawCurrentCube(idOfCubes[13],14);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);        
            //glutTexturedCube15(1);
            drawCurrentCube(idOfCubes[14],15);  
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
            //glutTexturedCube16(1);
            drawCurrentCube(idOfCubes[15],16);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube17(1);
            drawCurrentCube(idOfCubes[16],17);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);        
            //glutTexturedCube18(1);        
            drawCurrentCube(idOfCubes[17],18);  
        glPopMatrix();
        //##############
        //      Pinta el tercer nivel
        //##############
        glTranslatef(0.f, spaceBetweenCubes, 0.f);
        //glutTexturedCube19(1);
        drawCurrentCube(idOfCubes[18],19);  

        glPushMatrix();
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube20(1);
            drawCurrentCube(idOfCubes[19],20);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);        
            //glutTexturedCube21(1);
            drawCurrentCube(idOfCubes[20],21);  
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes);
            //glutTexturedCube22(1);
            drawCurrentCube(idOfCubes[21],22);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube23(1);
            drawCurrentCube(idOfCubes[22],23);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);        
            //glutTexturedCube24(1);
            drawCurrentCube(idOfCubes[23],24);  
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.f,0.f,-spaceBetweenCubes*2);
            //glutTexturedCube25(1);
            drawCurrentCube(idOfCubes[24],25);
            glTranslatef(spaceBetweenCubes,0.f,0.f);
            //glutTexturedCube26(1);
            drawCurrentCube(idOfCubes[25],26);  
            glTranslatef(spaceBetweenCubes,0.f,0.f);        
            //glutTexturedCube27(1);        
            drawCurrentCube(idOfCubes[26],27);  
        glPopMatrix();
    glPopMatrix();


    glutSwapBuffers();          // Se intercambian buffers
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

void specialKeyboard(int key, int x, int y)
{
    if(key == 1){
        // F1       
        rotateRight(true);
    }else if(key == 2){
        // F2
        rotateRight(false);
    }else if(key == 3){
        // F3       
        rotateLeft(true);
    }else if(key == 4){
        // F4
        rotateLeft(false);
    }else if(key == 5){
        // F5
        rotateFront(true);
    }else if(key == 6){
        // F6
        rotateFront(false);
    }else if(key == 7){
        // F7
        rotateBack(true);
    }else if(key == 8){
        // F8
        rotateBack(false);
    }else if(key == 9){
        // F9
        rotateUp(true);
    }else if(key == 10){
        // F10
        rotateUp(false);
    }else if(key == 11){
        // F11
        rotateDown(true);
    }else if(key == 12){
        // F12
        rotateDown(false);
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
    glutSpecialFunc(specialKeyboard);

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