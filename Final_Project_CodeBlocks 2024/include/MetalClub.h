#ifndef METALCLUB_H
#define METALCLUB_H

#include <Item.h>


class MetalClub : public Item
{
    public:
        MetalClub();
        MetalClub(WINDOW * _curWin);
        virtual ~MetalClub();

        void use();

    protected:

    private:
};

#endif // METALCLUB_H
