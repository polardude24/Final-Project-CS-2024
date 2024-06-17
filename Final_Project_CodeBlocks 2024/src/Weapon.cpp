#include "Weapon.h"

Weapon::Weapon()
{
    //ctor
}
Weapon::Weapon(WINDOW * _curWin, string _name, char _type, float _strengthModifier) : Item(_curWin, _name, _type)
{
    strengthModifier = _strengthModifier;
}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::use()
{

    return;
}
