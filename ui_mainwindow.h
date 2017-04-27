/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalibrate_color_detection;
    QAction *actionChange_colors;
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *nextScannedFace;
    QPushButton *saveScannedFace;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QListWidget *facesListView;
    QSpacerItem *verticalSpacer_3;
    CVImageWidget *facesView;
    QPushButton *finishScan;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_2;
    CVImageWidget *OpenCVViewer;
    QMenuBar *menuBar;
    QMenu *menuCalibration;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(968, 541);
        MainWindow->setMinimumSize(QSize(0, 480));
        actionCalibrate_color_detection = new QAction(MainWindow);
        actionCalibrate_color_detection->setObjectName(QStringLiteral("actionCalibrate_color_detection"));
        actionChange_colors = new QAction(MainWindow);
        actionChange_colors->setObjectName(QStringLiteral("actionChange_colors"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(660, 0, 291, 471));
        gridLayout_2 = new QGridLayout(formLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        nextScannedFace = new QPushButton(formLayoutWidget);
        nextScannedFace->setObjectName(QStringLiteral("nextScannedFace"));

        gridLayout_2->addWidget(nextScannedFace, 12, 0, 1, 1);

        saveScannedFace = new QPushButton(formLayoutWidget);
        saveScannedFace->setObjectName(QStringLiteral("saveScannedFace"));
        saveScannedFace->setAutoDefault(false);
        saveScannedFace->setFlat(false);

        gridLayout_2->addWidget(saveScannedFace, 10, 0, 1, 1);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 0, 1, 1);

        facesListView = new QListWidget(formLayoutWidget);
        facesListView->setObjectName(QStringLiteral("facesListView"));

        gridLayout_2->addWidget(facesListView, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 6, 0, 1, 1);

        facesView = new CVImageWidget(formLayoutWidget);
        facesView->setObjectName(QStringLiteral("facesView"));
        facesView->setMinimumSize(QSize(130, 130));
        facesView->setMaximumSize(QSize(130, 130));

        gridLayout_2->addWidget(facesView, 2, 0, 1, 1, Qt::AlignHCenter);

        finishScan = new QPushButton(formLayoutWidget);
        finishScan->setObjectName(QStringLiteral("finishScan"));

        gridLayout_2->addWidget(finishScan, 13, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 7, 0, 1, 1);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        OpenCVViewer = new CVImageWidget(centralWidget);
        OpenCVViewer->setObjectName(QStringLiteral("OpenCVViewer"));
        OpenCVViewer->setGeometry(QRect(10, 0, 640, 480));
        OpenCVViewer->setMinimumSize(QSize(640, 480));
        OpenCVViewer->setMaximumSize(QSize(1280, 720));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 968, 25));
        menuCalibration = new QMenu(menuBar);
        menuCalibration->setObjectName(QStringLiteral("menuCalibration"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalibration->menuAction());
        menuCalibration->addSeparator();
        menuCalibration->addAction(actionCalibrate_color_detection);
        menuCalibration->addAction(actionChange_colors);

        retranslateUi(MainWindow);

        saveScannedFace->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Rubik Cube Scanner", Q_NULLPTR));
        actionCalibrate_color_detection->setText(QApplication::translate("MainWindow", "Calibrate color detection", Q_NULLPTR));
        actionChange_colors->setText(QApplication::translate("MainWindow", "Change colors", Q_NULLPTR));
        nextScannedFace->setText(QApplication::translate("MainWindow", "New Face", Q_NULLPTR));
        saveScannedFace->setText(QApplication::translate("MainWindow", "Save/Replace face ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Scanned face:", Q_NULLPTR));
        finishScan->setText(QApplication::translate("MainWindow", "Finish Scan", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Scanned faces:", Q_NULLPTR));
        menuCalibration->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
