#include "Monster.h"

Monster::Monster()
{
    //ctor
}
Monster::Monster(WINDOW* _curWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type, int _mazeChoice) : Entity(_curWin, _curMaze, _curTile, _hp, _name, _strength, _id, _type, _mazeChoice)
{
    switch(mazeChoice)
    {
    case 1:
        curMaze->hardMaze1[posY][posX]->setIsTraversable(false);
        break;
    case 2:
        curMaze->hardMaze2[posY][posX]->setIsTraversable(false);
        break;
    case 3:
        curMaze->hardMaze3[posY][posX]->setIsTraversable(false);
        break;
    default:
        break;
    }
    isInCombat = false;
}

Monster::~Monster()
{
    //dtor
}

void Monster::moveMonster(char _input)
{

    if(curMaze == nullptr || curWin == nullptr)
    {
        return;
    }

    switch(mazeChoice)
    {
    case 1:
        curMaze->hardMaze1[posY][posX]->setIsTraversable(true);
        break;
    case 2:
        curMaze->hardMaze2[posY][posX]->setIsTraversable(true);
        break;
    case 3:
        curMaze->hardMaze3[posY][posX]->setIsTraversable(true);
        break;
    default:
        break;
    }

    switch (_input)
    {
        case 'u':
            posY--;
            break;
        case 'd':
            posY++;
            break;
        case 'l':
            posX--;
            break;
        case 'r':
            posX++;
            break;
        default:
            break;
    }

    switch(mazeChoice)
    {
    case 1:
        curMaze->hardMaze1[posY][posX]->setIsTraversable(false);
        break;
    case 2:
        curMaze->hardMaze2[posY][posX]->setIsTraversable(false);
        break;
    case 3:
        curMaze->hardMaze3[posY][posX]->setIsTraversable(false);
        break;
    default:
        break;
    }
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
