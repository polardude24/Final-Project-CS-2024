#include <curses.h>
#include <string>

using namespace std;


// winget install ezwinports.make

int main()
{
  initscr();
  cbreak();
  noecho();

    char in1 = getch();
    char in2 = getch();
    string text = "Hello, ncurses!";

    mvprintw(LINES/2,(COLS-text.size())/2,text.c_str());

    move(in1,in2);
    printf("Shrek");
    getch();
    endwin();
    return 0;
}
