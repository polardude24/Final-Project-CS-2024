#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <Item.h>


class Consumable : public Item
{
    public:
        Consumable();
        Consumable(WINDOW * _curWin, string _name, char _type);
        virtual ~Consumable();

        void use();

    protected:

    private:
};

#endif // CONSUMABLE_H
