#ifndef GARLICCLOVE_H
#define GARLICCLOVE_H

#include <Item.h>


class GarlicClove : public Item
{
    public:
        GarlicClove();
        GarlicClove(WINDOW * _curWin);
        virtual ~GarlicClove();

        void use();

    protected:

    private:
};

#endif // GARLICCLOVE_H
