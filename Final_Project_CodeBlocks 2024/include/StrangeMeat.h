#ifndef STRANGEMEAT_H
#define STRANGEMEAT_H

#include <Item.h>


class StrangeMeat : public Item
{
    public:
        StrangeMeat();
        virtual ~StrangeMeat();

        void use();

    protected:

    private:
};

#endif // STRANGEMEAT_H
