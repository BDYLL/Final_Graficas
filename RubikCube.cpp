#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>

#include <vector>
#include "Cubo.h"

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

// Cube rubikCube[27];
std::vector<Cube> rubikCube;
rubikCube.resize(27);

/*
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

*/


void rotateRight(bool clockWise){
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
    }
}

void rotateLeft(bool clockWise){
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
    }
}

void rotateFront(bool clockWise){
    if(clockWise){      
        Cube tmp1 = rubikCube[3];
        Cube tmp2 = rubikCube[6];
        Cube tmp3 = rubikCube[15];
        Cube tmp4 = rubikCube[24];

        rubikCube[6]  = rubikCube[0];
        rubikCube[3]  = rubikCube[9];
        rubikCube[0]  = rubikCube[18];
        rubikCube[15]  = tmp1;
        rubikCube[10] = rubikCube[10];
        rubikCube[9] = rubikCube[21];       
        rubikCube[24] = tmp2;
        rubikCube[21] = tmp3;
        rubikCube[18] = tmp4;
    }else{
        Cube tmp1 = rubikCube[6];
        Cube tmp2 = rubikCube[3];
        Cube tmp3 = rubikCube[9];
        Cube tmp4 = rubikCube[0];

        rubikCube[6]  = rubikCube[24];
        rubikCube[3]  = rubikCube[15];
        rubikCube[0]  = tmp1;
        rubikCube[15]  = rubikCube[21];
        rubikCube[10] = rubikCube[10];
        rubikCube[9] = tmp2;
        rubikCube[24] = rubikCube[18];
        rubikCube[21] = tmp3;
        rubikCube[18] = tmp4;       
    }
}

void rotateBack(bool clockWise){
    if(clockWise){      
        Cube tmp1 = rubikCube[5];
        Cube tmp2 = rubikCube[2];
        Cube tmp3 = rubikCube[11];
        Cube tmp4 = rubikCube[20];

        rubikCube[2]  = rubikCube[8];
        rubikCube[5]  = rubikCube[17];
        rubikCube[8]  = rubikCube[26];
        rubikCube[11]  = tmp1;
        rubikCube[14] = rubikCube[14];
        rubikCube[17] = rubikCube[23];      
        rubikCube[20] = tmp2;
        rubikCube[23] = tmp3;
        rubikCube[26] = tmp4;
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
    }
}

void rotateUp(bool clockWise){
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
    }
}

void rotateDown(bool clockWise){
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

	GLfloat colorRed[]    = {1.0,   0,   0 };
	GLfloat colorGreen[]  = {  0, 1.0,   0 };
	GLfloat colorBlue[]   = {  0,   0, 1.0 };
	GLfloat colorOrange[] = {1.0, 0.5, 0.18};
	GLfloat colorYellow[] = {1.0, 1.0,   0 };
	GLfloat colorWhite[]  = {1.0, 1.0, 1.0 };
	GLfloat colorBlack[]  = {  0,   0,   0 };

	rubikCube[0] = Cube(colorRed, colorBlack, colorBlack, colorBlue, colorWhite,colorBlack, 0.0, 0.0, 0.0);	
	rubikCube[1] = Cube(colorRed, colorBlack, colorBlack, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[2] = Cube(colorRed, colorBlack, colorGreen, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[3] = Cube(colorBlack, colorBlack, colorBlack, colorBlue, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[4] = Cube(colorBlack, colorBlack, colorBlack, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[5] = Cube(colorBlack, colorBlack, colorGreen, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[6] = Cube(colorBlack, colorOrange, colorBlack, colorBlue, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[7] = Cube(colorBlack, colorOrange, colorBlack, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0);     
    rubikCube[8] = Cube(colorBlack, colorOrange, colorGreen, colorBlack, colorWhite,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[9] = Cube(colorRed, colorBlack, colorBlack, colorBlue, colorBlack,colorBlack, 0.0, 0.0, 0.0); 

    rubikCube[10] = Cube(colorRed, colorBlack, colorBlack, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[11] = Cube(colorRed, colorBlack, colorGreen, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[12] = Cube(colorBlack, colorBlack, colorBlack, colorBlue, colorBlack,colorBlack, 0.0, 0.0, 0.0);
    rubikCube[13] = Cube(colorBlack, colorBlack, colorBlack, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0);
    rubikCube[14] = Cube(colorBlack, colorBlack, colorGreen, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[15] = Cube(colorBlack, colorOrange, colorBlack, colorBlue, colorBlack,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[16] = Cube(colorBlack, colorOrange, colorBlack, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[17] = Cube(colorBlack, colorOrange, colorGreen, colorBlack, colorBlack,colorBlack, 0.0, 0.0, 0.0); 
    rubikCube[18] = Cube(colorRed, colorBlack, colorBlack, colorBlue, colorBlack,colorYellow, 0.0, 0.0, 0.0);
    rubikCube[19] = Cube(colorRed, colorBlack, colorBlack, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0);

    rubikCube[20] = Cube(colorRed, colorBlack, colorGreen, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0); 
    rubikCube[21] = Cube(colorBlack, colorBlack, colorBlack, colorBlue, colorBlack,colorYellow, 0.0, 0.0, 0.0);
    rubikCube[22] = Cube(colorBlack, colorBlack, colorBlack, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0);
    rubikCube[23] = Cube(colorBlack, colorBlack, colorGreen, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0);
    rubikCube[24] = Cube(colorBlack, colorOrange, colorBlack, colorBlue, colorBlack,colorYellow, 0.0, 0.0, 0.0); 
    rubikCube[25] = Cube(colorBlack, colorOrange, colorBlack, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0);
    rubikCube[26] = Cube(colorBlack, colorOrange, colorGreen, colorBlack, colorBlack,colorYellow, 0.0, 0.0, 0.0);
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
    rubikCube[0].paint();

    glPushMatrix();
        glTranslatef(spaceBetweenCubes,0.f,0.f);
        //glutTexturedCube2(1);
        rubikCube[1].paint();
        glTranslatef(spaceBetweenCubes,0.f,0.f);        
        //glutTexturedCube3(1);
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

        //##############
        //      Pinta el tercer nivel
        //##############
        glTranslatef(0.f, spaceBetweenCubes, 0.f);
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