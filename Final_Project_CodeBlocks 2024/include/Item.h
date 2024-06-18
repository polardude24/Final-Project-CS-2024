#ifndef ITEM_H
#define ITEM_H

#include <Utility.h>

class Item : public Utility
{
    public:
        Item();
        Item(WINDOW * _curWin, string _name, char _type);
        virtual ~Item();

        char getType();
        string getName();

        void display(WINDOW*);
        virtual float use();
        virtual bool getMultiply();
        //virtual void makeThisClassAbstractWeeeee() = 0;

    protected:
        WINDOW * curWin;
        char type;
        string name;
        string info;

    private:
};

#endif // ITEM_H
