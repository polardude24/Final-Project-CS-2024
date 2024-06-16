#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "curses.h"

using namespace std;

class Utility
{
    public:
        Utility();
        virtual ~Utility();

        int randomNumberInt(int _upperRange);

    protected:
        WINDOW * curWin;
        int difficulty;


    private:
};

#endif // UTILITY_H
