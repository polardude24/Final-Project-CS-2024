#include "Entity.h"

Entity::Entity()
{
    curWin = nullptr;
    curTile = nullptr;
    curMaze = nullptr;
    hp = 0;
    name = "";
    strength = 0;
    id = -1;
    posX = -1;
    posY = -1;
    isAlive = false;
    type = ' ';
}
Entity::Entity(WINDOW* _curWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type)
{
    curWin = _curWin;
    curTile = _curTile;
    curMaze = _curMaze;
    hp = _hp;
    name = _name;
    strength = _strength;
    id = _id;
    posX = curTile->getPosX();
    posY = curTile->getPosY();
    isAlive = true;
    type = _type;
    maxHP = hp;
}

Entity::~Entity()
{
    //dtor
}
