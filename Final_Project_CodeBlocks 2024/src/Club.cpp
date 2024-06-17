#include "Club.h"

Club::Club()
{
    name = "Club";
    type = 'W';
    curWin = nullptr;
    //ctor
}
Club::Club(WINDOW * _curWin) : Club()
{
    curWin = _curWin;
}
Club::~Club()
{
    //dtor
}

void Club::use()
{
    return;
}
