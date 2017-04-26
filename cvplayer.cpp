#include "cvplayer.h"

using namespace cv;
using namespace std;

CVPlayer::CVPlayer(QObject *parent)
 : QThread(parent)
{
    VideoCapture cap(0);

    if(!cap.isOpened()){
        cout << "Cannot open the web cam" << endl;
    }


    Mat imgOriginal;
    Mat quadReferences;
    Mat view;

    bool bSuccess = cap.read(imgOriginal); // read a new frame from video

    if (!bSuccess) //if not success, break loop
    {
        cout << "Cannot read a frame from video stream" << endl;
    }

    //My cam source size: 480X640 (height, width)
    int v_height = imgOriginal.rows;
    int v_width = imgOriginal.cols;
    int quad_size = 20;
    int quad_distance = 60;

    Scalar color_quad = Scalar(0, 255, 0);

    //Create quad references for video
    quadReferences = Mat::ones(v_height, v_width, CV_8UC3);
    //Center Quad
    Rect quadCenter = Rect(v_width/2, v_height/2, quad_size, quad_size);
    rectangle(quadReferences, quadCenter, color_quad, +2, 4);

    //Left Quad
    Rect quadLeft = Rect(v_width/2 - quad_distance - quad_size/2, v_height/2, quad_size, quad_size);
    rectangle(quadReferences, quadLeft, color_quad, +2, 4);
    //Right Quad
    Rect quadRight = Rect(v_width/2 + quad_distance + quad_size/2, v_height/2, quad_size, quad_size);
    rectangle(quadReferences, quadRight, color_quad, +2, 4);
    //Upper Quad
    Rect quadUpper = Rect(v_width/2, v_height/2 + quad_distance + quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadUpper, color_quad, +2, 4);
    //Lower Quad
    Rect quadLower = Rect(v_width/2, v_height/2 - quad_distance - quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadLower, color_quad, +2, 4);
    //Upper-left Quad
    Rect quadUpLt = Rect(v_width/2 - quad_distance - quad_size/2, v_height/2 + quad_distance + quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadUpLt, color_quad, +2, 4);
    //Upper-right Quad
    Rect quadUpRt = Rect(v_width/2 + quad_distance + quad_size/2, v_height/2 + quad_distance + quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadUpRt, color_quad, +2, 4);
    //Lower-left Quad
    Rect quadLoLt = Rect(v_width/2 - quad_distance - quad_size/2, v_height/2 - quad_distance - quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadLoLt, color_quad, +2, 4);
    //Lower-right Quad
    Rect quadLoRt = Rect(v_width/2 + quad_distance + quad_size/2, v_height/2 - quad_distance - quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadLoRt, color_quad, +2, 4);


    while (bSuccess)
    {

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        //Clone the video Source to put the UI
        //imgUI = imgOriginal.clone();
        //BGR
        //rectangle( imgOriginal, Point( 15, 20 ), Point( 70, 50), Scalar( 0, 255, 0 ), +2, 4 );
        view = imgOriginal + quadReferences;



        imshow("Original", view); //show the original image and the UI

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
}
