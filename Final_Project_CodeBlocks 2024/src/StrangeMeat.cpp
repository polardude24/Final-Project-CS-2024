#include "StrangeMeat.h"

StrangeMeat::StrangeMeat()
{
    name = "Strange Meat";
    type = 'C';
    curWin = nullptr;
    //ctor
}
StrangeMeat::StrangeMeat(WINDOW * _curWin) : StrangeMeat()
{
    curWin = _curWin;
}

StrangeMeat::~StrangeMeat()
{
    //dtor
}

void StrangeMeat::use()
{
    return;
}
