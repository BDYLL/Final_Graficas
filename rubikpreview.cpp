#include "rubikpreview.h"

RubikPreview::RubikPreview(QWidget *parent): QWidget(parent)
{
    Scalar orange (51, 150, 255);
    Scalar yellow (0, 255, 255);
    Scalar green (0, 255, 0);
    Scalar blue (255, 0, 0);
    Scalar red (0, 0, 255);
    Scalar white (255,255,255);

    this->colors = {orange, yellow, green, blue, red, white};
    this->invalidColor = Scalar(83, 87, 85);

    cout << "Creating object.." << endl;
}

void RubikPreview::showFacePreview(vector<vector<int> > face){
    Mat hudCube = Mat::zeros(this->previewWidget->height(),this->previewWidget->width(), CV_8UC3);
    int size = this->previewWidget->height() / 3;

    int start_x = this->previewWidget->width()/2 - size/2;
    int start_y = this->previewWidget->height()/2 - size/2;
    Scalar color_quad;

    cout << "Painting preview.." << endl;

    //Center Quad
    Rect quadCenter = Rect(start_x, start_y, size, size);
    color_quad = (face[1][1] != -1)? colors[face[1][1]] : invalidColor;
    rectangle(hudCube, quadCenter, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadCenter, invalidColor, 2, 4);
    //Left Quad
    Rect quadLeft = Rect(start_x - size, start_y, size, size);
    color_quad = (face[1][0] != -1)? colors[face[1][0]] : invalidColor;
    rectangle(hudCube, quadLeft, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadLeft, invalidColor, 2, 4);
    //Right Quad
    Rect quadRight = Rect(start_x + size, start_y, size, size);
    color_quad = (face[1][2] != -1)? colors[face[1][2]] : invalidColor;
    rectangle(hudCube, quadRight, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadRight, invalidColor, 2, 4);
    //Upper Quad
    Rect quadUpper = Rect(start_x, start_y + size, size, size);
    color_quad = (face[0][1] != -1)? colors[face[0][1]] : invalidColor;
    rectangle(hudCube, quadUpper, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadUpper, invalidColor, 2, 4);
    //Lower Quad
    Rect quadLower = Rect(start_x, start_y - size, size, size);
    color_quad = (face[2][1] != -1)? colors[face[2][1]] : invalidColor;
    rectangle(hudCube, quadLower, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadLower, invalidColor, 2, 4);
    //Upper-left Quad
    Rect quadUpLt = Rect(start_x - size, start_y + size, size, size);
    color_quad = (face[0][0] != -1)? colors[face[0][0]] : invalidColor;
    rectangle(hudCube, quadUpLt, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadUpLt, invalidColor, 2, 4);
    //Upper-right Quad
    Rect quadUpRt = Rect(start_x + size, start_y + size, size, size);
    color_quad = (face[0][2] != -1)? colors[face[0][2]] : invalidColor;
    rectangle(hudCube, quadUpRt, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadUpRt, invalidColor, 2, 4);
    //Lower-left Quad
    Rect quadLoLt = Rect(start_x - size, start_y - size, size, size);
    color_quad = (face[2][0] != -1)? colors[face[2][0]] : invalidColor;
    rectangle(hudCube, quadLoLt, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadLoLt, invalidColor, 2, 4);
    //Lower-right Quad
    Rect quadLoRt = Rect(start_x + size, start_y - size, size, size);
    color_quad = (face[2][2] != -1)? colors[face[2][2]] : invalidColor;
    rectangle(hudCube, quadLoRt, color_quad, CV_FILLED, 4);
    rectangle(hudCube, quadLoRt, invalidColor, 2, 4);

    cout << "Almost done..." << endl;

    this->previewWidget->showImage(hudCube);
    cout << "Done!" << endl;

}

void RubikPreview::setPreviewWidget(CVImageWidget *previewWidget){
    this->previewWidget = previewWidget;
}

