#include "Consumable.h"

Consumable::Consumable()
{
    //ctor
}
Consumable::Consumable(WINDOW * _curWin, string _name, char _type, float _healthModifier, bool _multiply) : Item(_curWin, _name, _type)
{
    healthModifier = _healthModifier;
    multiply = _multiply;
}

Consumable::~Consumable()
{
    //dtor
}

float Consumable::use()
{
    return healthModifier;
}
