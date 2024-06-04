#include <curses.h>
#include <string>

using namespace std;


// winget install ezwinports.make

int main(int argc, char** argv)
{
    initscr(); // Start Curses
    cbreak();
    noecho();

    /// get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    /// create a window for our input
    WINDOW * menuWin = newwin(3, xMax-12, yMax-5, 5);
    box(menuWin, 0,0);
    refresh();
    wrefresh(menuWin);

    keypad(menuWin, true);
    getch();
    endwin(); /// End curses

    return 0;
}

/*
This is where all of the functions and their inputs will reside for curses to refer back to

NOTE: curses always has y before x

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




attributes:
attron();
attroff();
A_NORMAL
A_STANDOUT
A_REVERSE
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

*/
