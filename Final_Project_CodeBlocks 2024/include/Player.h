#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include "LinkedList.h"
#include "Node.h"
#include "Item.h"


class Player : public Entity
{
    public:
        Player();
        using Entity::Entity; // inherit ALL of Entity's constructors
        //Player(WINDOW* _curWin, Maze* _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, int _posY, int _posX, bool _isAlive, char _type); // just in case I need this later
        Player(WINDOW* _curWin, WINDOW * consoleWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type, LinkedList * _inventory);
        virtual ~Player();

        bool getHasKey() { return hasKey; }
        void setHasKey(bool val) { hasKey = val; }
        LinkedList * getInventory() { return inventory; }
        void setInventory(LinkedList * val) { inventory = val; }
        void setMaxHP(float val){maxHP = val;}
        float getMaxHP(){return maxHP;}
        Item * getEquippedItem(){return equippedItem;}
        void setEquippedItem(Item* val){equippedItem = val;}

        void movePlayer(char _input);
        void display();

    protected:

    private:
        bool hasKey;
        WINDOW * consoleWin;
        LinkedList * inventory;
        Item * equippedItem;
};

#endif // PLAYER_H
