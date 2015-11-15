#ifndef SCORESETTINGSDIALOG_H
#define SCORESETTINGSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include "tester.h"

namespace Ui {
class ScoreSettingsDialog;
}

class ScoreSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreSettingsDialog(QList<Tester *> rulelist, int vnotedistance, QWidget *parent = 0);
    ~ScoreSettingsDialog();

    QList<int> getRuleList() const;
    int getVnoteDistance() const;

private:
    Ui::ScoreSettingsDialog *ui;
};

#endif // SCORESETTINGSDIALOG_H
