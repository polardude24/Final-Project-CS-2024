#include "Weapon.h"

Weapon::Weapon()
{
    //ctor
}
Weapon::Weapon(WINDOW * _curWin, string _name, char _type, float _strengthModifier, bool _multiply) : Item(_curWin, _name, _type)
{
    strengthModifier = _strengthModifier;
    multiply = _multiply;
}

Weapon::~Weapon()
{
    //dtor
}

float Weapon::use()
{
    return strengthModifier;
}
