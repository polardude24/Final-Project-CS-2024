#include <curses.h>
#include <string>
#include <cstdlib>
#include <ctime>

#include "menu.h"
#include "MenuBar.h"


using namespace std;


// winget install ezwinports.make

int main(int argc, char** argv)
{
    initscr(); // Start Curses
    cbreak();
    noecho();
    curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
    box(win,0,0);

    Menu menus[3] = {
        Menu("File", 'f'),
        Menu("Edit", 'e'),
        Menu("Options", 'o'),
    };

    MenuBar menuBar(win, menus, 3);
    menuBar.display();

    char ch;
    while(ch = wgetch(win))
    {
        menuBar.handleTrigger(ch);
        menuBar.display();
    }


    wgetch(win);

    endwin(); /// End curses

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
COLOR_BLACK 0
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

*/
