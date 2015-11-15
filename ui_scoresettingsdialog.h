/********************************************************************************
** Form generated from reading UI file 'scoresettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORESETTINGSDIALOG_H
#define UI_SCORESETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *mainRulesCheckBox;
    QCheckBox *onlyConsonanceCheckBox;
    QCheckBox *beginEndRuleCheckBox;
    QCheckBox *maxIntervalCheckBox;
    QCheckBox *nextToTheLastCheckBox;
    QCheckBox *modeRuleCheckBox;
    QCheckBox *forbiddenSkipsCheckBox;
    QGroupBox *groupBox;
    QWidget *widget1;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *noteDistanceSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScoreSettingsDialog)
    {
        if (ScoreSettingsDialog->objectName().isEmpty())
            ScoreSettingsDialog->setObjectName(QStringLiteral("ScoreSettingsDialog"));
        ScoreSettingsDialog->resize(475, 314);
        gridLayout = new QGridLayout(ScoreSettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_2 = new QGroupBox(ScoreSettingsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 22, 211, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainRulesCheckBox = new QCheckBox(widget);
        mainRulesCheckBox->setObjectName(QStringLiteral("mainRulesCheckBox"));

        verticalLayout->addWidget(mainRulesCheckBox);

        onlyConsonanceCheckBox = new QCheckBox(widget);
        onlyConsonanceCheckBox->setObjectName(QStringLiteral("onlyConsonanceCheckBox"));

        verticalLayout->addWidget(onlyConsonanceCheckBox);

        beginEndRuleCheckBox = new QCheckBox(widget);
        beginEndRuleCheckBox->setObjectName(QStringLiteral("beginEndRuleCheckBox"));

        verticalLayout->addWidget(beginEndRuleCheckBox);

        maxIntervalCheckBox = new QCheckBox(widget);
        maxIntervalCheckBox->setObjectName(QStringLiteral("maxIntervalCheckBox"));

        verticalLayout->addWidget(maxIntervalCheckBox);

        nextToTheLastCheckBox = new QCheckBox(widget);
        nextToTheLastCheckBox->setObjectName(QStringLiteral("nextToTheLastCheckBox"));

        verticalLayout->addWidget(nextToTheLastCheckBox);

        modeRuleCheckBox = new QCheckBox(widget);
        modeRuleCheckBox->setObjectName(QStringLiteral("modeRuleCheckBox"));

        verticalLayout->addWidget(modeRuleCheckBox);

        forbiddenSkipsCheckBox = new QCheckBox(widget);
        forbiddenSkipsCheckBox->setObjectName(QStringLiteral("forbiddenSkipsCheckBox"));

        verticalLayout->addWidget(forbiddenSkipsCheckBox);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(ScoreSettingsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 23, 191, 31));
        formLayout = new QFormLayout(widget1);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        noteDistanceSpinBox = new QSpinBox(widget1);
        noteDistanceSpinBox->setObjectName(QStringLiteral("noteDistanceSpinBox"));
        noteDistanceSpinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        noteDistanceSpinBox->setMaximum(100);
        noteDistanceSpinBox->setSingleStep(5);

        formLayout->setWidget(0, QFormLayout::FieldRole, noteDistanceSpinBox);

        label->raise();
        noteDistanceSpinBox->raise();
        groupBox_2->raise();

        horizontalLayout->addWidget(groupBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ScoreSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(ScoreSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ScoreSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ScoreSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ScoreSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ScoreSettingsDialog)
    {
        ScoreSettingsDialog->setWindowTitle(QApplication::translate("ScoreSettingsDialog", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("ScoreSettingsDialog", "Ellenpont szab\303\241ly be\303\241ll\303\255t\303\241sok", 0));
        mainRulesCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Alapvet\305\221 szab\303\241lyok", 0));
        onlyConsonanceCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Csak konszon\303\241ns hangk\303\266z\303\266k", 0));
        beginEndRuleCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Elej\303\251n \303\251s v\303\251g\303\251n csak t\303\266k\303\251letes konsz.", 0));
        maxIntervalCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Legnagyobb hangk\303\266z T8", 0));
        nextToTheLastCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Utols\303\263 el\305\221tti hangk\303\266z N6/K3", 0));
        modeRuleCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Hangnem szab\303\241ly", 0));
        forbiddenSkipsCheckBox->setText(QApplication::translate("ScoreSettingsDialog", "Tilos ugr\303\241sok szab\303\241ly", 0));
        groupBox->setTitle(QApplication::translate("ScoreSettingsDialog", "Kotta be\303\241ll\303\255t\303\241sok", 0));
        label->setText(QApplication::translate("ScoreSettingsDialog", "Hang t\303\241vols\303\241g", 0));
    } // retranslateUi

};

namespace Ui {
    class ScoreSettingsDialog: public Ui_ScoreSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORESETTINGSDIALOG_H
