#ifndef CLUB_H
#define CLUB_H

#include <Item.h>


class Club : public Item
{
    public:
        Club();
        virtual ~Club();

        void use();

    protected:

    private:
};

#endif // CLUB_H
