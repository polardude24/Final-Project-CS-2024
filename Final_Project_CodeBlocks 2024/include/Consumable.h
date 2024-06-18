#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <Item.h>


class Consumable : public Item
{
    public:
        Consumable();
        Consumable(WINDOW * _curWin, string _name, char _type, float _healthModifier, bool _multiply);
        virtual ~Consumable();

        bool getMultiply(){return multiply;}

        float use();

    protected:

    private:
        float healthModifier;
        bool multiply;
};

#endif // CONSUMABLE_H
