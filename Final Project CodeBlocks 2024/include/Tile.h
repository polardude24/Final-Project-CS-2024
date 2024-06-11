#ifndef TILE_H
#define TILE_H

#include <Utility.h>


class Tile : public Utility
{
    public:
        Tile();
        Tile(WINDOW * _curWin, int posY, int posX, char _type, bool isTraversable);
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

        void display();

    protected:
        WINDOW * curWin;
        int posX;
        int posY;
        char type;
        bool isTraversable;
        bool isCrumb;

    private:
};

#endif // TILE_H
