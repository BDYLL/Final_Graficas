/********************************************************************************
** Form generated from reading UI file 'solverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLVERWINDOW_H
#define UI_SOLVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "openglcontext.h"

QT_BEGIN_NAMESPACE

class Ui_SolverWindow
{
public:
    QAction *actionSave_File;
    QAction *actionSave_Solution_to_File;
    QAction *actionOpen_Solution_from_File;
    QWidget *centralwidget;
    OpenGLContext *openGLViewer;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *scanNewCube;
    QPushButton *exitButton;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SolverWindow)
    {
        if (SolverWindow->objectName().isEmpty())
            SolverWindow->setObjectName(QStringLiteral("SolverWindow"));
        SolverWindow->resize(800, 685);
        actionSave_File = new QAction(SolverWindow);
        actionSave_File->setObjectName(QStringLiteral("actionSave_File"));
        actionSave_Solution_to_File = new QAction(SolverWindow);
        actionSave_Solution_to_File->setObjectName(QStringLiteral("actionSave_Solution_to_File"));
        actionOpen_Solution_from_File = new QAction(SolverWindow);
        actionOpen_Solution_from_File->setObjectName(QStringLiteral("actionOpen_Solution_from_File"));
        centralwidget = new QWidget(SolverWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        openGLViewer = new OpenGLContext(centralwidget);
        openGLViewer->setObjectName(QStringLiteral("openGLViewer"));
        openGLViewer->setGeometry(QRect(0, 0, 801, 431));
        openGLViewer->setFocusPolicy(Qt::ClickFocus);
        openGLViewer->setAcceptDrops(true);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 430, 801, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        scanNewCube = new QPushButton(gridLayoutWidget);
        scanNewCube->setObjectName(QStringLiteral("scanNewCube"));

        horizontalLayout_3->addWidget(scanNewCube);

        exitButton = new QPushButton(gridLayoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout_3->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 4, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 4, 0, 1, 1);

        SolverWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SolverWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SolverWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SolverWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SolverWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave_Solution_to_File);
        menuFile->addAction(actionOpen_Solution_from_File);

        retranslateUi(SolverWindow);

        QMetaObject::connectSlotsByName(SolverWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SolverWindow)
    {
        SolverWindow->setWindowTitle(QApplication::translate("SolverWindow", "Rubik Cube Solution", Q_NULLPTR));
        actionSave_File->setText(QApplication::translate("SolverWindow", "Save File", Q_NULLPTR));
        actionSave_Solution_to_File->setText(QApplication::translate("SolverWindow", "Save Solution to File", Q_NULLPTR));
        actionOpen_Solution_from_File->setText(QApplication::translate("SolverWindow", "Open Solution from File", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SolverWindow", "Back", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SolverWindow", "Forward", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("SolverWindow", "Auto", Q_NULLPTR));
        label_3->setText(QApplication::translate("SolverWindow", "Step 0/0", Q_NULLPTR));
        scanNewCube->setText(QApplication::translate("SolverWindow", "Scan new cube", Q_NULLPTR));
        exitButton->setText(QApplication::translate("SolverWindow", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("SolverWindow", "Steps: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("SolverWindow", "Steps Controls:", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SolverWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SolverWindow: public Ui_SolverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVERWINDOW_H
