#include "Monster.h"

Monster::Monster()
{
    //ctor
}
Monster::Monster(WINDOW* _curWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type) : Entity(_curWin, _curMaze, _curTile, _hp, _name, _strength, _id, _type)
{
    curMaze->hardMaze1[posY][posX]->setIsOccupied(true);
    isInCombat = false;
}

Monster::~Monster()
{
    //dtor
}

void Monster::moveMonster(char _input)
{
    int maxY, maxX;
    getmaxyx(curWin,maxY, maxX);

    if(curMaze == nullptr)
    {
        return;
    }

    curMaze->hardMaze1[posY][posX]->setIsOccupied(false);

    switch (_input)
    {
        case 'u':
            posY--;
            if(posY <= 0)
                posY = 1;
            break;
        case 'd':
            posY++;
            if(posY >= maxY)
                posY = maxY - 1;
            break;
        case 'l':
            posX--;
            if(posX <= 0)
                posX = 1;
            break;
        case 'r':
            posX++;
            if(posX >= maxX)
                posX = maxX-1;
            break;
        default:
            break;
    }
    curMaze->hardMaze1[posY][posX]->setIsOccupied(true);
    return;
}


void Monster::display()
{
    wattron(curWin, COLOR_PAIR(5));
    mvwprintw(curWin, posY+1, 2*posX+1, "%c%c", type, type); // doubled to make it square
    wattroff(curWin, COLOR_PAIR(5));
    wrefresh(curWin);
    return;
}
