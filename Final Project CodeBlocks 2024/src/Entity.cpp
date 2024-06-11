#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

void Entity::moveEntity(char _input)
{
    //int max
    mvwprintw(curWin, posY, posX, "..");
    switch (_input)
    {
    case KEY_UP:
        posY-=2;
        if(posY)
        break;
    case KEY_DOWN:
        posY+=2;
        break;
    case KEY_LEFT:
        posX-=2;
        break;
    case KEY_RIGHT:
        posX+=2;
        break;
    case 'w':
        posY-=2;
        break;
    case 's':
        posY+=2;
        break;
    case 'a':
        posX-=2;
        break;
    case 'd':
        posX+=2;
        break;
    default:
        break;
    }

    return;
}
void Entity::display()
{
    mvwprintw(curWin, posY, posX, "%c%c",type,type); // doubled to make it square
    return;
}
