#ifndef HSVCOLORRANGE_H
#define HSVCOLORRANGE_H

#include <opencv2/opencv.hpp>

using namespace cv;

class HSVColorRange
{
public:
    Scalar lowLimit;
    Scalar topLimit;
public:
    HSVColorRange(Scalar lowLimit, Scalar topLimit);
};

#endif // HSVCOLORRANGE_H
