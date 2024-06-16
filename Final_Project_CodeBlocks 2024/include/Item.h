#ifndef ITEM_H
#define ITEM_H

#include <Utility.h>

class Player;

class Item : public Utility
{
    public:
        Item();
        Item(WINDOW * _curWin, int _id, string _name, char _type);
        virtual ~Item();

        char getType();
        string getName();

        void display(WINDOW*);
        virtual void use();
        //virtual void makeThisClassAbstractWeeeee() = 0;

    protected:
        WINDOW * curWin;
        Player * player;
        int id;
        char type;
        string name;

    private:
};

#endif // ITEM_H
