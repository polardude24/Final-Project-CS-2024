#include "Player.h"

Player::Player()
{
    hasKey = false;
    inventory = nullptr;
    equippedItem = nullptr;
}
Player::Player(WINDOW* _curWin, WINDOW* _consoleWin, Maze * _curMaze, Tile* _curTile, float _hp, string _name, float _strength, int _id, char _type, int _mazeChoice, LinkedList * _inventory) : Entity(_curWin, _curMaze, _curTile, _hp, _name, _strength, _id, _type, _mazeChoice)
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
    switch(mazeChoice) // Set itself to not traversable so that the monsters don't move onto the player's position immediately
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
}
Player::~Player()
{
    //dtor
}

void Player::movePlayer(char _input)
{
    switch(mazeChoice) // Set its own position to traversable
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

    switch(mazeChoice)
    {
    case 1:
        switch (_input)
        {
            // If can move in a direction, move in that direction
            case 'w':
                if(curMaze->hardMaze1[posY-1][posX]->getIsTraversable())
                {
                    posY--;
                }
                break;
            case 's':
                if(curMaze->hardMaze1[posY+1][posX]->getIsTraversable())
                {
                    posY++;
                }
                break;
            case 'a':
                if(curMaze->hardMaze1[posY][posX-1]->getIsTraversable())
                {
                    posX--;
                }
                break;
            case 'd':
                if(curMaze->hardMaze1[posY][posX+1]->getIsTraversable())
                {
                    posX++;
                }
                break;
            default:
                break;
        }
        break;
    case 2:
        switch (_input)
        {
            case 'w':
                if(curMaze->hardMaze2[posY-1][posX]->getIsTraversable())
                {
                    posY--;
                }
                break;
            case 's':
                if(curMaze->hardMaze2[posY+1][posX]->getIsTraversable())
                {
                    posY++;
                }
                break;
            case 'a':
                if(curMaze->hardMaze2[posY][posX-1]->getIsTraversable())
                {
                    posX--;
                }
                break;
            case 'd':
                if(curMaze->hardMaze2[posY][posX+1]->getIsTraversable())
                {
                    posX++;
                }
                break;
            default:
                break;
        }
        break;
    case 3:
        switch (_input)
        {
            case 'w':
                if(curMaze->hardMaze3[posY-1][posX]->getIsTraversable())
                {
                    posY--;
                }
                break;
            case 's':
                if(curMaze->hardMaze3[posY+1][posX]->getIsTraversable())
                {
                    posY++;
                }
                break;
            case 'a':
                if(curMaze->hardMaze3[posY][posX-1]->getIsTraversable())
                {
                    posX--;
                }
                break;
            case 'd':
                if(curMaze->hardMaze3[posY][posX+1]->getIsTraversable())
                {
                    posX++;
                }
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }

    switch(mazeChoice)
    {
    case 1:
        // If there is an item on the tile, pick it up
        if(curMaze->hardMaze1[posY][posX]->getItem() != nullptr)
        {
            if(curMaze->hardMaze1[posY][posX]->getItem()->getName() == "Key") // If it's the key, set the hasKey bool to true
            {
                hasKey = true;
            }
            inventory->insertEnd(curMaze->hardMaze1[posY][posX]->getItem()); // Add it to the inventory
            curMaze->hardMaze1[posY][posX]->setItem(nullptr); // Remove the item from that position in the maze
            // Print to the console that you picked up an item. Yes that is 6 lines of code.
            wmove(consoleWin, 1,1);
            winsdelln(consoleWin, 1);
            mvwprintw(consoleWin, 1, 1, "Picked up an item! Inventory count: %i", inventory->count());
            box(consoleWin, 0, 0);
            mvwprintw(consoleWin, 0,2, "CONSOLE WINDOW");
            wrefresh(consoleWin);
        }
        break;
    case 2:
        if(curMaze->hardMaze2[posY][posX]->getItem() != nullptr)
        {
            if(curMaze->hardMaze2[posY][posX]->getItem()->getName() == "Key") // If it's the key
            {
                hasKey = true;
            }
            inventory->insertEnd(curMaze->hardMaze2[posY][posX]->getItem());
            curMaze->hardMaze2[posY][posX]->setItem(nullptr);
            wmove(consoleWin, 1,1);
            winsdelln(consoleWin, 1);
            mvwprintw(consoleWin, 1, 1, "Picked up an item! Inventory count: %i", inventory->count());
            box(consoleWin, 0, 0);
            mvwprintw(consoleWin, 0,2, "CONSOLE WINDOW");
            wrefresh(consoleWin);
        }
        break;
    case 3:
        if(curMaze->hardMaze3[posY][posX]->getItem() != nullptr)
        {
            if(curMaze->hardMaze3[posY][posX]->getItem()->getName() == "Key") // If it's the key
            {
                hasKey = true;
            }
            inventory->insertEnd(curMaze->hardMaze3[posY][posX]->getItem());
            curMaze->hardMaze3[posY][posX]->setItem(nullptr);
            wmove(consoleWin, 1,1);
            winsdelln(consoleWin, 1);
            mvwprintw(consoleWin, 1, 1, "Picked up an item! Inventory count: %i", inventory->count());
            box(consoleWin, 0, 0);
            mvwprintw(consoleWin, 0,2, "CONSOLE WINDOW");
            wrefresh(consoleWin);
        }
        break;
    default:
        break;
    }

    // Set the player's position to non traversable at the end of every move
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

    display();
    return;
}

// displays the player...
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
