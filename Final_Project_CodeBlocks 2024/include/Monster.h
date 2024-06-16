#ifndef MONSTER_H
#define MONSTER_H

#include <Entity.h>


class Monster : public Entity
{
    public:
        Monster();

        using Entity::Entity; // inherirts ALL of Entity's constructors
        Monster(WINDOW* _curWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type);
        virtual ~Monster();

        void setIsInCombat(bool val){isInCombat = val;}
        bool getIsInCombat(){return isInCombat;}

        void moveMonster(char _input);
        void display();

    protected:

    private:
        bool isInCombat;
};

#endif // MONSTER_H
