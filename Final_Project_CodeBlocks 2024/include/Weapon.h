#ifndef WEAPON_H
#define WEAPON_H

#include <Item.h>


class Weapon : public Item
{
    public:
        Weapon();
        Weapon(WINDOW * _curWin, string _name, char _type, float _strengthModifier);
        virtual ~Weapon();

        float GetstrengthModifier() { return strengthModifier; }
        void SetstrengthModifier(float val) { strengthModifier = val; }

        void use();

    protected:

    private:
        float strengthModifier;
};

#endif // WEAPON_H
