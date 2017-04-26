#ifndef SOLVERWINDOW_H
#define SOLVERWINDOW_H

#include <QMainWindow>

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
private slots:

    void on_scanNewCube_clicked();

    void on_exitButton_clicked();

private:
    Ui::SolverWindow *ui;
};

#endif // SOLVERWINDOW_H
