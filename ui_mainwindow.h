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
    QAction *actionOpen_LilyPond_file;
    QAction *actionExit;
    QAction *actionLilyPond;
    QAction *actionAddNote;
    QAction *actionAddRest;
    QAction *actionHalf;
    QAction *actionWhole;
    QAction *actionQuarter;
    QAction *actionEighth;
    QAction *action_newStaff;
    QAction *actionAddSharp;
    QAction *actionAddFlat;
    QAction *actionOpenLilypondToolBar;
    QAction *actionSaveLilypondToolBar;
    QAction *actionNewScore;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    ScoreView *scoreView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen;
    QMenu *menuExport;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1153, 744);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/half_note.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        actionScore = new QAction(MainWindow);
        actionScore->setObjectName(QStringLiteral("actionScore"));
        actionOpen_LilyPond_file = new QAction(MainWindow);
        actionOpen_LilyPond_file->setObjectName(QStringLiteral("actionOpen_LilyPond_file"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLilyPond = new QAction(MainWindow);
        actionLilyPond->setObjectName(QStringLiteral("actionLilyPond"));
        actionAddNote = new QAction(MainWindow);
        actionAddNote->setObjectName(QStringLiteral("actionAddNote"));
        actionAddNote->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/quarter_note.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddNote->setIcon(icon1);
        actionAddRest = new QAction(MainWindow);
        actionAddRest->setObjectName(QStringLiteral("actionAddRest"));
        actionAddRest->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/quarter_rest.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddRest->setIcon(icon2);
        actionHalf = new QAction(MainWindow);
        actionHalf->setObjectName(QStringLiteral("actionHalf"));
        actionHalf->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/half_note_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHalf->setIcon(icon3);
        actionWhole = new QAction(MainWindow);
        actionWhole->setObjectName(QStringLiteral("actionWhole"));
        actionWhole->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/res/whole_note_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWhole->setIcon(icon4);
        actionQuarter = new QAction(MainWindow);
        actionQuarter->setObjectName(QStringLiteral("actionQuarter"));
        actionQuarter->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/res/quarter_note_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuarter->setIcon(icon5);
        actionEighth = new QAction(MainWindow);
        actionEighth->setObjectName(QStringLiteral("actionEighth"));
        actionEighth->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/res/eighth_note_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEighth->setIcon(icon6);
        action_newStaff = new QAction(MainWindow);
        action_newStaff->setObjectName(QStringLiteral("action_newStaff"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("res/staff_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_newStaff->setIcon(icon7);
        actionAddSharp = new QAction(MainWindow);
        actionAddSharp->setObjectName(QStringLiteral("actionAddSharp"));
        actionAddSharp->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/res/sharp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddSharp->setIcon(icon8);
        actionAddFlat = new QAction(MainWindow);
        actionAddFlat->setObjectName(QStringLiteral("actionAddFlat"));
        actionAddFlat->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/res/flat.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddFlat->setIcon(icon9);
        actionOpenLilypondToolBar = new QAction(MainWindow);
        actionOpenLilypondToolBar->setObjectName(QStringLiteral("actionOpenLilypondToolBar"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("res/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenLilypondToolBar->setIcon(icon10);
        actionSaveLilypondToolBar = new QAction(MainWindow);
        actionSaveLilypondToolBar->setObjectName(QStringLiteral("actionSaveLilypondToolBar"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/res/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveLilypondToolBar->setIcon(icon11);
        actionNewScore = new QAction(MainWindow);
        actionNewScore->setObjectName(QStringLiteral("actionNewScore"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/res/new_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewScore->setIcon(icon12);
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
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuFile->addAction(actionExit);
        menuNew->addAction(actionScore);
        menuOpen->addAction(actionOpen_LilyPond_file);
        menuExport->addAction(actionLilyPond);
        mainToolBar->addAction(action_newStaff);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAddNote);
        mainToolBar->addAction(actionAddRest);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionWhole);
        mainToolBar->addAction(actionHalf);
        mainToolBar->addAction(actionQuarter);
        mainToolBar->addAction(actionEighth);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAddSharp);
        mainToolBar->addAction(actionAddFlat);
        mainToolBar->addSeparator();
        toolBar->addAction(actionNewScore);
        toolBar->addAction(actionOpenLilypondToolBar);
        toolBar->addAction(actionSaveLilypondToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ellenpont", 0));
        actionScore->setText(QApplication::translate("MainWindow", "Kotta", 0));
        actionOpen_LilyPond_file->setText(QApplication::translate("MainWindow", "LilyPond f\303\241jl megnyit\303\241sa", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Kil\303\251p\303\251s", 0));
        actionLilyPond->setText(QApplication::translate("MainWindow", "LilyPond", 0));
        actionAddNote->setText(QApplication::translate("MainWindow", "\303\232j Hangjegy", 0));
        actionAddRest->setText(QApplication::translate("MainWindow", "\303\232j Sz\303\274net", 0));
        actionHalf->setText(QApplication::translate("MainWindow", "F\303\251l", 0));
        actionWhole->setText(QApplication::translate("MainWindow", "Eg\303\251sz", 0));
        actionQuarter->setText(QApplication::translate("MainWindow", "Negyed", 0));
        actionEighth->setText(QApplication::translate("MainWindow", "Nyolcad", 0));
        action_newStaff->setText(QApplication::translate("MainWindow", "\303\232j kottasor", 0));
        actionAddSharp->setText(QApplication::translate("MainWindow", "Kereszt hozz\303\241ad\303\241sa", 0));
        actionAddFlat->setText(QApplication::translate("MainWindow", "B hozz\303\241ad\303\241sa", 0));
        actionOpenLilypondToolBar->setText(QApplication::translate("MainWindow", "LilyPond f\303\241jl megnyit\303\241sa", 0));
        actionSaveLilypondToolBar->setText(QApplication::translate("MainWindow", "Kotta ment\303\251se", 0));
        actionNewScore->setText(QApplication::translate("MainWindow", "\303\232j kotta", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "F\303\241jl", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "\303\232j", 0));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Megnyit\303\241s", 0));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
