/********************************************************************************
** Form generated from reading UI file 'midisettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDISETTINGSDIALOG_H
#define UI_MIDISETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MidiSettingsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QSlider *volumeSlider;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QSlider *tempoSlider;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MidiSettingsDialog)
    {
        if (MidiSettingsDialog->objectName().isEmpty())
            MidiSettingsDialog->setObjectName(QStringLiteral("MidiSettingsDialog"));
        MidiSettingsDialog->setWindowModality(Qt::WindowModal);
        MidiSettingsDialog->resize(400, 300);
        MidiSettingsDialog->setModal(false);
        verticalLayout_2 = new QVBoxLayout(MidiSettingsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(MidiSettingsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        volumeSlider = new QSlider(groupBox);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMinimum(1);
        volumeSlider->setMaximum(100);
        volumeSlider->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(volumeSlider);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(25, 15));
        label_4->setMaximumSize(QSize(25, 15));
        label_4->setFrameShape(QFrame::StyledPanel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        tempoSlider = new QSlider(groupBox);
        tempoSlider->setObjectName(QStringLiteral("tempoSlider"));
        tempoSlider->setMinimum(1);
        tempoSlider->setMaximum(100);
        tempoSlider->setOrientation(Qt::Vertical);

        horizontalLayout_9->addWidget(tempoSlider);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(25, 15));
        label_5->setMaximumSize(QSize(25, 15));
        label_5->setFrameShape(QFrame::Panel);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setLineWidth(1);
        label_5->setMidLineWidth(0);
        label_5->setScaledContents(false);
        label_5->setWordWrap(true);

        horizontalLayout_9->addWidget(label_5);


        gridLayout->addLayout(horizontalLayout_9, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(MidiSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MidiSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MidiSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MidiSettingsDialog, SLOT(reject()));
        QObject::connect(volumeSlider, SIGNAL(valueChanged(int)), label_4, SLOT(setNum(int)));
        QObject::connect(tempoSlider, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MidiSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *MidiSettingsDialog)
    {
        MidiSettingsDialog->setWindowTitle(QApplication::translate("MidiSettingsDialog", "MIDI be\303\241ll\303\255t\303\241sok", 0));
        groupBox->setTitle(QApplication::translate("MidiSettingsDialog", "MIDI be\303\241ll\303\255t\303\241sok", 0));
        label_4->setText(QApplication::translate("MidiSettingsDialog", "TextLabel", 0));
        label_5->setText(QApplication::translate("MidiSettingsDialog", "TextLabel", 0));
        label_2->setText(QApplication::translate("MidiSettingsDialog", "Hanger\305\221", 0));
        label_3->setText(QApplication::translate("MidiSettingsDialog", "Tempo", 0));
        label->setText(QApplication::translate("MidiSettingsDialog", "Hangszer", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MidiSettingsDialog", "Acoustic Grand Piano", 0)
         << QApplication::translate("MidiSettingsDialog", "Bright Acoustic Piano", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Grand Piano", 0)
         << QApplication::translate("MidiSettingsDialog", "Honky-tonk Piano", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Piano 1", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Piano 2", 0)
         << QApplication::translate("MidiSettingsDialog", "Harpsichord", 0)
         << QApplication::translate("MidiSettingsDialog", "Clavinet", 0)
         << QApplication::translate("MidiSettingsDialog", "Celesta", 0)
         << QApplication::translate("MidiSettingsDialog", "Glockenspiel", 0)
         << QApplication::translate("MidiSettingsDialog", "Music Box", 0)
         << QApplication::translate("MidiSettingsDialog", "Vibraphone", 0)
         << QApplication::translate("MidiSettingsDialog", "Marimba", 0)
         << QApplication::translate("MidiSettingsDialog", "Xylophone", 0)
         << QApplication::translate("MidiSettingsDialog", "Tubular Bells", 0)
         << QApplication::translate("MidiSettingsDialog", "Dulcimer", 0)
         << QApplication::translate("MidiSettingsDialog", "Drawbar Organ", 0)
         << QApplication::translate("MidiSettingsDialog", "Percussive Organ", 0)
         << QApplication::translate("MidiSettingsDialog", "Rock Organ", 0)
         << QApplication::translate("MidiSettingsDialog", "Church Organ", 0)
         << QApplication::translate("MidiSettingsDialog", "Reed Organ", 0)
         << QApplication::translate("MidiSettingsDialog", "Accordion", 0)
         << QApplication::translate("MidiSettingsDialog", "Harmonica", 0)
         << QApplication::translate("MidiSettingsDialog", "Tango Accordion", 0)
         << QApplication::translate("MidiSettingsDialog", "Acoustic Guitar (nylon)", 0)
         << QApplication::translate("MidiSettingsDialog", "Acoustic Guitar (steel)", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Guitar (jazz)", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Guitar (clean)", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Guitar (muted)", 0)
         << QApplication::translate("MidiSettingsDialog", "Overdriven Guitar", 0)
         << QApplication::translate("MidiSettingsDialog", "Distortion Guitar", 0)
         << QApplication::translate("MidiSettingsDialog", "Guitar harmonics", 0)
         << QApplication::translate("MidiSettingsDialog", "Acoustic Bass", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Bass (finger)", 0)
         << QApplication::translate("MidiSettingsDialog", "Electric Bass (pick)", 0)
         << QApplication::translate("MidiSettingsDialog", "Fretless Bass", 0)
         << QApplication::translate("MidiSettingsDialog", "Slap Bass 1", 0)
         << QApplication::translate("MidiSettingsDialog", "Slap Bass 2", 0)
         << QApplication::translate("MidiSettingsDialog", "Synth Bass 1", 0)
         << QApplication::translate("MidiSettingsDialog", "Synth Bass 2", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MidiSettingsDialog: public Ui_MidiSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDISETTINGSDIALOG_H
