/********************************************************************************
** Form generated from reading UI file 'newcpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCPDIALOG_H
#define UI_NEWCPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewCPDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *trebleRadioButton;
    QRadioButton *altoRadioButton;
    QRadioButton *tenorRadioButton;
    QRadioButton *bassRadioButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineCF;
    QPushButton *browseFileButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewCPDialog)
    {
        if (NewCPDialog->objectName().isEmpty())
            NewCPDialog->setObjectName(QStringLiteral("NewCPDialog"));
        NewCPDialog->resize(552, 290);
        verticalLayout_3 = new QVBoxLayout(NewCPDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(NewCPDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 89, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        trebleRadioButton = new QRadioButton(layoutWidget);
        trebleRadioButton->setObjectName(QStringLiteral("trebleRadioButton"));

        verticalLayout->addWidget(trebleRadioButton);

        altoRadioButton = new QRadioButton(layoutWidget);
        altoRadioButton->setObjectName(QStringLiteral("altoRadioButton"));

        verticalLayout->addWidget(altoRadioButton);

        tenorRadioButton = new QRadioButton(layoutWidget);
        tenorRadioButton->setObjectName(QStringLiteral("tenorRadioButton"));

        verticalLayout->addWidget(tenorRadioButton);

        bassRadioButton = new QRadioButton(layoutWidget);
        bassRadioButton->setObjectName(QStringLiteral("bassRadioButton"));

        verticalLayout->addWidget(bassRadioButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(NewCPDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 70, 241, 71));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineCF = new QLineEdit(layoutWidget1);
        lineCF->setObjectName(QStringLiteral("lineCF"));
        lineCF->setCursor(QCursor(Qt::ArrowCursor));
        lineCF->setReadOnly(true);

        verticalLayout_4->addWidget(lineCF);

        browseFileButton = new QPushButton(layoutWidget1);
        browseFileButton->setObjectName(QStringLiteral("browseFileButton"));

        verticalLayout_4->addWidget(browseFileButton);


        horizontalLayout->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NewCPDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        retranslateUi(NewCPDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewCPDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewCPDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewCPDialog);
    } // setupUi

    void retranslateUi(QDialog *NewCPDialog)
    {
        NewCPDialog->setWindowTitle(QApplication::translate("NewCPDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("NewCPDialog", "Ellenpont sz\303\263lam kulcsa", 0));
        trebleRadioButton->setText(QApplication::translate("NewCPDialog", "Violin kulcs", 0));
        altoRadioButton->setText(QApplication::translate("NewCPDialog", "Alt kulcs", 0));
        tenorRadioButton->setText(QApplication::translate("NewCPDialog", "Tenor kulcs", 0));
        bassRadioButton->setText(QApplication::translate("NewCPDialog", "Basszus kulcs", 0));
        groupBox_2->setTitle(QApplication::translate("NewCPDialog", "Cantus Firmus f\303\241jl helye", 0));
        browseFileButton->setText(QApplication::translate("NewCPDialog", "Cantus Firmus kiv\303\241laszt\303\241sa", 0));
    } // retranslateUi

};

namespace Ui {
    class NewCPDialog: public Ui_NewCPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCPDIALOG_H
