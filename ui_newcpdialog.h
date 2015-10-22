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
    QGroupBox *groupBox_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *upperRadioButton;
    QRadioButton *lowerRadioButton;

    void setupUi(QDialog *NewCPDialog)
    {
        if (NewCPDialog->objectName().isEmpty())
            NewCPDialog->setObjectName(QStringLiteral("NewCPDialog"));
        NewCPDialog->resize(451, 253);
        buttonBox = new QDialogButtonBox(NewCPDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(70, 220, 341, 32));
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
        groupBox_3 = new QGroupBox(NewCPDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(150, 110, 291, 101));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 271, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        upperRadioButton = new QRadioButton(widget);
        upperRadioButton->setObjectName(QStringLiteral("upperRadioButton"));

        horizontalLayout->addWidget(upperRadioButton);

        lowerRadioButton = new QRadioButton(widget);
        lowerRadioButton->setObjectName(QStringLiteral("lowerRadioButton"));

        horizontalLayout->addWidget(lowerRadioButton);


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
        groupBox_3->setTitle(QApplication::translate("NewCPDialog", "Ellenpont helye", 0));
        upperRadioButton->setText(QApplication::translate("NewCPDialog", "Fels\305\221 ellenpont", 0));
        lowerRadioButton->setText(QApplication::translate("NewCPDialog", "Als\303\263 ellenpont", 0));
    } // retranslateUi

};

namespace Ui {
    class NewCPDialog: public Ui_NewCPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCPDIALOG_H
