#include "Sword.h"

Sword::Sword()
{
    name = "Sword";
    type = 'W';
    curWin = nullptr;
    //ctor
}
Sword::Sword(WINDOW * _curWin) : Sword()
{
    curWin = _curWin;
}

Sword::~Sword()
{
    //dtor
}

void Sword::use()
{
    return;
}
