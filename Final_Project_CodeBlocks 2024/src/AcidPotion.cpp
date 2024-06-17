#include "AcidPotion.h"

AcidPotion::AcidPotion()
{
    name = "Acid Potion";
    type = 'C';
    curWin = nullptr;
    //ctor
}
AcidPotion::AcidPotion(WINDOW * _curWin) : AcidPotion()
{
    curWin = _curWin;
}

AcidPotion::~AcidPotion()
{
    //dtor
}

void AcidPotion::use()
{
    return;
}
