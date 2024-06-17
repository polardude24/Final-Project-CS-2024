#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
    name = "Health Potion";
    type = 'C';
    curWin = nullptr;
    //ctor
}
HealthPotion::HealthPotion(WINDOW * _curWin) : HealthPotion()
{
    curWin = _curWin;
}

HealthPotion::~HealthPotion()
{
    //dtor
}

void HealthPotion::use()
{
    return;
}
