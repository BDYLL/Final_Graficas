#include "solverwindow.h"
#include "ui_solverwindow.h"

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
