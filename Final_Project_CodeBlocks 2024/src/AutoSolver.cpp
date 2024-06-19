#include "AutoSolver.h"

AutoSolver::AutoSolver(WINDOW* _curWin, Maze* _curMaze, int _posY, int _posX, int _mazeChoice)
{
    curWin = _curWin;
    curMaze = _curMaze;
    posY = _posY;
    posX = _posX;
    stackMain = new Stack();
    stackBacktrack = new Stack();
    stackExit = new Stack();
    hasKey = false;
    lastMove = ' ';
    hasMetExit = false;
    mazeChoice = _mazeChoice;
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
void AutoSolver::moveAutoSolver()
{
    /**
    Pseudocode:

    load the opposite of the last moved direction onto the stack first (so that it's tried last for each space)
    load the other three directions onto the stack, in order

    pop the top of the stack, if can move there move there, and add opposite of that direction to the backTracking stack
    if cannot move there, do nothing and pop the next one, up to 4 times
    if the direction to move moves the solver onto a crumb, backtrack once, popping off both the main stack and backtrackingstack

    if moving for whatever reason after having met the end of the maze without the key, add the opposite of that move to the exit backtrack stack

    */
    if(posX == curMaze->getEndPosX() && posY == curMaze->getEndPosY()) // If at the exit wtihout key
    {
        hasMetExit = true;
    }
    if(hasKey && hasMetExit) // If the solver has been to the exit, and it finds the key, don't do any more searching and just backtrack along the 3rd stack
    {
        backTrackExit();
        return;
    }

    switch(mazeChoice)// Make its current position a crumb every time it moves
    {
    case 1:
        curMaze->hardMaze1[posY][posX]->setIsCrumb(true);
        break;
    case 2:
        curMaze->hardMaze2[posY][posX]->setIsCrumb(true);
        break;
    case 3:
        curMaze->hardMaze3[posY][posX]->setIsCrumb(true);
        break;
    default:
        break;
    }



    if(lastMove == ' ') // If the solver has not moved yet, try all 4 directions
    {
        loadStack();
        for(int i = 0; i < 4; i++)
        {
            char temp = stackMain->pop();
            if(checkDirection(temp))
            {
                moveDirection(temp);
                loadStack();
                switch(mazeChoice)
                {
                case 1:
                    if(curMaze->hardMaze1[posY][posX]->getItem() != nullptr)
                    {
                        if(curMaze->hardMaze1[posY][posX]->getItem()->getName() == "Key") // If it's the key
                        {
                            hasKey = true;
                            curMaze->hardMaze1[posY][posX]->setItem(nullptr);
                        }
                    }
                    break;
                case 2:
                    if(curMaze->hardMaze2[posY][posX]->getItem() != nullptr)
                    {
                        if(curMaze->hardMaze2[posY][posX]->getItem()->getName() == "Key") // If it's the key
                        {
                            hasKey = true;
                            curMaze->hardMaze2[posY][posX]->setItem(nullptr);
                        }
                    }
                    break;
                case 3:
                    if(curMaze->hardMaze3[posY][posX]->getItem() != nullptr)
                    {
                        if(curMaze->hardMaze3[posY][posX]->getItem()->getName() == "Key") // If it's the key
                        {
                            hasKey = true;
                            curMaze->hardMaze3[posY][posX]->setItem(nullptr);
                        }
                    }
                    break;
                default:
                    break;
                }

                return;
            }
        }
    }

    while(stackMain->peek() != stackBacktrack->peek())
    {
        char temp = stackMain->pop();
        if(checkDirection(temp))
        {
            moveDirection(temp);
            loadStack();
            switch(mazeChoice)
            {
            case 1:
                if(curMaze->hardMaze1[posY][posX]->getItem() != nullptr)
                {
                    if(curMaze->hardMaze1[posY][posX]->getItem()->getName() == "Key") // If it's the key
                    {
                        hasKey = true;
                        curMaze->hardMaze1[posY][posX]->setItem(nullptr);
                    }
                }
                break;
            case 2:
                if(curMaze->hardMaze2[posY][posX]->getItem() != nullptr)
                {
                    if(curMaze->hardMaze2[posY][posX]->getItem()->getName() == "Key") // If it's the key
                    {
                        hasKey = true;
                        curMaze->hardMaze2[posY][posX]->setItem(nullptr);
                    }
                }
                break;
            case 3:
                if(curMaze->hardMaze3[posY][posX]->getItem() != nullptr)
                {
                    if(curMaze->hardMaze3[posY][posX]->getItem()->getName() == "Key") // If it's the key
                    {
                        hasKey = true;
                        curMaze->hardMaze3[posY][posX]->setItem(nullptr);
                    }
                }
                break;
            default:
                break;
            }
            return;
        }
    }

    // If this code is running, that means that the solver has gotten to a dead end, and has to backtrack to try all the previous untried moves until it finds one that works
    backTrack();

    switch(mazeChoice)
    {
    case 1:
        if(curMaze->hardMaze1[posY][posX]->getItem() != nullptr)
        {
            if(curMaze->hardMaze1[posY][posX]->getItem()->getName() == "Key") // If it's the key
            {
                hasKey = true;
                curMaze->hardMaze1[posY][posX]->setItem(nullptr);
            }
        }
        break;
    case 2:
        if(curMaze->hardMaze2[posY][posX]->getItem() != nullptr)
        {
            if(curMaze->hardMaze2[posY][posX]->getItem()->getName() == "Key") // If it's the key
            {
                hasKey = true;
                curMaze->hardMaze2[posY][posX]->setItem(nullptr);
            }
        }
        break;
    case 3:
        if(curMaze->hardMaze3[posY][posX]->getItem() != nullptr)
        {
            if(curMaze->hardMaze3[posY][posX]->getItem()->getName() == "Key") // If it's the key
            {
                hasKey = true;
                curMaze->hardMaze3[posY][posX]->setItem(nullptr);
            }
        }
        break;
    default:
        break;
    }
    return;
}

void AutoSolver::loadStack()
{
    // Try in order left, down, right, up, with the last move always being first to be added
    switch(lastMove)
    {
    case 'd':
        stackMain->push('u');
        //stackMain->push('O');
        stackMain->push('l');
        stackMain->push('d');
        stackMain->push('r');
        break;
    case 'l':
        stackMain->push('r');
        //stackMain->push('O');
        stackMain->push('l');
        stackMain->push('d');
        stackMain->push('u');
        break;
    case 'u':
        stackMain->push('d');
        //stackMain->push('O');
        stackMain->push('l');
        stackMain->push('r');
        stackMain->push('u');
        break;
    case 'r':
        stackMain->push('l');
        //stackMain->push('O');
        stackMain->push('d');
        stackMain->push('r');
        stackMain->push('u');
        break;
    default:
        stackMain->push('l');
        stackMain->push('d');
        stackMain->push('r');
        stackMain->push('u');
        break;
    }
    return;
}

void AutoSolver::backTrack()
{
    // Backtracks one step, and Importantly adds to the 3rd stack if has met the end tile
    stackMain->pop();
    switch(stackBacktrack->pop())
    {
        case 'u':
            posY--;
            if(hasMetExit)
                stackExit->push('d');
            return;
        case 'r':
            posX++;
            if(hasMetExit)
                stackExit->push('l');
            return;
        case 'd':
            posY++;
            if(hasMetExit)
                stackExit->push('u');
            return;
        case 'l':
            posX--;
            if(hasMetExit)
                stackExit->push('r');
            return;
        default:
            return;
    }
}

bool AutoSolver::checkDirection(char _directionToCheck)
{
    // If the tile in the direction is traversable and is not a crumb tile, return true

    switch(mazeChoice)
    {
    case 1:
        switch(_directionToCheck)
        {
            case 'u':
                if(curMaze->hardMaze1[posY-1][posX]->getIsTraversable() && !curMaze->hardMaze1[posY-1][posX]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'r':
                if(curMaze->hardMaze1[posY][posX+1]->getIsTraversable() && !curMaze->hardMaze1[posY][posX+1]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'd':
                if(curMaze->hardMaze1[posY+1][posX]->getIsTraversable() && !curMaze->hardMaze1[posY+1][posX]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'l':
                if(curMaze->hardMaze1[posY][posX-1]->getIsTraversable() && !curMaze->hardMaze1[posY][posX-1]->getIsCrumb())
                {
                    return true;
                }
                break;
            default:
                break;
        }
        break;
    case 2:
        switch(_directionToCheck)
        {
            case 'u':
                if(curMaze->hardMaze2[posY-1][posX]->getIsTraversable() && !curMaze->hardMaze2[posY-1][posX]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'r':
                if(curMaze->hardMaze2[posY][posX+1]->getIsTraversable() && !curMaze->hardMaze2[posY][posX+1]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'd':
                if(curMaze->hardMaze2[posY+1][posX]->getIsTraversable() && !curMaze->hardMaze2[posY+1][posX]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'l':
                if(curMaze->hardMaze2[posY][posX-1]->getIsTraversable() && !curMaze->hardMaze2[posY][posX-1]->getIsCrumb())
                {
                    return true;
                }
                break;
            default:
                break;
        }
        break;
    case 3:
        switch(_directionToCheck)
        {
            case 'u':
                if(curMaze->hardMaze3[posY-1][posX]->getIsTraversable() && !curMaze->hardMaze3[posY-1][posX]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'r':
                if(curMaze->hardMaze3[posY][posX+1]->getIsTraversable() && !curMaze->hardMaze3[posY][posX+1]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'd':
                if(curMaze->hardMaze3[posY+1][posX]->getIsTraversable() && !curMaze->hardMaze3[posY+1][posX]->getIsCrumb())
                {
                    return true;
                }
                break;
            case 'l':
                if(curMaze->hardMaze3[posY][posX-1]->getIsTraversable() && !curMaze->hardMaze3[posY][posX-1]->getIsCrumb())
                {
                    return true;
                }
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }
    return false;
}

void AutoSolver::moveDirection(char _directionToMove)
{
    // Move the autosolver in the specified direction
    switch(_directionToMove)
    {
        case 'u':
            posY--;
            stackBacktrack->push('d');
            if(hasMetExit)
                stackExit->push('d');
            break;
        case 'r':
            posX++;
            stackBacktrack->push('l');
            if(hasMetExit)
                stackExit->push('l');
            break;
        case 'd':
            posY++;
            stackBacktrack->push('u');
            if(hasMetExit)
                stackExit->push('u');
            break;
        case 'l':
            posX--;
            stackBacktrack->push('r');
            if(hasMetExit)
                stackExit->push('r');
            break;
        default:
            break;
    }
    lastMove = _directionToMove;
    return;
}

void AutoSolver::backTrackExit()
{
    // Backtrack off of the exit stack
    switch(stackExit->pop())
    {
        case 'u':
            posY--;
            return;
        case 'r':
            posX++;
            return;
        case 'd':
            posY++;
            return;
        case 'l':
            posX--;
            return;
        default:
            return;
    }
    return;
}
