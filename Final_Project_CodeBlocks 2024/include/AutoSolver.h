#ifndef AUTOSOLVER_H
#define AUTOSOLVER_H

#include "Stack.h"
#include "Maze.h"
#include "Utility.h"

class AutoSolver : public Utility
{
    public:
        AutoSolver(WINDOW* _curWin, Maze* curMaze, int _posY, int _posX, int _mazeChoice);
        virtual ~AutoSolver();
        // Add the last moved direction first to the stack VERY IMPORTANT
        // Have a second stack with all the backtracking moves which also is the way out
        // Leave breadcrumbs; If going to move onto breadcrumb, don't. Backtrack instead

        int getPosX() { return posX; }
        void setPosX(int val) { posX = val; }
        int getPosY() { return posY; }
        void setPosY(int val) { posY = val; }
        bool getHasKey() { return hasKey; }
        void setHasKey(bool val) { hasKey = val; }
        Stack* getStackMain(){return stackMain;}
        Stack* getStackBackTrack(){return stackBacktrack;}

        void display();
        void moveAutoSolver();
        void loadStack();
        void backTrack();
        bool checkDirection(char _directionToCheck);
        void moveDirection(char _directionToMove);
        void backTrackExit();

    protected:

    private:
        Maze* curMaze;
        Stack* stackMain;
        Stack* stackBacktrack;
        Stack* stackExit; // A third stack to make the algorithm work. Is the list of moves from current pos to the exit
        char lastMove;
        int posX;
        int posY;
        bool hasKey;
        bool hasMetExit;
        int mazeChoice;
};

#endif // AUTOSOLVER_H
