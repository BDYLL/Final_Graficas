#ifndef CQTOPENCVVIEWERGL_H
#define CQTOPENCVVIEWERGL_H

#include <QWidget>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
class CQtOpenCVViewerGl : public QWidget
{
    Q_OBJECT
public:
    explicit CQtOpenCVViewerGl(QWidget *parent = 0);

signals:

public slots:
};

#endif // CQTOPENCVVIEWERGL_H
