#include "AutoSolver.h"

AutoSolver::AutoSolver(WINDOW* _curWin, Maze* _curMaze, int _posY, int _posX)
{
    curWin = _curWin;
    curMaze = _curMaze;
    posY = _posY;
    posX = _posX;
    stackMain = new Stack();
    stackBacktrack = new Stack();
    hasKey = false;
    lastMove = ' ';
    //ctor
}

AutoSolver::~AutoSolver()
{
    //dtor
}

void AutoSolver::display()
{
    wattron(curWin, COLOR_PAIR(1));
    mvwprintw(curWin, posY+1, 2*posX+1, "AA");
    wattroff(curWin, COLOR_PAIR(1));
    return;
}
void AutoSolver::moveAutoSolver(char _input)
{
    // Add the last moved direction first to the stack VERY IMPORTANT
    // Have a second stack with all the backtracking moves which also is the way out
    // Leave breadcrumbs; If going to move onto breadcrumb, don't. Backtrack instead
    // When backtracking, do not add any new moves to the main stack

    loadStack();

    curMaze->hardMaze1[posY][posX]->setIsCrumb(true); // Make its current position a crumb every time it moves

    int numMovesTried = 0;

    while(numMovesTried < 4)
    {
        switch(stackMain->pop())
        {
            case 'u':
                if(curMaze->hardMaze1[posY-1][posX]->getIsTraversable() && !curMaze->hardMaze1[posY-1][posX]->getIsCrumb())
                {
                    posY--;
                    stackBacktrack->push('d');
                    lastMove = 'u';
                    numMovesTried = 100;
                }
                else if(curMaze->hardMaze1[posY-1][posX]->getIsCrumb())
                {
                    backTrack();
                    numMovesTried--;
                }
                break;
            case 'r':
                if(curMaze->hardMaze1[posY][posX+1]->getIsTraversable() && !curMaze->hardMaze1[posY][posX+1]->getIsCrumb())
                {
                    posX++;
                    stackBacktrack->push('l');
                    lastMove = 'r';
                    numMovesTried = 100;
                }
                else if(curMaze->hardMaze1[posY][posX+1]->getIsCrumb())
                {
                    backTrack();
                    numMovesTried--;
                }
                break;
            case 'd':
                if(curMaze->hardMaze1[posY+1][posX]->getIsTraversable() && !curMaze->hardMaze1[posY+1][posX]->getIsCrumb())
                {
                    posY++;
                    stackBacktrack->push('u');
                    lastMove = 'd';
                    numMovesTried = 100;
                }
                else if(curMaze->hardMaze1[posY+1][posX]->getIsCrumb())
                {
                    backTrack();
                    numMovesTried--;
                }
                break;
            case 'l':
                if(curMaze->hardMaze1[posY][posX-1]->getIsTraversable() && !curMaze->hardMaze1[posY][posX-1]->getIsCrumb())
                {
                    posX--;
                    stackBacktrack->push('r');
                    lastMove = 'l';
                    numMovesTried = 100;
                }
                else if(curMaze->hardMaze1[posY][posX-1]->getIsCrumb())
                {
                    backTrack();
                    numMovesTried--;
                }
                break;
            default:
                break;
        }
        mvwaddch(curWin,25+numMovesTried,25,_input);
        numMovesTried++;
    }
    if(curMaze->hardMaze1[posY][posX]->getItem() != nullptr)
    {
        if(curMaze->hardMaze1[posY][posX]->getItem()->getName() == "Key") // If it's the key
        {
            hasKey = true;
            curMaze->hardMaze1[posY][posX]->setItem(nullptr);
        }
    }
    return;
}

void AutoSolver::loadStack()
{
    switch(lastMove)
    {
    case 'd':
        stackMain->push('u');
        stackMain->push('r');
        stackMain->push('d');
        stackMain->push('l');
        break;
    case 'l':
        stackMain->push('r');
        stackMain->push('u');
        stackMain->push('d');
        stackMain->push('l');
        break;
    case 'u':
        stackMain->push('d');
        stackMain->push('u');
        stackMain->push('r');
        stackMain->push('l');
        break;
    case 'r':
        stackMain->push('l');
        stackMain->push('u');
        stackMain->push('r');
        stackMain->push('d');
        break;
    default:
        stackMain->push('u');
        stackMain->push('r');
        stackMain->push('d');
        stackMain->push('l');
        break;
    }
    return;
}

void AutoSolver::backTrack()
{
    switch(stackBacktrack->pop())
    {
        case 'u':
            posY--;
            break;
        case 'r':
            posX++;
            break;
        case 'd':
            posY++;
            break;
        case 'l':
            posX--;
            break;
        default:
            break;
    }
    return;
}
