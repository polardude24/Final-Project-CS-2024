#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
Menu::Menu(string _text, char _trigger, string *_items, int _numItems)
{
    text = _text;
    trigger = _trigger;
    items = _items;
    numItems = _numItems;
    selectedItem = 0;
}

void Menu::Menu::selectNextItem()
{
    selectedItem++;
    if(selectedItem >= numItems)
    {
        selectedItem = 0;
    }
    return;
}
void Menu::selectPrevItem()
{
    selectedItem--;
    if(selectedItem < 0)
    {
        selectedItem = numItems-1;
    }
    return;
}
