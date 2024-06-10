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

        WINDOW * win;
        Menu * menus;
        int numMenus;
        int selectedMenu;

        void display();
        void handleTrigger(char _trigger);
    protected:

    private:
};

#endif // MENUBAR_H
