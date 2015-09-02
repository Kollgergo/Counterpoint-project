#ifndef CPSYSTEM_H
#define CPSYSTEM_H
#include <iostream>
#include <stdlib.h>
#include "scoreviewmodel.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;

class Cpsystem
{
private:
    ScoreViewModel *scoreview;


public:
    Cpsystem();
    ~Cpsystem();

   void test();
   ScoreViewModel *getScoreview() const;
   int initGui(int argc, char *argv[]);

};

#endif // CPSYSTEM_H
