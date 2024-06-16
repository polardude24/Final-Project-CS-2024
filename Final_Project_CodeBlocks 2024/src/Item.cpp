#include "Item.h"

Item::Item()
{
    id = -1;
    name = "";
    type = ' ';
    curWin = nullptr;
}
Item::Item(WINDOW * _curWin, int _id, string _name, char _type)
{
    curWin = _curWin;
    id = _id;
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

void Item::use()
{
    return;
}

/*
Item * Utility::generateItem()
{
    // NOTE: There will be 1 less case than the amount of items, because monsters should not *randomly* drop the key. The last one is always the one to drop the key.
    Item * temp = nullptr;

    switch(Utility::randomNumberInt(numItemTypes))
    {
    case 0:
        temp = new Sword();
        break;
    case 1:
        temp = new Club();
        break;
    case 2:
        temp = new MagicalStaff();
        break;
    case 3:
        temp = new Sword();
        break;
    case 4:
        temp = new Sword();
        break;
    case 5:
        temp = new Sword();
        break;
    case 6:
        temp = new Sword();
        break;
    case 7:
        temp = new Sword();
        break;
    case 8:
        temp = new Sword();
        break;
    case 9:
        temp = new Sword();
        break;
    default:
        break;
    }

    return temp;
}
*/
