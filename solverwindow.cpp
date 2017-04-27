#include "solverwindow.h"
#include "ui_solverwindow.h"
#include <QDir>

using namespace std;

SolverWindow::SolverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolverWindow)
{
    ui->setupUi(this);
}

SolverWindow::~SolverWindow()
{
    delete ui;
}


void SolverWindow::on_scanNewCube_clicked()
{
    emit restoreMainWindow();
    this->close();
}

void SolverWindow::on_exitButton_clicked()
{
    this->close();
}

void SolverWindow::receiveCubeData(vector<vector<vector<int>>> faces){
    this->faces = faces;
    cout << "Faces: " << this->faces.size() << endl;

    resolveRubikCube();
}

void SolverWindow::resolveRubikCube(){
    vector <string> v ({"FL" ,"RB" ,"LB" ,"LD" ,"DB" ,"DF" ,"DR","UR" ,"UB" ,"FU" ,"UL" ,"FR" ,"FRU" ,"BRD" ,"ULF" ,"BUR" ,"LBD" ,"DRF" ,"BLU" ,"DFL"});
    QString path = QDir::currentPath();
    cout << path.toStdString() <<endl;

    mixedMethod(v.size(), v);
}
