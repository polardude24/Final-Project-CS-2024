#ifndef MAZE_H
#define MAZE_H

#include <Utility.h>
#include "Tile.h"

class Maze : public Utility
{
    public:
        Maze();
        virtual ~Maze();

        int getFogDistance() { return fogDistance; }
        void setFogDistance(int val) { fogDistance = val; }
        int getMazeHeight() { return mazeHeight; }
        void setMazeHeight(int val) { mazeHeight = val; }
        int getMazeWidth() { return mazeWidth; }
        void setMazeWidth(int val) { mazeWidth = val; }
        int getEndPosX() { return endPosX; }
        void setEndPosX(int val) { endPosX = val; }
        int getEndPosY() { return endPosY; }
        void setEndPosY(int val) { endPosY = val; }

        int fogDistance;
        Tile* maze1[20][20];
        Tile* maze2[20][20];
        int endPosX;
        int endPosY;

    protected:

    private:
        int mazeHeight;
        int mazeWidth;
};

#endif // MAZE_H
