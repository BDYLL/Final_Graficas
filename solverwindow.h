#ifndef SOLVERWINDOW_H
#define SOLVERWINDOW_H

#include <QMainWindow>
#include <vector>
#include "rubiksolveralgorithms.cpp"

using namespace std;

namespace Ui {
class SolverWindow;
}

class SolverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SolverWindow(QWidget *parent = 0);
    ~SolverWindow();
signals:
    void restoreMainWindow();
public slots:
    void receiveCubeData(vector<vector<vector<int>>> faces);
private slots:
    void on_scanNewCube_clicked();
    void on_exitButton_clicked();
    void resolveRubikCube();

private:
    Ui::SolverWindow *ui;
    vector<vector<vector<int>>> faces;
};

#endif // SOLVERWINDOW_H
