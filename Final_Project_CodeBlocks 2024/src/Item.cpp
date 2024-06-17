#include "Item.h"

Item::Item()
{
    name = "";
    type = ' ';
    curWin = nullptr;
}
Item::Item(WINDOW * _curWin, string _name, char _type)
{
    curWin = _curWin;
    name = _name;
    type = _type;
}

Item::~Item()
{
    //dtor
}

char Item::getType()
{
    return type;
}
string Item::getName()
{
    return name;
}

void Item::use(Player * _player)
{
    return;
}
