#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include <Item.h>


class HealthPotion : public Item
{
    public:
        HealthPotion();
        HealthPotion(WINDOW * _curWin);
        virtual ~HealthPotion();

        void use();

    protected:

    private:
};

#endif // HEALTHPOTION_H
