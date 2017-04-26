#ifndef RUBIKSCANNER_H
#define RUBIKSCANNER_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <vector>
#include "hsvcolorrange.h"

using namespace cv;
using namespace std;

class RubikScanner : public QThread
{
    Q_OBJECT

private:
    bool stop;
    Mat drawUISquares(int v_height, int v_width, int quad_size, int quad_distance);
    Mat drawHudCube(Mat imgOriginal, int result[][3], vector<Scalar> colors, Scalar invalid_color, int size);
    int identifyColor( Mat img, vector<HSVColorRange> ranges);
    int identified_colors[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

private:
    void identifyCubeColors(Mat imgOriginal, int results[][3], int quad_size, int quad_distance);
    vector<HSVColorRange > colorRanges;
    vector<Scalar> expectedColors;
    Scalar invalidColor;
signals:
//Signal to output frame to be displayed
    void videoStream(Mat view);

protected:
    void run();

public:
    RubikScanner(QObject *parent = 0);
    vector<vector<int>> getCurrentFace();
    void Play();
    ~RubikScanner();

};

#endif // RUBIKSCANNER_H
