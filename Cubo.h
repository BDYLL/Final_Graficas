#ifndef CUBO_H
#define CUBO_H

#include <GL/glew.h>
#include <GL/freeglut.h>

class Cube {
    GLfloat color[108];
    float rotX =0;
    float rotY =0;
    float rotZ =0;

    GLfloat vert[108] = {
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

    GLushort idxs[36] = {
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
    float get_rotX();
    float get_rotY();
    float get_rotZ();
    void paint () {
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, color);
        glVertexPointer(3, GL_FLOAT, 0, vert);

        glPushMatrix();
        glRotatef(rotX, 1.0, 0.0, 0.0);
        glRotatef(rotY, 0.0, 1.0, 0.0);
        glRotatef(rotZ, 0.0, 0.0, 1.0);        
        glColor4f(1, 1, 1, 1);
        glScaled(1, 1, 1);
        glDrawElements(GL_TRIANGLES, sizeof(idxs)/sizeof(idxs[0]), GL_UNSIGNED_SHORT, idxs);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    void set_rots (float rX, float rY, float rZ);
    void increase_rots (float rX, float rY, float rZ);
};

#endif