#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "curses.h"

using namespace std;

// Everything needs to know what window it's in, and it's handy for everything to be able to generate a random number.
// Nothing else came up that would be handy to have in a utility class
class Utility
{
    public:
        Utility();
        virtual ~Utility();

        int randomNumberInt(int _upperRange);

    protected:
        WINDOW * curWin;


    private:
};

#endif // UTILITY_H
