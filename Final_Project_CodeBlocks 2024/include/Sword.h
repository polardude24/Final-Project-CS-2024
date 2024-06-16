#ifndef SWORD_H
#define SWORD_H

#include <Item.h>


class Sword : public Item
{
    public:
        Sword();
        virtual ~Sword();

        void use();

    protected:

    private:
};

#endif // SWORD_H
