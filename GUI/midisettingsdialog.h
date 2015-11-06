#ifndef MIDISETTINGSDIALOG_H
#define MIDISETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class MidiSettingsDialog;
}

class MidiSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MidiSettingsDialog(int instrument, int volume, int tempo, QWidget *parent = 0);
    ~MidiSettingsDialog();

    int getInstrument() const;
    int getVolume() const;
    int getTempo() const;

private:
    Ui::MidiSettingsDialog *ui;
};

#endif // MIDISETTINGSDIALOG_H
