#ifndef GAME_H
#define GAME_H

#include <Utility.h>
#include "Maze.h"
#include "Menu.h"
#include "MenuBar.h"
#include "Maze.h"
#include "Tile.h"
#include "Utility.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "LinkedList.h"
#include "Node.h"
#include "Weapon.h"
#include "Consumable.h"
#include "AutoSolver.h"

class Game : public Utility
{
    public:
        Game();
        Game(bool _autoSolverFlag, int _mazeChoice);
        virtual ~Game();

        WINDOW * getMazeWin(){return mazeWin;}
        WINDOW * getInventoryWin(){return inventoryWin;}
        WINDOW * getCombatWin(){return combatWin;}
        WINDOW * getConsoleWin(){return consoleWin;}
        int getSelectedWin(){return selectedWin;}

        void initializeGame();
        void runGame();
        void checkCombat();
        void displayMaze();
        void displayInventory();
        void displayCombat();
        void displayConsole();
        void displayMonsters();
        void handleInput(int);
        void moveMonsters();
        void resetWins();
        bool didWin();
        bool didWinAutoSolver();
        void printToConsole(string _input);

        void handleCombat(int _input);
        void playerAttack();
        void monsterAttack();

        void displayStack(Stack* _stack, int _line);

        void handleInventory();

        void highlightMaze();
        void highlightInventory();
        void highlightCombat();

        Item * generateItem();

        static const int numMonsters = 15;
        static const int numItemTypes = 9;

    protected:

    private:
        WINDOW * mazeWin;
        WINDOW * inventoryWin;
        WINDOW * combatWin;
        WINDOW * consoleWin;
        Maze * maze;
        Player * player;
        AutoSolver * autoSolver;
        Monster * monsters[numMonsters];
        Monster * monsterInCombat;
        Item * selectedItem;
        LinkedList * inventory;
        int selectedWin;
        bool isInCombat;
        bool autoSolverFlag;
        int mazeChoice;
};

#endif // GAME_H
