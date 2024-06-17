#include "Scythe.h"

Scythe::Scythe()
{
    name = "Scythe";
    type = 'W';
    curWin = nullptr;
    //ctor
}
Scythe::Scythe(WINDOW * _curWin) : Scythe()
{
    curWin = _curWin;
}

Scythe::~Scythe()
{
    //dtor
}

void Scythe::use()
{
    return;
}
