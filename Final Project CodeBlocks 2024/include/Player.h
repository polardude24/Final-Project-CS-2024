#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include "LinkedList.h"


class Player : public Entity
{
    public:
        Player();
        virtual ~Player();

        bool getHasKey() { return hasKey; }
        void setHasKey(bool val) { hasKey = val; }
        LinkedList * getInventory() { return inventory; }
        void setInventory(LinkedList * val) { inventory = val; }



    protected:

    private:
        bool hasKey;
        LinkedList * inventory;
};

#endif // PLAYER_H
