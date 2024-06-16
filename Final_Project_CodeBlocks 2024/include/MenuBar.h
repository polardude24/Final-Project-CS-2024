#ifndef MENUBAR_H
#define MENUBAR_H

#include <Utility.h>
#include "Menu.h"


class MenuBar : public Utility
{
    public:
        MenuBar();
        MenuBar(WINDOW * _win, Menu * _menus, int _numMenus);
        virtual ~MenuBar();

        WINDOW* getMenuWin(){return menuWin;}
        void setMenuWin(WINDOW* val){menuWin = val;}
        WINDOW* getwin(){return win;}
        void setWin(WINDOW* val){win = val;}
        Menu* getMenus(){return menus;}
        void setMenus(Menu* val){menus = val;}
        int getNumMenus(){return numMenus;}
        void setNumMenus(int val){numMenus = val;}
        int getSelectedMenu(){return selectedMenu;}
        void setSelectedMenu(int val){selectedMenu = val;}

        void display();
        void displayMenu(Menu, bool);
        void displayMenuItems(Menu);
        void handleTrigger(char _trigger);
        void reset();
    protected:

    private:
        WINDOW * menuWin;
        WINDOW * win;
        Menu * menus;
        int numMenus;
        int selectedMenu;
};

#endif // MENUBAR_H
