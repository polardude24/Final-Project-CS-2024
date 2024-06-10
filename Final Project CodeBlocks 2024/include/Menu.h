#ifndef MENU_H
#define MENU_H

#include <Utility.h>


class Menu : public Utility
{
    public:
        Menu();
        Menu(string _text, char _trigger);
        virtual ~Menu();

        int startX;
        string text;
        char trigger;

    protected:

    private:
};

#endif // MENU_H
