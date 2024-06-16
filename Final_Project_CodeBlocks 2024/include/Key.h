#ifndef KEY_H
#define KEY_H

#include <Item.h>


class Key : public Item
{
    public:
        Key();
        Key(WINDOW* _curWin, int _id);
        virtual ~Key();

        void use();

    protected:

    private:
};

#endif // KEY_H
