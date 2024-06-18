#include <curses.h>
#include <string>
#include <cstdlib>
#include <ctime>


#include "Game.h"

using namespace std;


// winget install ezwinports.make

int main(int argc, char** argv)
{
    srand(time(NULL));
    initscr(); // Start Curses
    cbreak();
    noecho();
    curs_set(0);
    if(!has_colors()) // Check to see if console supports colours, if not do not proceed with program
    {
        return -1;
    }
    start_color(); // Sets up curses to work with colour
    init_pair(1, COLOR_WHITE, COLOR_BLUE); // White text on blue background (highlighted)
    init_pair(2, COLOR_BLACK, COLOR_GREEN); // Black text on green background (player)
    init_pair(3, COLOR_BLACK, COLOR_YELLOW); // Black text on yellow background (item)
    init_pair(4, COLOR_WHITE, COLOR_CYAN); // White text on cyan background (exit)
    init_pair(5, COLOR_BLACK, COLOR_RED); // Black text on red background (monster)
    init_pair(6, COLOR_GREEN, COLOR_BLACK); // Green text on black background (player stats)
    init_pair(7, COLOR_RED, COLOR_BLACK); // Red text on black background (monster stats)


    // # = 48 + #


    printw("Which maze would you like to use?");
    mvprintw(1,0, "1) Small maze (20x20)");
    mvprintw(2,0, "2) Medium maze (30x30)");
    mvprintw(3,0, "3) Large maze (40x40)");
    refresh();
    char mazeChoice = getch();
    clear();
    printw("Would you like to run the Auto Solver?");
    mvprintw(1,0, "1) Yes");
    mvprintw(2,0, "2) No");
    int autoSolverChoice = getch();
    int mazeChoiceInt = 0;
    bool autoSolverChoiceBool = false;
    switch(mazeChoice)
    {
    case '1':
        mazeChoiceInt = 1;
        break;
    case '2':
        mazeChoiceInt = 2;
        break;
    case '3':
        mazeChoiceInt = 3;
        break;
    default:
        break;
    }
    if(autoSolverChoice == 49)
    {
        autoSolverChoiceBool = true;
    }
    else if(autoSolverChoice == 50)
    {
        autoSolverChoiceBool = false;
    }

    clear();
    Game* game = new Game(autoSolverChoiceBool, mazeChoiceInt);
    game->initializeGame();
    game->runGame();


    //printw("%i",input);

    //printw("Please enter your name:")

    clear();
    //getch();
    endwin();
    return 0;
}

/**
This is where all of the functions and their inputs will reside for curses to refer back to

NOTE: curses always has y before x
NOTE: to display a string, add .c_str() to the end of it to convert it to the proper format

METHODS:
move(y,x); // moves the cursor to (x,y)
newwin(height, width, start_y, start_x); // creates a new window
box(win, left&right, top&bottom); // makes a simple box around a window
wborder(win, left, right, top, bottom, tlc, trc, blc, brc); // makes a more complex border around  a window
wprintw(win, text); // prints to a window at 0,0; will overlap borders
mvwprintw(win, start_y, start_x, text); // prints to a window at x,y
init_pair(valueOfColourPair, foreground, background); // initializes a colour pair assigned an int value with 2 colours
getyx(win, y, x); // changes y and x to the current position of the cursor in the window specified
getbegyx(win, y, x); // changes y and x to the beginning corner of the window specified
getmaxyx(win, y, x); // changes y and x to the height and width of the window specified
wgetchar(win); // returns a character
keypad(win, bool); // sets whether a window can accept arrow keys or keypad keys as input
mvwaddchar(win, y, x, char); // prints a character at (x,y)
werase(win); // sets the window back to blank
chgat(numCharctersToChange, attributeToSet, colourPair, NULL); // changes the attribute of text for a set number of characters to a new attribute and colour pair
refresh(); // refreshes the whole screen, moving its contents from memory to visual
wrefresh(win); // refreshes a window, moving its contents from memory to visual


INPUT MODES:
halfdelay(int); // waits for 'int' tenths of a second for input, and if none supplied will return ERR or -1
nodelay(win, bool); // if bool==true act like halfdelay except with wait time being 0
timeout(int); // if 'int' < 1, acts like getch(), if 'int' = 0, acts like nodelay, if 'int' > 0, acts like halfdelay except with 'int' milliseconds (so more accurate)

DATA TYPES:
chtype = 'char' | attribute | attribute ... // char, but with memory for attributes


attributes:
attron();
attroff();
A_NORMAL // Makes it normal
A_STANDOUT // Highlights
A_REVERSE // Reverses colour
A_BLINK
A_ALTCHARSET

COLOR_PAIR(valueOfColourPair);
COLOR_BLACK
COLOR_RED
COLOR_GREEN
COLOR_YELLOW
COLOR_BLUE
COLOR_MAGENTA
COLOR_CYAN
COLOR_WHITE

DETECTING CTRL + CHAR:
#define ctrl(x) (x && 0x1F) // defining the ctrl(char) function
if(char == ctrl(char)) will return true if 'char' is ctrl+char




REFERENCE FOR MENUBAR FUNCTIONALITY. CREDIT GOES TO CASUAL CODER YOUTUBE CHANNEL

string menu1[] = {"New", "Open", "Save", "Exit"};
string menu2[] = {"Copy", "Cut", "Paste"};
string menu3[] = {"Sidebar", "Terminal"};

Menu menus[3] = {
    Menu("File", 'f', menu1, 4),
    Menu("Edit", 'e', menu2, 3),
    Menu("Options", 'o', menu3, 2),
};

MenuBar menuBar(win, menus, 3);
menuBar.display();

char ch;
while(ch = wgetch(win))
{
    menuBar.handleTrigger(ch);
    menuBar.display();
}

*/
