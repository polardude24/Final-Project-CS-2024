#ifndef MENU_H
#define MENU_H

#include <Utility.h>


class Menu : public Utility
{
    public:
        Menu();
        Menu(string _text, char _trigger, string *_items, int _numItems);
        virtual ~Menu();

        int getStartX(){return startX;}
        void setStartX(int val){startX = val;}
        string getText(){return text;}
        void setText(string val){text = val;}
        char getTrigger(){return trigger;}
        void setTrigger(char val){trigger = val;}
        string* getItems(){return items;}
        void setItems(string* val){items = val;}
        int getNumItems(){return numItems;}
        void setNumItems(int val){numItems = val;}
        int getSelectedItem(){return selectedItem;}
        void setSelectedItem(int val){selectedItem = val;}

        void selectNextItem();
        void selectPrevItem();

    protected:

    private:
        int startX;
        string text;
        char trigger;
        string * items;
        int numItems;
        int selectedItem;
};

#endif // MENU_H
