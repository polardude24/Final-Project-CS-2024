#ifndef AUTOSOLVER_H
#define AUTOSOLVER_H

#include "Stack.h"
#include "Maze.h"
#include "Utility.h"

class AutoSolver : public Utility
{
    public:
        AutoSolver(WINDOW* _curWin, Maze* curMaze, int _posY, int _posX);
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
        void moveAutoSolver(char _input);
        void loadStack();
        void backTrack();

    protected:

    private:
        WINDOW * _curWin;
        Maze* curMaze;
        Stack* stackMain;
        Stack* stackBacktrack;
        char lastMove;
        int posX;
        int posY;
        bool hasKey;
};

#endif // AUTOSOLVER_H
