#include "Tile.h"

Tile::Tile()
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}
Tile::Tile(WINDOW* _curWin, int _posY, int _posX, char _type, bool _isTraversable, chtype _color)
{
    curWin = _curWin;
    posY = _posY;
    posX = _posX;
    type = _type;
    isTraversable = _isTraversable;
    color = _color;
    isCrumb = false;
    item = nullptr;
}

void Tile::display() // Displays a tile in its window
{
    if(item != nullptr)
    {
        wattron(curWin, COLOR_PAIR(3));
        mvwprintw(curWin, posY+1, (2*posX)+1, "%c%c", item->getType(),item->getType());
        wattroff(curWin, COLOR_PAIR(3));
    }
    else if(isCrumb)
    {
        wattron(curWin, color);
        mvwprintw(curWin, posY+1, (2*posX)+1, "..");
        wattroff(curWin, color);
    }
    else
    {
        wattron(curWin, color);
        mvwprintw(curWin, posY+1, (2*posX)+1, "%c%c",type,type);
        wattroff(curWin, color);
    }
    return;
}
