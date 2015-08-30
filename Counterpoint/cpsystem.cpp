#include "cpsystem.h"

int Cpsystem::initGui(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setSvm(this->getScoreview());

    w.show();

    return a.exec();
}


ScoreViewModel *Cpsystem::getScoreview() const
{
    return scoreview;
}
Cpsystem::Cpsystem()
{
    scoreview = new ScoreViewModel();

}

Cpsystem::~Cpsystem()
{
    delete scoreview;
}

void Cpsystem::test()
{

    scoreview->addStaff(Clef::treble, 0, 0);
    scoreview->addNote(1, 0, 4, 0);
    scoreview->addNote(1, 4, 4, 0);
    scoreview->addNote(1, 0, 4, 0);
    scoreview->addNote(1, 4, 4, 0);
    scoreview->addNote(1, 7, 2, 0);
    scoreview->addNote(1, 7, 2, 0);
/*
    scoreview->addStaff(Clef::treble, 0, 0);
    scoreview->addNote(2, 0, 2, 0);
    scoreview->addNote(2, 0, 2, 0);
    scoreview->addNote(2, 7, 2, 0);
    scoreview->addNote(2, 7, 2, 0);

    scoreview->addStaff(Clef::treble, 0, 0);
    scoreview->addNote(3, 0, 2, 0);
    scoreview->addNote(3, 0, 2, 0);
    scoreview->addNote(3, 7, 2, 0);
    scoreview->addNote(3, 7, 2, 0);

    scoreview->addStaff(Clef::treble, 0, 0);
    scoreview->addNote(4, 0, 2, 0);
    scoreview->addNote(4, 0, 2, 0);
    scoreview->addNote(4, 7, 2, 0);
    scoreview->addNote(4, 7, 2, 0);
*/



}

