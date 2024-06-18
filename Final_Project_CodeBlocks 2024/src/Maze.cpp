#include "Maze.h"
#include "Tile.h"

static const char wll = 219;
static const char spc = ' ';
static const char beg = 'B';
static const char ext = 'D';
static const char plr = 'P';
//static const char ite = ' ';

Maze::Maze(WINDOW* _curWin, int _choice)
{
    curWin = _curWin;

    switch(_choice)
    {
    case 1:
        mazeHeight = mazeWidth = 20;
        endPosY = 9;
        endPosX = 11;
        startPosY = 8;
        startPosX = 1;
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
        break;
    case 2:
        mazeHeight = mazeWidth = 30;
        endPosY = 24;
        endPosX = 25;
        startPosY = 1;
        startPosX = 1;
        for(int i = 0; i < mazeHeight; i++)
        {
            for(int j = 0; j < mazeWidth; j++)
            {
                if(mazeTemplate2[i][j] == wll) // checks to see if there's a wall there, if so then make the tile not traversable
                {
                    hardMaze2[i][j] = new Tile(curWin, i, j, mazeTemplate2[i][j], false, COLOR_PAIR(0));
                }
                else if (mazeTemplate2[i][j] == ext)
                {
                    hardMaze2[i][j] = new Tile(curWin, i, j, mazeTemplate2[i][j], true, COLOR_PAIR(4));
                }
                else
                {
                    hardMaze2[i][j] = new Tile(curWin, i, j, mazeTemplate2[i][j], true, COLOR_PAIR(0));
                }
            }
        }
        break;
    case 3:
        mazeHeight = mazeWidth = 40;
        endPosY = 2;
        endPosX = 22;
        startPosY = 25;
        startPosX = 2;
        for(int i = 0; i < mazeHeight; i++)
        {
            for(int j = 0; j < mazeWidth; j++)
            {
                if(mazeTemplate3[i][j] == wll) // checks to see if there's a wall there, if so then make the tile not traversable
                {
                    hardMaze3[i][j] = new Tile(curWin, i, j, mazeTemplate3[i][j], false, COLOR_PAIR(0));
                }
                else if (mazeTemplate3[i][j] == ext)
                {
                    hardMaze3[i][j] = new Tile(curWin, i, j, mazeTemplate3[i][j], true, COLOR_PAIR(4));
                }
                else
                {
                    hardMaze3[i][j] = new Tile(curWin, i, j, mazeTemplate3[i][j], true, COLOR_PAIR(0));
                }
            }
        }
        break;
    default:
        break;
    }
}

Maze::~Maze()
{
    //dtor
}




// TO ADD: MAKE IT SO THAT IT DISPLAYS THE "CURRENT" MAZE, AND EACH MAZE GETS INITIALIZED WITH WHICH HARDCODED MAZE, OR TO GENERATE A MAZE







void Maze::display(int _whichMaze) // Display the maze, iterating through each space
{
    switch(_whichMaze)
    {
    case 1:
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
        break;
    case 2:
        for(int i = 0; i < mazeHeight; i++)
        {
            for(int j = 0; j < mazeWidth; j++)
            {
                if(hardMaze2[i][j] != nullptr)
                {
                    hardMaze2[i][j]->display();
                }
            }
        }
        break;
    }
    return;
}

const char Maze::mazeTemplate1[20][20] = {
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,spc,spc,spc,wll,wll,wll,spc,spc,spc,wll,wll},
{wll,wll,wll,spc,spc,spc,spc,spc,wll,spc,wll,wll,wll,spc,spc,spc,wll,spc,spc,wll},
{wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,spc,wll,wll,wll,wll,spc,wll},
{wll,wll,wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,spc,spc,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,wll,spc,wll,wll,wll,wll},
{wll,wll,wll,spc,spc,spc,wll,wll,wll,spc,wll,wll,spc,spc,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,spc,spc,spc,spc,wll,spc,wll,wll},
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

