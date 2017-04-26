#ifndef RUBIKPREVIEW_H
#define RUBIKPREVIEW_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <vector>
#include "hsvcolorrange.h"
#include "cvimagewidget.h"

using namespace std;

class RubikPreview : public QWidget
{
    Q_OBJECT

private:
    CVImageWidget *previewWidget;
    vector<Scalar> colors;
    Scalar invalidColor;

public:
    explicit RubikPreview(QWidget *parent = 0);
    void showFacePreview(vector<vector<int>> face);
    void setPreviewWidget(CVImageWidget *previewWidget);

};

#endif // RUBIKPREVIEW_H
