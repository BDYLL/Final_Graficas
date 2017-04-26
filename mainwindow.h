#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cvimagewidget.h>
#include <rubikscanner.h>
#include <rubikpreview.h>
#include <opencv2/opencv.hpp>
#include <solverwindow.h>
#include <vector>

#define FACESLIMIT 6

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openSolverWindow();
    void restoreWindow();

private slots:
    //Display video frame in player UI
    void updatePlayerUI(Mat img);
    void on_saveScannedFace_clicked();
    void on_nextScannedFace_clicked();
    void on_finishScan_clicked();

    void on_facesListView_clicked(const QModelIndex &index);

public:
    vector<vector<vector<int>>> faces;

private:
    Ui::MainWindow *ui;
    SolverWindow *solverWindow;
    RubikScanner *scanner;
    RubikPreview * faceScannedView;
    int selectedFace;
    int countFaces;

};

#endif // MAINWINDOW_H
