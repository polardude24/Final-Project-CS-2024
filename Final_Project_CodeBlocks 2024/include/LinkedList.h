#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Utility.h"
#include "Item.h"

class Node;

class LinkedList : public Utility
{
  public:
    LinkedList();
    virtual ~LinkedList();

    // Getters and setters
    Node* getFront();
    Node* getBack();

    // Public methods
    void insertBeginning(Item*);
    void insertEnd(Item*);
    void insertAfter(Node*, Item*);
    void insertAfterValue(Item*, Item*);
    void insertNth(int, Item*);
    bool search(Item*);
    bool search(Node*);
    Node* index(int);
    Node* findItem(Item*);
    int findReturnIndex(Item*);
    void remove(Node*);
    void removeItem(Item*);
    void removeNth(int);
    void removeFront();
    void removeEnd();
    int count();

  private:
    Node* front;
    Node* back;

    // Private methods
    void insertAfter(Node*, Node*);
    Node* searchReturn(Item*);
};

#endif
