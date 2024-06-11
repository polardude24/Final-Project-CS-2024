#include "Tile.h"

Tile::Tile()
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}
Tile::Tile(WINDOW* _curWin, int _posY, int _posX, char _type, bool _isTraversable)
{
    curWin = _curWin;
    posY = _posY;
    posX = _posX;
    type = _type;
    isTraversable = _isTraversable;
    isCrumb = false;
}

void Tile::display() // Displays a tile in its window
{
    mvwprintw(curWin, posY, posX, "%c%c",type,type);
    return;
}
