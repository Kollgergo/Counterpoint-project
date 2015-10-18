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
    QAction *actionExit;
    QAction *actionAddNote;
    QAction *actionAddRest;
    QAction *actionHalf;
    QAction *actionWhole;
    QAction *actionQuarter;
    QAction *actionEighth;
    QAction *actionAddSharp;
    QAction *actionAddFlat;
    QAction *actionNewScore;
    QAction *actionNewCounterpoint;
    QAction *actionChangeNoteRest;
    QAction *actionOpenLilypond;
    QAction *actionSaveLilypond;
    QAction *actionTest;
    QAction *actionNewStaff;
    QAction *actionPlayMIDI;
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
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
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
        actionAddSharp = new QAction(MainWindow);
        actionAddSharp->setObjectName(QStringLiteral("actionAddSharp"));
        actionAddSharp->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/res/sharp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddSharp->setIcon(icon7);
        actionAddFlat = new QAction(MainWindow);
        actionAddFlat->setObjectName(QStringLiteral("actionAddFlat"));
        actionAddFlat->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/res/flat.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddFlat->setIcon(icon8);
        actionNewScore = new QAction(MainWindow);
        actionNewScore->setObjectName(QStringLiteral("actionNewScore"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/res/new_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewScore->setIcon(icon9);
        actionNewCounterpoint = new QAction(MainWindow);
        actionNewCounterpoint->setObjectName(QStringLiteral("actionNewCounterpoint"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/res/CP_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewCounterpoint->setIcon(icon10);
        actionChangeNoteRest = new QAction(MainWindow);
        actionChangeNoteRest->setObjectName(QStringLiteral("actionChangeNoteRest"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/res/changeicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangeNoteRest->setIcon(icon11);
        actionOpenLilypond = new QAction(MainWindow);
        actionOpenLilypond->setObjectName(QStringLiteral("actionOpenLilypond"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/res/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenLilypond->setIcon(icon12);
        actionSaveLilypond = new QAction(MainWindow);
        actionSaveLilypond->setObjectName(QStringLiteral("actionSaveLilypond"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/res/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveLilypond->setIcon(icon13);
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/res/test_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTest->setIcon(icon14);
        actionNewStaff = new QAction(MainWindow);
        actionNewStaff->setObjectName(QStringLiteral("actionNewStaff"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/res/staff_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewStaff->setIcon(icon15);
        actionPlayMIDI = new QAction(MainWindow);
        actionPlayMIDI->setObjectName(QStringLiteral("actionPlayMIDI"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/res/play_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlayMIDI->setIcon(icon16);
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
        menuNew->addAction(actionNewScore);
        menuNew->addAction(actionNewCounterpoint);
        menuOpen->addAction(actionOpenLilypond);
        menuExport->addAction(actionSaveLilypond);
        mainToolBar->addAction(actionNewStaff);
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
        mainToolBar->addAction(actionChangeNoteRest);
        toolBar->addAction(actionNewScore);
        toolBar->addAction(actionOpenLilypond);
        toolBar->addAction(actionSaveLilypond);
        toolBar->addSeparator();
        toolBar->addAction(actionNewCounterpoint);
        toolBar->addAction(actionTest);
        toolBar->addSeparator();
        toolBar->addAction(actionPlayMIDI);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ellenpont", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Kil\303\251p\303\251s", 0));
        actionAddNote->setText(QApplication::translate("MainWindow", "\303\232j Hangjegy", 0));
        actionAddRest->setText(QApplication::translate("MainWindow", "\303\232j Sz\303\274net", 0));
        actionHalf->setText(QApplication::translate("MainWindow", "F\303\251l", 0));
        actionHalf->setShortcut(QApplication::translate("MainWindow", "2", 0));
        actionWhole->setText(QApplication::translate("MainWindow", "Eg\303\251sz", 0));
        actionWhole->setShortcut(QApplication::translate("MainWindow", "1", 0));
        actionQuarter->setText(QApplication::translate("MainWindow", "Negyed", 0));
        actionQuarter->setShortcut(QApplication::translate("MainWindow", "3", 0));
        actionEighth->setText(QApplication::translate("MainWindow", "Nyolcad", 0));
        actionEighth->setShortcut(QApplication::translate("MainWindow", "4", 0));
        actionAddSharp->setText(QApplication::translate("MainWindow", "Kereszt hozz\303\241ad\303\241sa", 0));
        actionAddFlat->setText(QApplication::translate("MainWindow", "B hozz\303\241ad\303\241sa", 0));
        actionNewScore->setText(QApplication::translate("MainWindow", "\303\232j kotta", 0));
        actionNewCounterpoint->setText(QApplication::translate("MainWindow", "\303\232j Ellenpont feladat", 0));
        actionChangeNoteRest->setText(QApplication::translate("MainWindow", "Hang cser\303\251je hang-sz\303\274net", 0));
#ifndef QT_NO_TOOLTIP
        actionChangeNoteRest->setToolTip(QApplication::translate("MainWindow", "Hang - Sz\303\274net csere, gyorsbillenyt\305\261: M", 0));
#endif // QT_NO_TOOLTIP
        actionChangeNoteRest->setShortcut(QApplication::translate("MainWindow", "M", 0));
        actionOpenLilypond->setText(QApplication::translate("MainWindow", "LilyPond file megnyit\303\241sa", 0));
        actionSaveLilypond->setText(QApplication::translate("MainWindow", "Ment\303\251s LilyPond f\303\241jlba", 0));
        actionTest->setText(QApplication::translate("MainWindow", "Ellen\305\221rz\303\251s", 0));
        actionTest->setShortcut(QApplication::translate("MainWindow", "T", 0));
        actionNewStaff->setText(QApplication::translate("MainWindow", "\303\232j Kottasor", 0));
        actionPlayMIDI->setText(QApplication::translate("MainWindow", "Lej\303\241tsz\303\241s", 0));
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