const char Maze::mazeTemplate2[30][30] = {
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,beg,spc,spc,wll,wll,wll,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,spc,wll,wll,spc,spc,spc,wll,wll,spc,spc,wll,spc,wll},
{wll,spc,wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,spc,spc,spc,spc,spc,spc,wll,wll,wll,wll,spc,wll,wll,spc,wll,wll,spc,wll},
{wll,spc,wll,spc,spc,spc,spc,spc,wll,spc,wll,wll,spc,wll,spc,spc,wll,spc,spc,spc,spc,spc,spc,spc,spc,spc,spc,spc,spc,wll},
{wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,spc,wll,wll,wll,wll,spc,wll,wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll},
{wll,spc,wll,spc,spc,wll,spc,spc,spc,spc,wll,spc,spc,spc,spc,spc,spc,wll,wll,wll,wll,wll,spc,wll,spc,spc,spc,wll,spc,wll},
{wll,spc,wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,spc,wll,spc,wll,spc,spc,spc,spc,spc,wll,spc,wll,spc,spc,spc,wll},
{wll,spc,spc,spc,spc,spc,spc,spc,wll,spc,wll,spc,spc,wll,spc,wll,spc,wll,spc,wll,spc,wll,spc,wll,spc,spc,wll,wll,spc,wll},
{wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,spc,wll,spc,wll,spc,wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,spc,spc,wll},
{wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll,spc,spc,spc,spc,wll,spc,spc,spc,wll,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll},
{wll,spc,spc,wll,spc,spc,spc,spc,wll,spc,wll,spc,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,spc,wll,spc,wll},
{wll,wll,spc,spc,spc,wll,wll,spc,wll,spc,spc,spc,wll,wll,spc,spc,spc,wll,wll,wll,spc,wll,spc,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,spc,wll,wll,wll,wll,spc,wll,wll,wll,wll,wll,wll,wll,wll,spc,spc,spc,wll,spc,wll,spc,wll,wll,wll,wll,wll,wll,wll},
{wll,spc,spc,wll,spc,spc,wll,spc,wll,spc,spc,spc,spc,spc,wll,wll,wll,wll,wll,wll,spc,wll,spc,spc,spc,wll,wll,wll,wll,wll},
{wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,spc,spc,spc,spc,wll},
{wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,wll,spc,spc,spc,spc,spc,spc,spc,spc,wll,spc,spc,wll,spc,wll,spc,wll,wll},
{wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,wll,wll,spc,wll,wll,spc,wll,spc,wll,wll,wll,wll},
{wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,wll,spc,spc,wll,wll,spc,wll,spc,wll,spc,spc,wll},
{wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,spc,spc,spc,spc,spc,spc,wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,wll,wll,spc,wll},
{wll,spc,wll,wll,wll,spc,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,wll,spc,wll,spc,wll,spc,wll,spc,spc,spc,spc,wll},
{wll,spc,spc,spc,wll,spc,wll,spc,wll,spc,spc,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,spc,wll,spc,wll,spc,wll,spc,wll,wll},
{wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,spc,spc,spc,spc,spc,spc,wll,spc,spc,wll},
{wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,spc,wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,spc,wll,spc,wll,spc,wll,spc,spc,spc,spc,spc,wll,spc,spc,spc,wll,spc,spc,spc,wll,spc,spc,spc,spc,spc,spc,spc,wll,wll},
{wll,spc,wll,spc,wll,spc,wll,spc,wll,wll,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll,wll,ext,wll,spc,wll,wll},
{wll,spc,wll,spc,wll,spc,spc,spc,spc,spc,spc,spc,spc,spc,spc,spc,wll,wll,wll,wll,wll,spc,wll,spc,wll,wll,wll,spc,wll,wll},
{wll,spc,wll,spc,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,spc,spc,spc,spc,spc,spc,wll,spc,wll,spc,wll,spc,wll,wll},
{wll,spc,spc,spc,spc,spc,wll,wll,wll,wll,wll,spc,spc,spc,spc,wll,spc,wll,wll,wll,wll,wll,wll,spc,spc,spc,wll,spc,wll,wll},
{wll,wll,wll,wll,wll,spc,spc,spc,spc,spc,spc,spc,wll,wll,spc,spc,spc,wll,spc,spc,spc,spc,spc,spc,wll,spc,spc,spc,spc,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
};

const char Maze::mazeTemplate3[40][40] = {
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,ext,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,beg,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
{wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll,wll},
};
