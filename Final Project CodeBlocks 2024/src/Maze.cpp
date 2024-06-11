#include "Maze.h"
#include "Tile.h"

const char wll = 219;
const char spc = ' ';
const char beg = 'B';
const char ext = 'X';
const char plr = 'P';

Maze::Maze(WINDOW* _curWin, int _mazeHeight, int _mazeWidth, int _endPosX, int _endPosY)
{
    curWin = _curWin;
    //fogDistance = _fogDistance;
    mazeHeight = _mazeHeight;
    mazeWidth = _mazeWidth;
    endPosX = _endPosX;
    endPosY = _endPosY;
    for(int i = 0; i < mazeHeight; i++)
    {
        for(int j = 0; j < mazeWidth; j++)
        {
            if(mazeTemplate1[i][j] == wll) // checks to see if there's a wall there, if so then make the tile not traversable
            {
                hardMaze1[i][j] = new Tile(curWin, i+1, (2*j)+1, mazeTemplate1[i][j], false);
            }
            else // else make it traversable
            {
                hardMaze1[i][j] = new Tile(curWin, i+1, (2*j)+1, mazeTemplate1[i][j], true);
            }
        }
    }
}

Maze::~Maze()
{
    //dtor
}

void Maze::display() // Display the maze, iterating through each space
{
    for(int i = 0; i < mazeHeight; i++)
    {
        for(int j = 0; j < mazeWidth; j++)
        {
            if(hardMaze1[i][j] != nullptr)
            {
               hardMaze1[i][j]->display();
            }
        }
    }
}

const char Maze::mazeTemplate1[20][20] = {
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,spc,spc,spc,wll,wll,wll,spc,spc,spc,wll,wll},
{wll,wll,wll,spc,spc,spc,spc,spc,wll,spc,wll,wll,wll,spc,spc,spc,wll,spc,spc,wll},
{wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,spc,wll,wll,wll,wll,spc,wll},
{wll,wll,wll,spc,wll,spc,spc,spc,wll,spc,wll,wll,wll,wll,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,wll,wll,spc,wll,wll,wll,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,wll,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,spc,spc,spc,wll,spc,wll,wll},
{wll,beg,spc,spc,wll,spc,wll,wll,wll,spc,wll,wll,spc,spc,wll,spc,spc,spc,wll,wll},
{wll,wll,wll,wll,wll,spc,wll,spc,spc,spc,wll,ext,spc,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,spc,spc,spc,wll,spc,wll,wll,wll,wll,spc,wll,wll,wll,wll,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,spc,spc,spc,wll,wll,spc,wll,spc,wll,wll,spc,wll,wll},
{wll,wll,wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,spc,spc,spc,spc,spc,spc,wll,wll},
{wll,spc,spc,spc,spc,spc,wll,spc,spc,spc,wll,wll,wll,wll,wll,wll,wll,spc,wll,wll},
{wll,spc,wll,wll,wll,spc,spc,spc,wll,wll,wll,wll,wll,spc,spc,spc,spc,spc,spc,wll},
{wll,spc,wll,wll,wll,spc,wll,spc,wll,wll,wll,wll,wll,spc,wll,wll,wll,spc,wll,wll},
{wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,spc,spc,spc,spc,spc,spc,wll,spc,wll,wll},
{wll,spc,spc,spc,wll,wll,wll,wll,wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll},
{wll,wll,wll,spc,wll,wll,wll,wll,spc,spc,wll,wll,wll,wll,wll,spc,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
};
