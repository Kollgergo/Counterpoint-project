#ifndef NEWSTAFFDIALOG_H
#define NEWSTAFFDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include "scoreviewmodel.h"

namespace Ui {
class NewStaffDialog;
}

class NewStaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStaffDialog(QWidget *parent = 0);
    ~NewStaffDialog();

    ScoreViewModel::clefNames getSelectedclef() const;
    int getSelectedkeysignature() const;

private slots:
    void on_trebleRadioButton_clicked();

    void on_altoRadioButton_clicked();

    void on_tenorRadioButton_clicked();

    void on_bassRadioButton_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::NewStaffDialog *ui;
    ScoreViewModel::clefNames selectedclef;
    int selectedkeysignature;
};

#endif // NEWSTAFFDIALOG_H
