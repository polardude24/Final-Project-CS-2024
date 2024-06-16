#ifndef SCYTHE_H
#define SCYTHE_H

#include <Item.h>


class Scythe : public Item
{
    public:
        Scythe();
        virtual ~Scythe();

        void use();

    protected:

    private:
};

#endif // SCYTHE_H
