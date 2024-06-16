#include "Maze.h"
#include "Tile.h"

static const char wll = 219;
static const char spc = ' ';
static const char beg = 'B';
static const char ext = 'D';
static const char plr = 'P';
//static const char ite = ' ';

Maze::Maze(WINDOW* _curWin, int _mazeHeight, int _mazeWidth, int _endPosY, int _endPosX, int _startPosY, int _startPosX)
{
    curWin = _curWin;
    //fogDistance = _fogDistance;
    mazeHeight = _mazeHeight;
    mazeWidth = _mazeWidth;
    endPosX = _endPosX;
    endPosY = _endPosY;
    startPosX = _startPosX;
    startPosY = _startPosY;


    for(int i = 0; i < mazeHeight; i++)
    {
        for(int j = 0; j < mazeWidth; j++)
        {
            if(mazeTemplate1[i][j] == wll) // checks to see if there's a wall there, if so then make the tile not traversable
            {
                hardMaze1[i][j] = new Tile(curWin, i, j, mazeTemplate1[i][j], false, COLOR_PAIR(0));
            }
            else if (mazeTemplate1[i][j] == ext)
            {
                hardMaze1[i][j] = new Tile(curWin, i, j, mazeTemplate1[i][j], true, COLOR_PAIR(4));
            }
            else
            {
                hardMaze1[i][j] = new Tile(curWin, i, j, mazeTemplate1[i][j], true, COLOR_PAIR(0));
            }
        }
    }
}

Maze::~Maze()
{
    //dtor
}




// TO ADD: MAKE IT SO THAT IT DISPLAYS THE "CURRENT" MAZE, AND EACH MAZE GETS INITIALIZED WITH WHICH HARDCODED MAZE, OR TO GENERATE A MAZE







void Maze::display(bool _useHardMaze) // Display the maze, iterating through each space
{
    if(_useHardMaze)
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
    else
    {
        for(int i = 0; i < mazeHeight; i++)
        {
            for(int j = 0; j < mazeWidth; j++)
            {
                if(generatedMaze[i][j] != nullptr)
                {
                   generatedMaze[i][j]->display();
                }
            }
        }
    }
    return;
}

const char Maze::mazeTemplate1[20][20] = {
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,spc,spc,spc,wll,wll,wll,spc,spc,spc,wll,wll},
{wll,wll,wll,spc,spc,spc,spc,spc,wll,spc,wll,wll,wll,spc,spc,spc,wll,spc,spc,wll},
{wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,spc,wll,wll,wll,wll,spc,wll},
{wll,wll,wll,spc,wll,spc,spc,spc,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,wll,wll,wll,wll},
{wll,wll,wll,spc,spc,spc,wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,spc,spc,spc,wll,spc,wll,wll},
{wll,beg,spc,spc,wll,spc,wll,wll,wll,spc,wll,wll,spc,spc,wll,spc,spc,spc,wll,wll},
{wll,wll,wll,wll,wll,spc,wll,spc,spc,spc,wll,ext,spc,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,spc,spc,spc,wll,spc,wll,wll,wll,wll,spc,wll,wll,wll,wll,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,spc,spc,spc,wll,wll,spc,wll,spc,wll,wll,spc,wll,wll},
{wll,wll,wll,spc,wll,spc,wll,spc,wll,spc,spc,spc,spc,spc,spc,spc,spc,spc,wll,wll},
{wll,spc,spc,spc,spc,spc,wll,spc,spc,spc,wll,wll,wll,wll,wll,wll,wll,spc,wll,wll},
{wll,spc,wll,wll,wll,spc,spc,spc,wll,wll,wll,wll,wll,spc,spc,spc,spc,spc,spc,wll},
{wll,spc,wll,wll,wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,wll,wll,wll,spc,wll,wll},
{wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,wll,wll},
{wll,spc,spc,spc,wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,wll,wll},
{wll,wll,wll,spc,wll,wll,wll,spc,spc,spc,wll,spc,spc,spc,spc,spc,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
};
