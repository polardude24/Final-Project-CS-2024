#include "Key.h"

Key::Key()
{
    name = "Key";
    type = 'K';
    //ctor
}

Key::Key(WINDOW* _curWin) : Key()
{
    curWin = _curWin;
}

Key::~Key()
{
    //dtor
}

void Key::use()
{
    return;
}
