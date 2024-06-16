#include "Player.h"

Player::Player()
{
    hasKey = false;
    inventory = nullptr;
    equippedItem = nullptr;
}
Player::Player(WINDOW* _curWin, WINDOW* _consoleWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type, LinkedList * _inventory) : Entity(_curWin, _curMaze, _curTile, _hp, _name, _strength, _id, _type)
{
    //Entity(_curWin, _curMaze, _curTile, _hp, _name, _strength, _id, _posY, _posX, _type); CHECK WITH MALOLEY
    /*
    curWin = _curWin;
    curTile = _curTile;
    curMaze = _curMaze;
    consoleWin = _consoleWin;
    hp = _hp;
    name = _name;
    strength = _strength;
    id = _id;
    posX = _posX;
    posY = _posY;
    isAlive = true;
    type = _type;
    */
    consoleWin = _consoleWin;
    hasKey = false;
    inventory = _inventory;
    maxHP = hp;
}
Player::~Player()
{
    //dtor
}

void Player::movePlayer(char _input)
{

    // Accidentally started writing code for the autosolver into entity. Oops!
    //curMaze->hardMaze1[posY][posX]->setIsCrumb(true);
    //if(curMaze->hardMaze1[posY][posX]->getType() != 'X' && curMaze->hardMaze1[posY][posX]->getType() != 'B') // if it isn't the beginning or end tile, change its display to ..
    //{
    //    curMaze->hardMaze1[posY][posX]->setType('.');
    //}

    int maxY, maxX;
    getmaxyx(curWin,maxY, maxX);

    curMaze->hardMaze1[posY][posX]->setIsOccupied(false);

    switch (_input)
    {
        case 'w':
            if(curMaze->hardMaze1[posY-1][posX]->getIsTraversable())
            {
                posY--;
                if(posY <= 0)
                    posY = 1;
            }
            break;
        case 's':
            if(curMaze->hardMaze1[posY+1][posX]->getIsTraversable())
            {
                posY++;
                if(posY >= maxY)
                    posY = maxY - 1;
            }
            break;
        case 'a':
            if(curMaze->hardMaze1[posY][posX-1]->getIsTraversable())
            {
                posX--;
                if(posX <= 0)
                    posX = 1;
            }
            break;
        case 'd':
            if(curMaze->hardMaze1[posY][posX+1]->getIsTraversable())
            {
                posX++;
                if(posX >= maxX)
                    posX = maxX-1;
            }
            break;
        default:
            break;
    }

    if(curMaze->hardMaze1[posY][posX]->getItem() != nullptr)
    {
        if(curMaze->hardMaze1[posY][posX]->getItem()->getName() == "Key") // If it's the key
        {
            hasKey = true;
        }
        inventory->insertEnd(curMaze->hardMaze1[posY][posX]->getItem());
        curMaze->hardMaze1[posY][posX]->setItem(nullptr);
        wmove(consoleWin, 1,1);
        winsdelln(consoleWin, 1);
        mvwprintw(consoleWin, 1, 1, "Picked up an item! Inventory count: %i", inventory->count());
        box(consoleWin, 0, 0);
        mvwprintw(consoleWin, 0,2, "CONSOLE WINDOW");
        wrefresh(consoleWin);
    }

    display();

    curMaze->hardMaze1[posY][posX]->setIsOccupied(true);

    return;
}

void Player::display()
{
    wattron(curWin, COLOR_PAIR(2));
    //if(inventory->count() != 0)
    //{
        //wattron(curWin, COLOR_PAIR(1));
    //}
    mvwprintw(curWin, posY+1, 2*posX+1, ":)"); // doubled to make it square
    wattroff(curWin, COLOR_PAIR(2));
    //wattroff(curWin, COLOR_PAIR(1));
    wrefresh(curWin);
    return;
}
