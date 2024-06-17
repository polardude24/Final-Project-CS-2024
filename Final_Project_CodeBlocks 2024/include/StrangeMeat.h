#ifndef STRANGEMEAT_H
#define STRANGEMEAT_H

#include <Item.h>


class StrangeMeat : public Item
{
    public:
        StrangeMeat();
        StrangeMeat(WINDOW * _curWin);
        virtual ~StrangeMeat();

        void use();

    protected:

    private:
};

#endif // STRANGEMEAT_H
