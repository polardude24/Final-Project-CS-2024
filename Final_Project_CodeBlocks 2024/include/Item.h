#ifndef ITEM_H
#define ITEM_H

#include <Utility.h>

class Player;

class Item : public Utility
{
    public:
        Item();
        Item(WINDOW * _curWin, string _name, char _type);
        virtual ~Item();

        char getType();
        string getName();

        void display(WINDOW*);
        virtual void use(Player* _player);
        //virtual void makeThisClassAbstractWeeeee() = 0;

    protected:
        WINDOW * curWin;
        Player * player;
        char type;
        string name;
        string info;

    private:
};

#endif // ITEM_H
