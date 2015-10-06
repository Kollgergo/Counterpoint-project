#include "newcpdialog.h"
#include "ui_newcpdialog.h"

NewCPDialog::NewCPDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCPDialog)
{
    ui->setupUi(this);
    clef = ScoreViewModel::treble;
    ui->trebleRadioButton->setChecked(true);
    QPushButton *okButton=ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(false);
}

NewCPDialog::~NewCPDialog()
{
    delete ui;
}

void NewCPDialog::on_browseFileButton_clicked()
{
    QMessageBox msgbox(this);
    msgbox.setText("Cantus Firmus megnyitása");
    msgbox.setInformativeText("A megnyitott kottának egy szólamúnak kell lennie! Ha több mint egy szólam, akkor csak az első szólam lesz feldolgozva. Folytatja?");
    msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgbox.setDefaultButton(QMessageBox::Cancel);
    msgbox.setButtonText(QMessageBox::Ok, "Igen");
    msgbox.setButtonText(QMessageBox::Cancel, "Mégse");
    int ret = msgbox.exec();

    if(ret == QMessageBox::Ok){
        QString filename = QFileDialog::getOpenFileName(this, "Cantus Firmus megnyitása", "./export", "*.ly");
        if(!filename.isEmpty()){
            ui->lineCF->setText(filename);
            QPushButton *okButton=ui->buttonBox->button(QDialogButtonBox::Ok);
            okButton->setEnabled(true);
        }
    }

}

void NewCPDialog::on_trebleRadioButton_clicked()
{
    clef = ScoreViewModel::treble;
}

void NewCPDialog::on_altoRadioButton_clicked()
{
    clef = ScoreViewModel::alto;
}

void NewCPDialog::on_tenorRadioButton_clicked()
{
    clef = ScoreViewModel::tenor;
}

void NewCPDialog::on_bassRadioButton_clicked()
{
    clef = ScoreViewModel::bass;
}
ScoreViewModel::clefNames NewCPDialog::getClef() const
{
    return clef;
}

QString NewCPDialog::getFileName() const
{
    return ui->lineCF->text();
}

