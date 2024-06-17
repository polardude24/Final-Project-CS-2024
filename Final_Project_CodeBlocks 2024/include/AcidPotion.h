#ifndef ACIDPOTION_H
#define ACIDPOTION_H

#include <Item.h>


class AcidPotion : public Item
{
    public:
        AcidPotion();
        AcidPotion(WINDOW * _curWin);
        virtual ~AcidPotion();

        void use();

    protected:

    private:
};

#endif // ACIDPOTION_H
