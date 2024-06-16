#ifndef METALCLUB_H
#define METALCLUB_H

#include <Item.h>


class MetalClub : public Item
{
    public:
        MetalClub();
        virtual ~MetalClub();

        void use();

    protected:

    private:
};

#endif // METALCLUB_H
