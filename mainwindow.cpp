#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->selectedFace = 0;
    vector<vector<int>> currentFace (3, vector<int>(3, -1));
    this->faces.push_back(currentFace);
    ui->facesListView->addItem("Face " + QString::number(1));

    this->faceScannedView = new RubikPreview();
    this->faceScannedView->setPreviewWidget(ui->facesView);
    this->faceScannedView->showFacePreview(currentFace);

    scanner = new RubikScanner();

    qRegisterMetaType<Mat>("Mat");
    QObject::connect(scanner, SIGNAL(videoStream(Mat)), this, SLOT(updatePlayerUI(Mat)));
    scanner->Play();

}

void MainWindow::updatePlayerUI(Mat img)
{
    ui->OpenCVViewer->showImage(img);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveScannedFace_clicked()
{
    vector<vector<int>> currentFace = scanner->getCurrentFace();
    this->faces[this->selectedFace] = currentFace;

    this->faceScannedView->showFacePreview(currentFace);

    //Reset items
    ui->facesListView->clear();
    // populate the items of the list
    for(int i = 0; i < faces.size(); i++)
    {
        ui->facesListView->addItem("Face " + QString::number(i + 1));
    }
}

void MainWindow::on_nextScannedFace_clicked()
{

    if(this->faces.size() < FACESLIMIT){
        vector<vector<int>> currentFace (3, vector<int>(3,-1));
        this->selectedFace = this->faces.size();
        this->faces.push_back(currentFace);
        ui->facesListView->addItem("Face " + QString::number(this->faces.size()));
        ui->facesListView->setCurrentRow(this->selectedFace);
        this->faceScannedView->showFacePreview(currentFace);
    }
}

void MainWindow::on_finishScan_clicked()
{
    openSolverWindow();
    this->close();
}

void MainWindow::openSolverWindow(){
    solverWindow = new SolverWindow();
    solverWindow->show();
}

void MainWindow::on_facesListView_clicked(const QModelIndex &index)
{
    this->selectedFace = index.row();
    this->faceScannedView->showFacePreview(this->faces[index.row()]);
    cout << "Face: " << index.row() << endl;
}
