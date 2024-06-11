#include "Game.h"
#include "curses.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

// Setup all windows, generate maze, and initialize everything else
void Game::initializeGame()
{
    // Setup windows------------------------------------------||
    mazeWin = newwin(40,80,2,2); // Sets up window
    box(mazeWin,0,0); // Creates border
    refresh();
    wrefresh(mazeWin); // Refreshes the window

    inventoryWin = newwin(10, 120, 2, 82);
    box(inventoryWin,0,0);
    refresh();
    wrefresh(inventoryWin);

    combatWin = newwin(30,120, 12, 82);
    box(combatWin,0,0);
    refresh();
    wrefresh(combatWin);

    consoleWin = newwin(10, 200, 42, 2);
    box(consoleWin,0,0);
    refresh();
    wrefresh(consoleWin);

    mvwprintw(mazeWin, 0,2, "MAZE WINDOW");
    wrefresh(mazeWin);
    mvwprintw(inventoryWin, 0,2, "INVENTORY WINDOW");
    wrefresh(inventoryWin);
    mvwprintw(combatWin, 0,2, "COMBAT WINDOW");
    wrefresh(combatWin);
    mvwprintw(consoleWin, 0,2, "CONSOLE WINDOW");
    wrefresh(consoleWin);
    //---------------------------------------------------------||

    // Setup maze
    Maze maze1(mazeWin, 20,20,8,12);
    maze1.display();
    wrefresh(mazeWin);

    getch();
    getch();

    refresh();

    return;
}
// Meat of the logic for the gameloop. Many, many lines of code...
void Game::runGame()
{

    return;
}

// Checks to see if combat should happen
bool Game::checkCombat()
{
    return false;
}

// Displays the player's inventory in its window
void Game::displayInventory()
{

    return;
}

// Displays the combat in its window
void Game::displayCombat()
{

    return;
}

// Displays the log of everything that happens (may or may not get to this)
void Game::displayConsole()
{

    return;
}

// Handles all the player input, including menu navigation
void Game::handleInput()
{

    return;
}

// Checks to see if the game has been won yet
bool Game::didWin()
{
    return false;
}
