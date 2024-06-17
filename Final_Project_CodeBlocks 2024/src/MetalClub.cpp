#include "MetalClub.h"

MetalClub::MetalClub()
{
    name = "Metal Club";
    type = 'W';
    curWin = nullptr;
    //ctor
}
MetalClub::MetalClub(WINDOW * _curWin) : MetalClub()
{
    curWin = _curWin;
}

MetalClub::~MetalClub()
{
    //dtor
}

void MetalClub::use()
{
    return;
}
