#include "newstaffdialog.h"
#include "ui_newstaffdialog.h"

NewStaffDialog::NewStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStaffDialog)
{
    ui->setupUi(this);
    selectedclef = ScoreViewModel::treble;
    selectedkeysignature = 0;
    ui->trebleRadioButton->setChecked(true);
}

NewStaffDialog::~NewStaffDialog()
{
    delete ui;
}

ScoreViewModel::clefNames NewStaffDialog::getSelectedclef() const
{
    return selectedclef;
}

int NewStaffDialog::getSelectedkeysignature() const
{
    return selectedkeysignature;
}

void NewStaffDialog::on_trebleRadioButton_clicked()
{
    selectedclef = ScoreViewModel::treble;
}

void NewStaffDialog::on_altoRadioButton_clicked()
{
    selectedclef = ScoreViewModel::alto;
}

void NewStaffDialog::on_tenorRadioButton_clicked()
{
    selectedclef = ScoreViewModel::tenor;
}

void NewStaffDialog::on_bassRadioButton_clicked()
{
    selectedclef = ScoreViewModel::bass;
}


void NewStaffDialog::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        selectedkeysignature = 0;
        break;
    case 1:
        selectedkeysignature = 1;
        break;
    case 2:
        selectedkeysignature = -1;
        break;
    case 3:
        selectedkeysignature = 2;
        break;
    case 4:
        selectedkeysignature = -2;
        break;
    case 5:
        selectedkeysignature = 3;
        break;
    case 6:
        selectedkeysignature = -3;
        break;
    case 7:
        selectedkeysignature = 4;
        break;
    case 8:
        selectedkeysignature = -4;
        break;
    case 9:
        selectedkeysignature = 5;
        break;
    case 10:
        selectedkeysignature = -5;
        break;
    case 11:
        selectedkeysignature = 6;
        break;
    case 12:
        selectedkeysignature = -6;
        break;
    case 13:
        selectedkeysignature = 7;
        break;
    case 14:
        selectedkeysignature = -7;
        break;
    default:
        selectedkeysignature = 0;
        break;
    }
}
