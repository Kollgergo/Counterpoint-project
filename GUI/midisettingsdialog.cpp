#include "midisettingsdialog.h"
#include "ui_midisettingsdialog.h"

MidiSettingsDialog::MidiSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MidiSettingsDialog)
{
    ui->setupUi(this);
}

MidiSettingsDialog::~MidiSettingsDialog()
{
    delete ui;
}
