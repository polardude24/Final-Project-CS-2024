#ifndef ENTITY_H
#define ENTITY_H

#include <Utility.h>
#include "Tile.h"
#include "Maze.h"
#include "LinkedList.h"


class Entity : public Utility
{
    public:
        Entity();
        Entity(WINDOW* _curWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type);
        virtual ~Entity();

        float getHP() { return hp; }
        void setHP(float val) { hp = val; }
        string getName() { return name; }
        void setName(string val) { name = val; }
        float getStrength() { return strength; }
        void setStrength(float val) { strength = val; }
        int getId() { return id; }
        void setId(int val) { id = val; }
        int getPosX() { return posX; }
        void setPosX(int val) { posX = val; }
        int getPosY() { return posY; }
        void setPosY(int val) { posY = val; }
        bool getIsAlive() { return isAlive; }
        void setIsAlive(bool val) { isAlive = val; }
        char getType() { return type; }
        void setType(char val) { type = val; }
        float getMaxHP(){return maxHP;}
        void setMaxHP(float val){maxHP = val;}

    protected:
        WINDOW* curWin;
        Maze * curMaze;
        Tile * curTile;
        float hp;
        float maxHP;
        string name;
        float strength;
        int id;
        int posX;
        int posY;
        bool isAlive;
        char type;

    private:
};

#endif // ENTITY_H
