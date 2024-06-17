#include "GarlicClove.h"

GarlicClove::GarlicClove()
{
    name = "Garlic Clove";
    type = 'C';
    curWin = nullptr;
    //ctor
}
GarlicClove::GarlicClove(WINDOW * _curWin) : GarlicClove()
{
    curWin = _curWin;
}

GarlicClove::~GarlicClove()
{
    //dtor
}

void GarlicClove::use()
{
    return;
}
