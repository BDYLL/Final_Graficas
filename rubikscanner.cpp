#include "rubikscanner.h"

RubikScanner::RubikScanner(QObject *parent) :QThread(parent)
{
    this->stopped = false;

    HSVColorRange orangeRange (Scalar(7, 60, 130), Scalar(22, 255, 255));
    HSVColorRange yellowRange (Scalar(22, 60, 130), Scalar(38, 255, 255));
    HSVColorRange greenRange (Scalar(38, 80, 80), Scalar(100, 255, 180));
    HSVColorRange blueRange (Scalar(100, 70, 80), Scalar(130, 255, 255));
    HSVColorRange redRange (Scalar(160, 0, 0), Scalar(179, 255, 255));
    HSVColorRange whiteRange (Scalar(0, 0, 180), Scalar(255, 70, 255));

    Scalar orange (51, 150, 255);
    Scalar yellow (0, 255, 255);
    Scalar green (0, 255, 0);
    Scalar blue (255, 0, 0);
    Scalar red (0, 0, 255);
    Scalar white (255,255,255);

    this->expectedColors = {orange, yellow, green, blue, red, white};
    this->colorRanges = {orangeRange, yellowRange, greenRange, blueRange, redRange, whiteRange};
    this->invalidColor = Scalar(83, 87, 85);
}

void RubikScanner::Play()
{

    start(LowPriority);

}

void RubikScanner::run(){
    VideoCapture cap(0);
    this->cap_p = &cap;

    this->stopped = false;

    if(!cap.isOpened()){
        cout << "Cannot open the web cam" << endl;
    }

    Mat imgOriginal;
    Mat view;

    bool bSuccess = cap.read(imgOriginal); // read a new frame from video

    if (!bSuccess && !this->stopped ) //if not success, break loop
    {
        cout << "Cannot read a frame from video stream" << endl;
    }

    //My cam source size: 480X640 (height, width)
    int quad_size = 40;
    int quad_distance = 45;
    int v_height = imgOriginal.rows;
    int v_width = imgOriginal.cols;    
    int start_x = v_width/2 - quad_size/2;
    int start_y = v_height/2 - quad_size/2;

    Mat quadReferences = drawUISquares(v_height, v_width, quad_size, quad_distance);
    imgOriginal = drawHudCube(imgOriginal, this->identified_colors, this->expectedColors, this->invalidColor, 30);
    /*=================== Calibration code ======================== */
    /*

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    int iLowH = 0;
    int iHighH = 179;

    int iLowS = 0;
    int iHighS = 255;

    int iLowV = 0;
    int iHighV = 255;

    //Create trackbars in "Control" window
    cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    cvCreateTrackbar("HighH", "Control", &iHighH, 179);

    cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    cvCreateTrackbar("HighS", "Control", &iHighS, 255);

    cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    cvCreateTrackbar("HighV", "Control", &iHighV, 255);
    /*============================================================= */


    cout << "Scanning cube, dude!" << endl;

    while (bSuccess)
    {

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        //Identify colors
        identifyCubeColors(imgOriginal, this->identified_colors, quad_size, quad_distance);
        //Update HUD
        imgOriginal = drawHudCube(imgOriginal, this->identified_colors, this->expectedColors, this->invalidColor, 30);
        //Update View
        view = imgOriginal + quadReferences;

        emit videoStream(view);  //show the original image and the UI

        /* ================================================================= */
        /*

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

        //morphological opening (remove small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        //morphological closing (fill small holes in the foreground)
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        imshow("Thresholded Image", imgThresholded); //show the thresholded image
        /* ================================================================= */

        //Mat quad (imgOriginal, Rect(v_width/2, v_height/2, quad_size, quad_size));
        //imshow("Cuadrito", quad);

    }

    cap.release();

}

