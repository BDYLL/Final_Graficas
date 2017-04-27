#include "Cubo.h"
#include <iostream>

Cube::Cube (GLfloat* color1, GLfloat* color2, GLfloat* color3,
            GLfloat* color4,GLfloat* color5, GLfloat* color6, float rX, float rY, float rZ) {
    rotX = rX;
    rotY = rY;
    rotZ = rZ;

    GLfloat tmp[] = {
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
        color6[0], color6[1], color6[2]
    };

    std::copy(std::begin(tmp),std::end(tmp),std::begin(color));

}

void Cube::set_colors (GLfloat* color1, GLfloat* color2, GLfloat* color3,
                    GLfloat* color4,GLfloat* color5, GLfloat* color6) {
    GLfloat tmp[] = {
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

    std::copy(std::begin(tmp),std::end(tmp),std::begin(color));

}

void Cube::set_rots (float rX, float rY, float rZ) {
    rotX = rX;
    rotY = rY;
    rotZ = rZ;
}