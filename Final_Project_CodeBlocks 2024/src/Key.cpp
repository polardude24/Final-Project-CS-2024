#include "Key.h"

Key::Key()
{
    //ctor
}

Key::Key(WINDOW* _curWin, int _id)
{
    curWin = _curWin;
    id = _id;
    name = "Key";
    type = 'K';
}

Key::~Key()
{
    //dtor
}

void Key::use()
{
    return;
}
