#ifndef NODE_H
#define NODE_H

#include "Utility.h"
#include "Item.h"

class Node : public Utility
{
  public:
    // Constructors and destructors
    Node();
    Node(Item*);
    Node(Node*, Node*, Item*);
    virtual ~Node();

    // Getters and setters
    Node* getNext();
    Node* getPrevious();
    Item* getContent();
    WINDOW* getWin(){return curWin;}
    void setNext(Node*);
    void setPrevious(Node*);
    void setContent(Item*);

    bool operator == (Node*);
  private:
    WINDOW * curWin;
    Node* next;
    Node* previous;
    Item * content;
};

#endif
