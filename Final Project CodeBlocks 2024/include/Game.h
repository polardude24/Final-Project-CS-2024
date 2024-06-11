#ifndef GAME_H
#define GAME_H

#include <Utility.h>
#include "Maze.h"


class Game : public Utility
{
    public:
        Game();
        virtual ~Game();

        WINDOW * getMazeWin(){return mazeWin;}
        WINDOW * getInventoryWin(){return inventoryWin;}
        WINDOW * getCombatWin(){return combatWin;}
        WINDOW * getConsoleWin(){return consoleWin;}

        void initializeGame();
        void runGame();
        bool checkCombat();
        void displayInventory();
        void displayCombat();
        void displayConsole();
        void handleInput();
        bool didWin();

    protected:

    private:
        WINDOW * mazeWin;
        WINDOW * inventoryWin;
        WINDOW * combatWin;
        WINDOW * consoleWin;

};

#endif // GAME_H
