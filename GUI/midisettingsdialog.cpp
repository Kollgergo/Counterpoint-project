#include "midisettingsdialog.h"
#include "ui_midisettingsdialog.h"

MidiSettingsDialog::MidiSettingsDialog(int instrument, int volume, int tempo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MidiSettingsDialog)
{
    ui->setupUi(this);

    ui->comboBox->setCurrentIndex(instrument);

    ui->volumeSlider->setValue(volume);

    ui->tempoSlider->setValue(tempo);
}

MidiSettingsDialog::~MidiSettingsDialog()
{
    delete ui;
}

int MidiSettingsDialog::getInstrument() const
{
    return ui->comboBox->currentIndex();
}

int MidiSettingsDialog::getVolume() const
{
    return ui->volumeSlider->value();
}

int MidiSettingsDialog::getTempo() const
{
   return ui->tempoSlider->value();
}
