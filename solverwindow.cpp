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
