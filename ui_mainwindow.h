/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "scoreview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScore;
    QAction *actionStaff;
    QAction *actionOpen_LilyPond_file;
    QAction *actionExit;
    QAction *actionLilyPond;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    ScoreView *scoreView;
    QPushButton *addStaffButton;
    QPushButton *addNoteButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen;
    QMenu *menuExport;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1153, 744);
        actionScore = new QAction(MainWindow);
        actionScore->setObjectName(QStringLiteral("actionScore"));
        actionStaff = new QAction(MainWindow);
        actionStaff->setObjectName(QStringLiteral("actionStaff"));
        actionOpen_LilyPond_file = new QAction(MainWindow);
        actionOpen_LilyPond_file->setObjectName(QStringLiteral("actionOpen_LilyPond_file"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLilyPond = new QAction(MainWindow);
        actionLilyPond->setObjectName(QStringLiteral("actionLilyPond"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scoreView = new ScoreView(centralWidget);
        scoreView->setObjectName(QStringLiteral("scoreView"));
        scoreView->setMinimumSize(QSize(0, 0));
        scoreView->setFrameShape(QFrame::StyledPanel);
        scoreView->setFrameShadow(QFrame::Sunken);
        scoreView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        verticalLayout->addWidget(scoreView);

        addStaffButton = new QPushButton(centralWidget);
        addStaffButton->setObjectName(QStringLiteral("addStaffButton"));
        addStaffButton->setCheckable(false);
        addStaffButton->setAutoDefault(false);
        addStaffButton->setFlat(false);

        verticalLayout->addWidget(addStaffButton);

        addNoteButton = new QPushButton(centralWidget);
        addNoteButton->setObjectName(QStringLiteral("addNoteButton"));
        addNoteButton->setCheckable(false);

        verticalLayout->addWidget(addNoteButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1153, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuFile->addAction(actionExit);
        menuNew->addAction(actionScore);
        menuNew->addAction(actionStaff);
        menuOpen->addAction(actionOpen_LilyPond_file);
        menuExport->addAction(actionLilyPond);

        retranslateUi(MainWindow);

        addStaffButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionScore->setText(QApplication::translate("MainWindow", "Score", 0));
        actionStaff->setText(QApplication::translate("MainWindow", "Staff", 0));
        actionOpen_LilyPond_file->setText(QApplication::translate("MainWindow", "Open LilyPond file", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionLilyPond->setText(QApplication::translate("MainWindow", "LilyPond", 0));
        addStaffButton->setText(QApplication::translate("MainWindow", "Add Staff", 0));
        addNoteButton->setText(QApplication::translate("MainWindow", "Add Note", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "New", 0));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open", 0));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
