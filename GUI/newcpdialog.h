#ifndef NEWCPDIALOG_H
#define NEWCPDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "Datamodel/scoreviewmodel.h"

namespace Ui {
class NewCPDialog;
}

class NewCPDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCPDialog(QWidget *parent = 0);
    ~NewCPDialog();

    ScoreViewModel::clefNames getClef() const;
    QString getFileName() const;

private slots:
    void on_browseFileButton_clicked();

    void on_trebleRadioButton_clicked();

    void on_altoRadioButton_clicked();

    void on_tenorRadioButton_clicked();

    void on_bassRadioButton_clicked();

private:
    Ui::NewCPDialog *ui;
    ScoreViewModel::clefNames clef;

};

#endif // NEWCPDIALOG_H
