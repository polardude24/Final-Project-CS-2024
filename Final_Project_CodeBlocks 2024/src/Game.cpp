#include "Game.h"
#include "curses.h"
#include <string>
#include <cstdlib>
#include <ctime>

Game::Game()
{
    mazeWin = nullptr;
    inventoryWin = nullptr;
    combatWin = nullptr;
    consoleWin = nullptr;
    for(int i = 0; i < 5; i++)
    {
        monsters[i] = nullptr;
    }
    selectedWin = 0;
    isInCombat = false;
    selectedItem = nullptr;
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
    keypad(mazeWin, true);

    inventoryWin = newwin(25, 120, 2, 82);
    box(inventoryWin,0,0);
    refresh();
    wrefresh(inventoryWin);
    keypad(inventoryWin, true);

    combatWin = newwin(15,120, 27, 82);
    box(combatWin,0,0);
    refresh();
    wrefresh(combatWin);
    keypad(combatWin, true);

    consoleWin = newwin(10, 200, 42, 2);
    box(consoleWin,0,0);
    refresh();
    wrefresh(consoleWin);
    keypad(consoleWin, true);

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
    maze = new Maze(mazeWin, 20,20,9,11,8,1);

    // Setup player

    inventory = new LinkedList();

    player = new Player(mazeWin, consoleWin, maze, maze->hardMaze1[maze->getStartPosY()][maze->getStartPosX()], 100.0, "Jeff", 30.0, 1, 'P', inventory);

    // Setup monsters

    monsters[0] = new Monster(mazeWin, maze, maze->hardMaze1[10][18], 100.0, "Zombie", 20.0, 2, 'Z');
    monsters[1] = new Monster(mazeWin, maze, maze->hardMaze1[4][5], 75.0, "Skeleton", 12.0, 3, 'S');
    monsters[2] = new Monster(mazeWin, maze, maze->hardMaze1[6][9], 2.0, "Bat", 7000.0, 4, 'B');
    monsters[3] = new Monster(mazeWin, maze, maze->hardMaze1[13][3], 250.0, "Golem", 6.0, 5, 'G');
    monsters[4] = new Monster(mazeWin, maze, maze->hardMaze1[11][8], 150.0, "Ogre", 15, 6,'O');

    // Setup items
    for(int i = 1; i < numItems; i++)
    {
        items[i] = nullptr;
    }
    items[0] = new Key(inventoryWin, 1); // Makes the key
    maze->hardMaze1[18][8]->setItem(items[0]); // For debugging, makes the key generate in the maze



    // Display maze initially
    displayMaze();

    printToConsole("Game intialised. Ready to play and waiting for input!");
    printToConsole("Use the arrow keys to navigate between windows and menus, enter to select a window, and wasd to move your character");
    printToConsole("The monsters will move every time you do, except if you become beside them. Combat is initiated if your character is ever beside a monster.");

    refresh();
    //wgetch(consoleWin);

    return;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------||

// Meat of the logic for the gameloop. Many, many lines of code...
void Game::runGame()
{
    while(!didWin() && player->getIsAlive())// continue running the game until the player wins or dies
    {
        int input = wgetch(consoleWin);
        handleInput(input);
        displayCombat();
        displayInventory();
        displayConsole();
        if(!isInCombat) // If not in combat, check to see if the player should be in combat
        {
            checkCombat();
            displayCombat();
        }
        else
        {
            handleCombat(input);
            displayCombat();
        }

    }

    // Show that you won the game in the console
    printToConsole("YOU WON! YAY CONGRATS YOU'RE SO GOOD AT THE GAME");
    return;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------||

// Checks to see if combat should happen
void Game::checkCombat()
{
    for(int i = 0; i < numMonsters; i++) // check to see if any of the monsters are beside the player
    {
        if(monsters[i] != nullptr)
        {
            int mX = monsters[i]->getPosX();
            int mY = monsters[i]->getPosY();
            int x = player->getPosX();
            int y = player->getPosY();
            // Check to see if the player is beside a monster. Trust the boolean algebra
            if((mY == y && mX == x) || (mY+1 == y && mX == x) || (mY == y && mX+1 == x) || (mY-1 == y && mX == x) || (mY == y && mX-1 == x))
            {
                isInCombat = true;
                monsters[i]->setIsInCombat(true);
                monsterInCombat = monsters[i];
                printToConsole("Combat Initiated!");
                selectedWin = 2;
                resetWins();
                highlightCombat();
                return;
            }
        }
    }
    return;
}

void Game::displayMaze()
{
    highlightMaze();
    maze->display(true); // displays the hardcoded maze
    displayMonsters(); // displays all the monsters
    player->display();
    //wgetch(consoleWin);
    //maze->display(true); // displays the hardcoded maze


    //mvwprintw(consoleWin, 8,1,"Player position: (%i, %i)",player->getPosY(), player->getPosX()); // For debugging and enemy positioning purposes, displays what the current player position relative to the maze is

    wrefresh(mazeWin);
    return;
}

// Displays the player's inventory in its window
void Game::displayInventory()
{
    for(int i = 0; i < inventory->count(); i++)
    {
        mvwprintw(inventoryWin, i+1, 1, "Name: %s ",inventory->index(i)->getContent()->getName().c_str());
    }
    wrefresh(inventoryWin);
    return;
}

// Displays the combat in its window
void Game::displayCombat()
{
    mvwprintw(combatWin, 0,2, "COMBAT WINDOW");
    if(isInCombat)
    {
        int halfX = getmaxx(combatWin)/2;

        float monsterMaxHealth = monsterInCombat->getHP();

        // Display player stats

        wattron(combatWin, COLOR_PAIR(6));
        mvwprintw(combatWin, 1,1,"Player Health: %f", player->getHP());
        wattroff(combatWin, COLOR_PAIR(6));
        wattron(combatWin, COLOR_PAIR(0));
        mvwprintw(combatWin, 2,1,"|");
        // Display the player health as a health bar
        for(int i = 0; i < 50; i++)
        {
            if(i < player->getHP()/player->getMaxHP()*50)
            {
                mvwprintw(combatWin, 2, i+2,"%c", char(178));
            }
            else
            {
                mvwprintw(combatWin, 2, i+2,"%c", '-');
            }

        }
        mvwprintw(combatWin, 2, 52,"|");
        wattroff(combatWin, COLOR_PAIR(0));
        wattron(combatWin, COLOR_PAIR(6));
        mvwprintw(combatWin, 3, 1, "Player strength: %i", int(player->getStrength())); // Faster than changing all the variables to float
        if(player->getEquippedItem() != nullptr)
        {
            mvwprintw(combatWin, 4, 1, "Item equipped: %s", player->getEquippedItem()->getName().c_str());
        }
        else
        {
            mvwprintw(combatWin, 4, 1, "Item equipped: None, Equip one in the inventory");
        }
        wattroff(combatWin, COLOR_PAIR(6));

        // Display enemy stats
        wattron(combatWin, COLOR_PAIR(7));
        mvwprintw(combatWin, 1,halfX,"Monster Health: %f", monsterInCombat->getHP());
        wattroff(combatWin, COLOR_PAIR(7));

        // Display the monster health as a health bar
        wattron(combatWin, COLOR_PAIR(0));
        mvwprintw(combatWin, 2,halfX,"|");
        for(int i = 0; i < 50; i++)
        {
            if(i < monsterInCombat->getHP()/monsterInCombat->getMaxHP()*50)
            {
                mvwprintw(combatWin, 2, halfX+i+1,"%c", char(178));
            }
            else
            {
                mvwprintw(combatWin, 2, halfX+i+1,"%c", '-');
            }

        }
        mvwprintw(combatWin, 2, halfX+51,"|");
        wattroff(combatWin, COLOR_PAIR(0));

        wattron(combatWin, COLOR_PAIR(7));
        mvwprintw(combatWin, 3, halfX, "Monster strength: %i", int(monsterInCombat->getStrength())); // Faster than changing all the variables to float
        wattroff(combatWin, COLOR_PAIR(7));
    }
    else
    {
        // Display player stats

        wattron(combatWin, COLOR_PAIR(6));
        mvwprintw(combatWin, 1,1,"Player Health: %f", player->getHP());
        wattroff(combatWin, COLOR_PAIR(6));
        wattron(combatWin, COLOR_PAIR(0));
        mvwprintw(combatWin, 2,1,"|");
        for(int i = 0; i < 50; i++) // Display the player health as a health bar
        {
            if(i < player->getHP()/player->getMaxHP()*50)
            {
                mvwprintw(combatWin, 2, i+2,"%c", char(178));
            }
            else
            {
                mvwprintw(combatWin, 2, i+2,"%c", '-');
            }

        }
        mvwprintw(combatWin, 2, 52,"|");
        wattroff(combatWin, COLOR_PAIR(0));
        wattron(combatWin, COLOR_PAIR(6));
        mvwprintw(combatWin, 3, 1, "Player strength: %i", int(player->getStrength())); // Faster than changing all the variables to float
        if(player->getEquippedItem() != nullptr)
        {
            mvwprintw(combatWin, 4, 1, "Item equipped: %s", player->getEquippedItem()->getName().c_str());
        }
        else
        {
            mvwprintw(combatWin, 4, 1, "Item equipped: None, Equip one in the inventory");
        }
        wattroff(combatWin, COLOR_PAIR(6));
    }

    wrefresh(combatWin);
    return;
}

// Displays the log of everything that happens (may or may not get to this)
void Game::displayConsole()
{

    return;
}

// Displays the monsters in the maze
void Game::displayMonsters()
{
    for(int i = 0; i < numMonsters; i++)
    {
        if(monsters[i] != nullptr)
        {
            monsters[i]->display();
        }
    }
    return;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------||

// Handles all the player input, including menu navigation
void Game::handleInput(int _input)
{

    switch(_input) // Highlight the selected window
    {
        /**
        Legend:
        selectedWin : 0 = mazeWin
        selectedWin : 1 = inventoryWin
        selectedWin : 2 = combatWin
        */
        case KEY_UP:
            if(selectedWin == 2)
            {
                selectedWin = 1;
                resetWins();
                displayInventory();
                highlightInventory();
            }
            break;
        case KEY_LEFT:
            if(selectedWin != 0)
            {
                selectedWin = 0;
                resetWins();
                displayMaze();
                highlightMaze();
            }
            break;
        case KEY_DOWN:
            if(selectedWin != 2)
            {
                selectedWin = 2;
                resetWins();
                displayCombat();
                highlightCombat();
            }
            break;
        case KEY_RIGHT:
            if(selectedWin == 0)
            {
                selectedWin = 1;
                resetWins();
                displayInventory();
                highlightInventory();
            }
            break;
        default:
            break;
    }

    // do something using selectedWin, even if it hasn't changed yet

    //if(_input == 27) // escape was pressed, exit

    if(selectedWin == 2 && _input == 10 && player->getInventory()->count() > 0) // if enter is pressed while inventory is selected, and there are items in your inventory
    {
        // BE ABLE TO NAVIGATE BETWEEN INVENTORY ITEMS AND SELECT THEM
    }
    // If the player is moving, do that
    if((char(_input) == 'w' || char(_input) == 'a' || char(_input) == 's' || char(_input) == 'd'))
    {
        if(!isInCombat)
        {
            player->movePlayer(char(_input));
            moveMonsters();
            selectedWin = 0;
            resetWins();
            displayMaze();
        }
        else
        {
            printToConsole("Cannot move, currently in combat");
        }
        return;

    }
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------||


void Game::moveMonsters()
{
    for(int i = 0; i < numMonsters; i++)
    {
        if(monsters[i] != nullptr)
        {
            int mX = monsters[i]->getPosX();
            int mY = monsters[i]->getPosY();
            int x = player->getPosX();
            int y = player->getPosY();
            char moves[4] = {' ',' ',' ',' '};
            int numMovesToTry = 0;

            // Check if the monster can move in each direction

            if(!((mY == y && mX == x) || (mY+1 == y && mX == x) || (mY == y && mX+1 == x) || (mY-1 == y && mX == x) || (mY == y && mX-1 == x))) // If the player is one space away, don't move
            {
                if((!maze->hardMaze1[mY-1][mX]->getIsOccupied()) && maze->hardMaze1[mY-1][mX]->getIsTraversable())
                {
                    moves[numMovesToTry] = 'u';
                    numMovesToTry++;
                }
                if((!maze->hardMaze1[mY][mX+1]->getIsOccupied()) && maze->hardMaze1[mY][mX+1]->getIsTraversable())
                {
                    moves[numMovesToTry] = 'r';
                    numMovesToTry++;
                }
                if((!maze->hardMaze1[mY+1][mX]->getIsOccupied()) && maze->hardMaze1[mY+1][mX]->getIsTraversable())
                {
                    moves[numMovesToTry] = 'd';
                    numMovesToTry++;
                }
                if((!maze->hardMaze1[mY][mX-1]->getIsOccupied()) && maze->hardMaze1[mY][mX-1]->getIsTraversable())
                {
                    moves[numMovesToTry] = 'l';
                    numMovesToTry++;
                }
                if(numMovesToTry == 1)
                {
                    monsters[i]->moveMonster(moves[0]);
                }
                else if (numMovesToTry > 1)
                {
                    int monsterMoveDecision = randomNumberInt(numMovesToTry);
                    monsters[i]->moveMonster(moves[monsterMoveDecision]);
                }
            }
        }
    }
    return;
}

void Game::resetWins()
{
    mvwchgat(mazeWin, 0, 2, 11, A_NORMAL, 0, NULL);
    mvwchgat(inventoryWin, 0, 2, 16, A_NORMAL, 0, NULL);
    mvwchgat(combatWin, 0, 2, 13, A_NORMAL, 0, NULL);
    wrefresh(inventoryWin);
    wrefresh(mazeWin);
    wrefresh(combatWin);
    return;
}

void Game::printToConsole(string _input)
{
    wmove(consoleWin, 1,1);
    winsdelln(consoleWin, 1);
    mvwprintw(consoleWin, 1, 1, "%s", _input.c_str());
    box(consoleWin, 0, 0);
    mvwprintw(consoleWin, 0,2, "CONSOLE WINDOW");
    wrefresh(consoleWin);
    return;
}

// Checks to see if the game has been won yet
bool Game::didWin() // resets the highlights for all 3 windows
{
    if(player->getPosX() == maze->getEndPosX() && player->getPosY() == maze->getEndPosY() && player->getHasKey())
    {
        return true;
    }
    return false; // TO CHANGE SOON
}


// Basically IS the combat system
void Game::handleCombat(int _input)
{
    displayCombat();
    char input = char(_input);
    switch(input)
    {
    case '1':
        if(player->getIsAlive())
        {
            playerAttack();
        }
        if(monsterInCombat->getIsAlive())
        {
            monsterAttack();
        }
        break;
    }
    if(!monsterInCombat->getIsAlive() || !player->getIsAlive())
    {
        isInCombat = false;
        maze->hardMaze1[monsterInCombat->getPosY()][monsterInCombat->getPosX()]->setIsOccupied(false);
        //delete monsterInCombat;
        for(int i = 0; i < numMonsters; i++)
        {
            if(monsters[i] == monsterInCombat)
            {
                monsters[i] == nullptr;
            }
        }
        printToConsole("Monster killed!");
        monsterInCombat = nullptr;
        player->setHP(player->getMaxHP());
        wclear(combatWin);
        box(combatWin,0,0);
        highlightCombat();
        displayCombat();
    }
    return;
}

void Game::playerAttack()
{
    monsterInCombat->setHP(monsterInCombat->getHP()-player->getStrength());
    if(monsterInCombat->getHP()<0)
    {
        monsterInCombat->setIsAlive(false);
    }
    return;
}
void Game::monsterAttack()
{
    player->setHP(player->getHP()-monsterInCombat->getStrength());
    if(player->getHP()<0)
    {
        player->setIsAlive(false);
    }
    return;
}
void Game::highlightMaze()
{
    mvwchgat(mazeWin, 0, 2, 11, A_STANDOUT, 0, NULL); // Highlights the maze title
    wrefresh(mazeWin);
    return;
}
void Game::highlightInventory()
{
    mvwchgat(inventoryWin, 0, 2, 16, A_STANDOUT, 0, NULL); // Highlights the inventory title
    wrefresh(inventoryWin);
    return;
}
void Game::highlightCombat()
{
    mvwchgat(combatWin, 0, 2, 13, A_STANDOUT, 0, NULL); // Highlights the inventory title
    wrefresh(combatWin);
    return;
}

Item* Game::generateItem()
{
    // NOTE: There will be 1 less case than the amount of items, because monsters should not *randomly* drop the key. The last one is always the one to drop the key.
    Item * temp = nullptr;
    switch(Utility::randomNumberInt(numItemTypes-1))
    {
    case 0:
        temp = new Sword();
        break;
    case 1:
        temp = new Club();
        break;
    case 2:
        temp = new GarlicClove();
        break;
    case 3:
        temp = new MetalClub();
        break;
    case 4:
        temp = new Scythe();
        break;
    case 5:
        temp = new HealthPotion();
        break;
    case 6:
        temp = new AcidPotion();
        break;
    case 7:
        temp = new StrangeMeat();
        break;
    case 8:
        temp = new MagicStaff();
        break;
    default:
        break;
    }

    return temp;
}
