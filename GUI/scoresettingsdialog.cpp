#include "scoresettingsdialog.h"
#include "ui_scoresettingsdialog.h"

ScoreSettingsDialog::ScoreSettingsDialog(QList<Tester *> rulelist, int vnotedistance, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreSettingsDialog)
{
    ui->setupUi(this);

    if(!rulelist.isEmpty()){
        for(int i=0; i<rulelist.size(); i++){
            switch (rulelist.at(i)->getTestType()) {
            case 1:
                ui->beginEndRuleCheckBox->setChecked(true);
                break;
            case 2:
                ui->forbiddenSkipsCheckBox->setChecked(true);
                break;
            case 3:
                ui->mainRulesCheckBox->setChecked(true);
                break;
            case 4:
                ui->maxIntervalCheckBox->setChecked(true);
                break;
            case 5:
                ui->modeRuleCheckBox->setChecked(true);
                break;
            case 6:
                ui->nextToTheLastCheckBox->setChecked(true);
                break;
            case 7:
                ui->onlyConsonanceCheckBox->setChecked(true);
                break;
            default:
                break;
            }
        }
    }



//    if(!rulelist.isEmpty()){
//        foreach (int rule, rulelist) {

//        }
//    }

    ui->noteDistanceSpinBox->setValue(vnotedistance);

}

ScoreSettingsDialog::~ScoreSettingsDialog()
{
    delete ui;
}

QList<int> ScoreSettingsDialog::getRuleList() const
{
    QList<int> templist;

    if(ui->beginEndRuleCheckBox->isChecked()){
        templist.push_back(1);
    }

    if(ui->forbiddenSkipsCheckBox->isChecked()){
        templist.push_back(2);
    }

    if(ui->mainRulesCheckBox->isChecked()){
        templist.push_back(3);
    }

    if(ui->maxIntervalCheckBox->isChecked()){
        templist.push_back(4);
    }

    if(ui->modeRuleCheckBox->isChecked()){
        templist.push_back(5);
    }

    if(ui->nextToTheLastCheckBox->isChecked()){
        templist.push_back(6);
    }

    if(ui->onlyConsonanceCheckBox->isChecked()){
        templist.push_back(7);
    }

    return templist;
}

int ScoreSettingsDialog::getVnoteDistance() const
{
    return ui->noteDistanceSpinBox->value();
}
