#include "MenuBar.h"

/**

COURTESY OF CASUAL CODER, I DID NOT MAKE MOST OF THIS CODE MYSELF.
As it's not part of the assignment description, you said this was okay.

*/


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

    int yMax, xMax, yBeg, xBeg;
    getmaxyx(win, yMax, xMax);
    getbegyx(win, yBeg, xBeg);
    menuWin = newwin(yMax-2, xMax-2, yBeg+1, xBeg+1);
    keypad(menuWin, true);
    wrefresh(menuWin);

    int currentPos = 2;

    for (int i = 0; i < numMenus ; i++)
    {
        menus[i].setStartX(currentPos);
        currentPos += menus[i].getText().length() + 1;
    }
}


/// Displays all of the menus in the menu bar
void MenuBar::display()
{
    for (int i = 0; i < numMenus ; i++)
    {
        displayMenu(menus[i], selectedMenu == i);
    }
    selectedMenu = -1;
    return;
}
/// Displays a given menu
void MenuBar::displayMenu(Menu _menu, bool _isSelected)
{
    int startX = _menu.getStartX();
    string text = _menu.getText();
    if(_isSelected)
        wattron(win, A_STANDOUT);
    mvwprintw(win, 0, startX, text.c_str());
    wattroff(win, A_STANDOUT);
    wrefresh(win);

    int ch; // input character
    displayMenuItems(_menu);
    wrefresh(menuWin);
    while(_isSelected && (ch = wgetch(menuWin)))
    {
        switch (ch)
        {
        case KEY_DOWN:
            _menu.selectNextItem();
            break;
        case KEY_UP:
            _menu.selectPrevItem();
            break;
        default:
            _isSelected = false;
            break;
        }
        displayMenuItems(_menu);
    }
    werase(menuWin);
    wrefresh(menuWin);
    reset();
    return;
}

/// Displays the items in a menu
void MenuBar::displayMenuItems(Menu _menu)
{
    int xMax = getmaxx(menuWin);
    for(int i = 0; i < _menu.getNumItems(); i++)
    {
        mvwprintw(menuWin, i, 0, _menu.getItems()[i].c_str());
        if(_menu.getSelectedItem() == i)
        {
            // if selected, change to color pair 1
            mvwchgat(menuWin, i, 0, xMax, A_NORMAL, 1, NULL);
        }
        else
        {
            // not selected, but still reversed
            mvwchgat(menuWin, i, 0, xMax, A_STANDOUT, 0, NULL);
        }
    }
    return;
}
void MenuBar::handleTrigger(char _trigger)
{
    for(int i = 0; i < numMenus; i++)
    {
        if(_trigger == menus[i].getTrigger())
        {
            selectedMenu = i;
        }
    }
    return;
}

void MenuBar::reset()
{
    for (int i = 0; i < numMenus ; i++)
    {
        int startX = menus[i].getStartX();
        string text = menus[i].getText();
        mvwprintw(win, 0, startX, text.c_str());
    }
    wrefresh(win);
    return;
}
