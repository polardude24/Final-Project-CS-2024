#include "Utility.h"

Utility::Utility()
{
    //ctor
}

Utility::~Utility()
{
    //dtor
}

int Utility::randomNumberInt(int _upperRange)
{
    if(_upperRange < 1)
        return 0;
    return rand() % _upperRange;
}

