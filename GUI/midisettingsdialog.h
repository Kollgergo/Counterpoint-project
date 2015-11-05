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
    explicit MidiSettingsDialog(QWidget *parent = 0);
    ~MidiSettingsDialog();

private:
    Ui::MidiSettingsDialog *ui;
};

#endif // MIDISETTINGSDIALOG_H
