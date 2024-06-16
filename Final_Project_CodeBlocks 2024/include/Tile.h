#ifndef TILE_H
#define TILE_H

#include <Utility.h>
#include "Item.h"


class Tile : public Utility
{
    public:
        Tile();
        Tile(WINDOW * _curWin, int posY, int posX, char _type, bool isTraversable, chtype _color);
        virtual ~Tile();

        int getPosX() { return posX; }
        void setPosX(int val) { posX = val; }
        int getPosY() { return posY; }
        void setPosY(int val) { posY = val; }
        char getType() { return type; }
        void setType(char val) { type = val; }
        bool getIsTraversable() { return isTraversable; }
        void setIsTraversable(bool val) { isTraversable = val; }
        bool getIsCrumb() { return isCrumb; }
        void setIsCrumb(bool val) { isCrumb = val; }
        void setItem(Item* val){item = val;}
        Item * getItem(){return item;}
        chtype getColor(){return color;}
        void setIsOccupied(bool val){isOccupied = val;}
        bool getIsOccupied(){return isOccupied;}

        void display();

    protected:
        WINDOW * curWin;
        Item* item;
        chtype color;
        int posX;
        int posY;
        char type;
        bool isTraversable;
        bool isCrumb;
        bool isOccupied;

    private:
};

#endif // TILE_H
