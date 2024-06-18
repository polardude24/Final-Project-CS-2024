#ifndef WEAPON_H
#define WEAPON_H

#include <Item.h>


class Weapon : public Item
{
    public:
        Weapon();
        Weapon(WINDOW * _curWin, string _name, char _type, float _strengthModifier, bool _multiply);
        virtual ~Weapon();

        bool getMultiply(){return multiply;}

        float use();

    protected:

    private:
        float strengthModifier;
        bool multiply;
};

#endif // WEAPON_H