int RubikScanner::identifyColor(Mat img, vector<HSVColorRange> ranges){
    Mat imgHSV;
    Mat imgThresholded;
    int max_blop = 0;
    int color = -1;
    int current_blop_size = 0;

    cvtColor(img, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    Mat M(img.rows, img.cols, CV_THRESH_BINARY, Scalar(255));

    for(int i = 0; i < ranges.size(); i++){
        inRange(imgHSV, ranges[i].lowLimit , ranges[i].topLimit, imgThresholded); //Threshold the image

        current_blop_size = sum(imgThresholded / M)[0];

        if(current_blop_size > max_blop){
            max_blop = current_blop_size;
            color = i;
        }
    }
    return color;
}

void RubikScanner:: identifyCubeColors(Mat imgOriginal, int results[][3], int quad_size, int quad_distance){
    int start_x = imgOriginal.cols/2 - quad_size/2;
    int start_y = imgOriginal.rows/2 - quad_size/2;

    //Center Quad
    Mat quad (imgOriginal, Rect(start_x, start_y, quad_size, quad_size));
    results [1][1] = identifyColor(quad, this->colorRanges);
    //Left Quad
    Mat quadLeft(imgOriginal, Rect(start_x - quad_distance - quad_size/2, start_y, quad_size, quad_size));
    results [1][0] = identifyColor(quadLeft, this->colorRanges);
    //Right Quad
    Mat quadRight (imgOriginal,Rect(start_x + quad_distance + quad_size/2, start_y, quad_size, quad_size));
    results [1][2] = identifyColor(quadRight, this->colorRanges);
    //Upper Quad
    Mat quadUpper (imgOriginal,Rect(start_x, start_y + quad_distance + quad_size/2, quad_size, quad_size));
    results [0][1] = identifyColor(quadUpper, this->colorRanges);
    //Lower Quad
    Mat quadLower (imgOriginal, Rect(start_x, start_y - quad_distance - quad_size/2, quad_size, quad_size));
    results [2][1] = identifyColor(quadLower, this->colorRanges);
    //Upper-left Quad
    Mat quadUpLt (imgOriginal, Rect(start_x - quad_distance - quad_size/2, start_y + quad_distance + quad_size/2, quad_size, quad_size));
    results [0][0] = identifyColor(quadUpLt, this->colorRanges);
    //Upper-right Quad
    Mat quadUpRt (imgOriginal, Rect(start_x + quad_distance + quad_size/2, start_y + quad_distance + quad_size/2, quad_size, quad_size));
    results [0][2] = identifyColor(quadUpRt, this->colorRanges);
    //Lower-left Quad
    Mat quadLoLt (imgOriginal, Rect(start_x - quad_distance - quad_size/2, start_y - quad_distance - quad_size/2, quad_size, quad_size));
    results [2][0] = identifyColor(quadLoLt, this->colorRanges);
    //Lower-right Quad
    Mat quadLoRt (imgOriginal, Rect(start_x + quad_distance + quad_size/2, start_y - quad_distance - quad_size/2, quad_size, quad_size));
    results [2][2] = identifyColor(quadLoRt, this->colorRanges);

}

Mat RubikScanner::drawUISquares(int v_height, int v_width, int quad_size, int quad_distance){


    Mat quadReferences = Mat::ones(v_height, v_width, CV_8UC3);
    Scalar color_quad = Scalar(0, 255, 0);

    int start_x = v_width/2 - quad_size/2;
    int start_y = v_height/2 - quad_size/2;

    //Create quad references for video
    quadReferences = Mat::ones(v_height, v_width, CV_8UC3);
    //Center Quad
    Rect quadCenter = Rect(start_x, start_y, quad_size, quad_size);
    rectangle(quadReferences, quadCenter, color_quad, +2, 4);
    //Left Quad
    Rect quadLeft = Rect(start_x - quad_distance - quad_size/2, start_y, quad_size, quad_size);
    rectangle(quadReferences, quadLeft, color_quad, +2, 4);
    //Right Quad
    Rect quadRight = Rect(start_x + quad_distance + quad_size/2, start_y, quad_size, quad_size);
    rectangle(quadReferences, quadRight, color_quad, +2, 4);
    //Upper Quad
    Rect quadUpper = Rect(start_x, start_y + quad_distance + quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadUpper, color_quad, +2, 4);
    //Lower Quad
    Rect quadLower = Rect(start_x, start_y - quad_distance - quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadLower, color_quad, +2, 4);
    //Upper-left Quad
    Rect quadUpLt = Rect(start_x - quad_distance - quad_size/2, start_y + quad_distance + quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadUpLt, color_quad, +2, 4);
    //Upper-right Quad
    Rect quadUpRt = Rect(start_x + quad_distance + quad_size/2, start_y + quad_distance + quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadUpRt, color_quad, +2, 4);
    //Lower-left Quad
    Rect quadLoLt = Rect(start_x - quad_distance - quad_size/2, start_y - quad_distance - quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadLoLt, color_quad, +2, 4);
    //Lower-right Quad
    Rect quadLoRt = Rect(start_x + quad_distance + quad_size/2, start_y - quad_distance - quad_size/2, quad_size, quad_size);
    rectangle(quadReferences, quadLoRt, color_quad, +2, 4);

    return quadReferences;

}

Mat RubikScanner::drawHudCube(Mat imgOriginal, int result[][3], vector<Scalar> colors, Scalar invalid_color, int size){
     Mat hudCube = imgOriginal;

     int start_x = 5 + size;
     int start_y = start_x;
     Scalar color_quad;

     //Center Quad
      Rect quadCenter = Rect(start_x, start_y, size, size);
      color_quad = (result[1][1] != -1)? colors[result[1][1]] : invalid_color;
      rectangle(hudCube, quadCenter, color_quad, CV_FILLED, 4);
      //Left Quad
      Rect quadLeft = Rect(start_x - size, start_y, size, size);
      color_quad = (result[1][0] != -1)? colors[result[1][0]] : invalid_color;
      rectangle(hudCube, quadLeft, color_quad, CV_FILLED, 4);
      //Right Quad
      Rect quadRight = Rect(start_x + size, start_y, size, size);
      color_quad = (result[1][2] != -1)? colors[result[1][2]] : invalid_color;
      rectangle(hudCube, quadRight, color_quad, CV_FILLED, 4);
      //Upper Quad
      Rect quadUpper = Rect(start_x, start_y + size, size, size);
      color_quad = (result[0][1] != -1)? colors[result[0][1]] : invalid_color;
      rectangle(hudCube, quadUpper, color_quad, CV_FILLED, 4);
      //Lower Quad
      Rect quadLower = Rect(start_x, start_y - size, size, size);
      color_quad = (result[2][1] != -1)? colors[result[2][1]] : invalid_color;
      rectangle(hudCube, quadLower, color_quad, CV_FILLED, 4);
      //Upper-left Quad
      Rect quadUpLt = Rect(start_x - size, start_y + size, size, size);
      color_quad = (result[0][0] != -1)? colors[result[0][0]] : invalid_color;
      rectangle(hudCube, quadUpLt, color_quad, CV_FILLED, 4);
      //Upper-right Quad
      Rect quadUpRt = Rect(start_x + size, start_y + size, size, size);
      color_quad = (result[0][2] != -1)? colors[result[0][2]] : invalid_color;
      rectangle(hudCube, quadUpRt, color_quad, CV_FILLED, 4);
      //Lower-left Quad
      Rect quadLoLt = Rect(start_x - size, start_y - size, size, size);
      color_quad = (result[2][0] != -1)? colors[result[2][0]] : invalid_color;
      rectangle(hudCube, quadLoLt, color_quad, CV_FILLED, 4);
      //Lower-right Quad
      Rect quadLoRt = Rect(start_x + size, start_y - size, size, size);
      color_quad = (result[2][2] != -1)? colors[result[2][2]] : invalid_color;
      rectangle(hudCube, quadLoRt, color_quad, CV_FILLED, 4);

     return hudCube;
}

vector<vector<int>> RubikScanner::getCurrentFace(){
    vector<vector<int>> currentFace(3, vector<int>(3));

    for (int r = 0; r < 3 ; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            currentFace[r][c] =  this->identified_colors[r][c];
        }
    }

    return currentFace;
}


void RubikScanner::Stop(){
    this->stopped = true;
    this->cap_p->release();
    cout << "Stopping camera..." << endl;
}


RubikScanner::~RubikScanner(){}
