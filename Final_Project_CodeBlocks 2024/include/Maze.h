#ifndef MAZE_H
#define MAZE_H

#include <Utility.h>
#include "Tile.h"

class Maze : public Utility
{
    public:
        Maze(WINDOW* _curWin, int _mazeHeight, int mazeWidth, int _endPosY, int _endPosX, int _startPosY, int _startPosX);
        virtual ~Maze();
        static const char mazeTemplate1[20][20];
        // getters and setters
        //int getFogDistance() { return fogDistance; }
        //void setFogDistance(int val) { fogDistance = val; }
        int getMazeHeight() { return mazeHeight; }
        void setMazeHeight(int val) { mazeHeight = val; }
        int getMazeWidth() { return mazeWidth; }
        void setMazeWidth(int val) { mazeWidth = val; }
        int getEndPosX() { return endPosX; }
        void setEndPosX(int val) { endPosX = val; }
        int getEndPosY() { return endPosY; }
        void setEndPosY(int val) { endPosY = val; }
        int getStartPosX(){return startPosX;}
        int getStartPosY(){return startPosY;}

        void display(bool _useHardMaze);
        Maze * generateMaze();

        // these HAVE to be public, because I have no clue how to return this in a get function
        Tile* hardMaze1[20][20];
        Tile* generatedMaze[40][40];

    protected:

    private:
        WINDOW * curWin;
        //int fogDistance;
        int mazeHeight;
        int mazeWidth;
        //const char mazeTemplate1[10][10];
        int endPosX;
        int endPosY;
        int startPosX;
        int startPosY;
};

#endif // MAZE_H
