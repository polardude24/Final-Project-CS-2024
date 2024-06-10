#include "MenuBar.h"

MenuBar::MenuBar()
{
    //ctor
}

MenuBar::~MenuBar()
{
    //dtor
}

MenuBar::MenuBar(WINDOW * _win, Menu * _menus, int _numMenus)
{
    win = _win;
    menus = _menus;
    numMenus = _numMenus;
    selectedMenu = -1;

    int currentPos = 2;

    for (int i = 0; i < numMenus ; i++)
    {
        menus[i].startX = currentPos;
        currentPos += menus[i].text.length() + 1;
    }
}
void MenuBar::display()
{
    for (int i = 0; i < numMenus ; i++)
    {
        int startX = menus[i].startX;
        string text = menus[i].text;
        if(selectedMenu == i)
            wattron(win, A_STANDOUT);
        else wattroff(win, A_STANDOUT);
        mvwprintw(win, 0, startX, text.c_str());
        //wattroff(win, A_STANDOUT);
    }
}
void MenuBar::handleTrigger(char _trigger)
{
    bool flag = false;
    for(int i = 0; i < numMenus; i++)
    {
        if(_trigger == menus[i].trigger)
        {
            selectedMenu = i;
            flag = true;
        }
    }
    if(flag == false)
    {
        selectedMenu = -1;
    }
    return;
}
