#ifndef MAGICSTAFF_H
#define MAGICSTAFF_H

#include <Item.h>


class MagicStaff : public Item
{
    public:
        MagicStaff();
        virtual ~MagicStaff();

        void use();

    protected:

    private:
};

#endif // MAGICSTAFF_H
