/********************************************************************************
** Form generated from reading UI file 'newcpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QGroupBox>
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
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *trebleRadioButton;
    QRadioButton *altoRadioButton;
    QRadioButton *tenorRadioButton;
    QRadioButton *bassRadioButton;
    QGroupBox *groupBox_2;
    QLineEdit *lineCF;
    QPushButton *browseFileButton;

    void setupUi(QDialog *NewCPDialog)
    {
        if (NewCPDialog->objectName().isEmpty())
            NewCPDialog->setObjectName(QStringLiteral("NewCPDialog"));
        NewCPDialog->resize(451, 253);
        buttonBox = new QDialogButtonBox(NewCPDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 210, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(NewCPDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 131, 201));
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

        groupBox_2 = new QGroupBox(NewCPDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 10, 291, 101));
        lineCF = new QLineEdit(groupBox_2);
        lineCF->setObjectName(QStringLiteral("lineCF"));
        lineCF->setGeometry(QRect(10, 30, 271, 20));
        lineCF->setCursor(QCursor(Qt::ArrowCursor));
        lineCF->setReadOnly(true);
        browseFileButton = new QPushButton(groupBox_2);
        browseFileButton->setObjectName(QStringLiteral("browseFileButton"));
        browseFileButton->setGeometry(QRect(64, 60, 161, 23));

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
