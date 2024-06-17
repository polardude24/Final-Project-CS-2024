#include "MagicStaff.h"

MagicStaff::MagicStaff()
{
    name = "Magic Staff";
    type = 'W';
    curWin = nullptr;
    //ctor
}
MagicStaff::MagicStaff(WINDOW * _curWin) : MagicStaff()
{
    curWin = _curWin;
}

MagicStaff::~MagicStaff()
{
    //dtor
}

void MagicStaff::use()
{
    return;
}
