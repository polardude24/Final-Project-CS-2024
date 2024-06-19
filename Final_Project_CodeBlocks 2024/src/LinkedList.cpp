#include "Node.h"
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructors and destructors
LinkedList::LinkedList()
{
  front = nullptr;
  back = nullptr;
}
LinkedList::~LinkedList()
{
}

// Getters and setters
Node* LinkedList::getFront()
{
  return front;
}
Node* LinkedList::getBack()
{
  return back;
}

// Public methods ||-------------------------------------------------------------------------------------------------------------||

// Wrapper methods ||------------------------------------------------------------------------------------------------------------||
void LinkedList::insertBeginning(Item* _item) // Insert at the beginning
{
  insertAfter(nullptr, new Node(_item));
  return;
}
void LinkedList::insertEnd(Item* _item) // Insert at the end
{
    if(_item == nullptr)
        return;
  insertAfter(index(count()-1), new Node(_item));
  return;
}
void LinkedList::insertAfter(Node* _nodeLookingFor, Item* _item) // Insert after a given node
{
  insertAfter(_nodeLookingFor, new Node(_item));
  return;
}
void LinkedList::insertNth(int _index, Item* _item) // Insert at the n'th positino
{
  insertAfter(index(_index), _item);
  return;
}
void LinkedList::insertAfterValue(Item* _itemLookingFor, Item* _itemToInsert) // Insert after the first occurance of a given item
{
  if(search(_itemLookingFor)) // If the item looking for is in the array, insert after that
  {
    Node* temp = new Node;
    temp = searchReturn(_itemLookingFor);
    insertAfter(temp, new Node(_itemToInsert));
  }
  return;
}
void LinkedList::removeItem(Item* _itemToRemove) // Remove the first occurance of a given item
{
  remove(searchReturn(_itemToRemove));
  return;
}
void LinkedList::removeNth(int _n) // Remove the n'th node from the list
{
  remove(index(_n));
  return;
}
void LinkedList::removeFront() // Remove the front of the list
{
  remove(front);
  return;
}
void LinkedList::removeEnd() // Renove the back of the list
{
  remove(back);
  return;
}

// Not-Wrapper methods ||--------------------------------------------------------------------------------------------------------||
bool LinkedList::search(Item* _itemSearchingFor) // Searches for a given item in the list
{
  if (front == nullptr) // If nothing in the list, throw error
  {
    return false;
  }
  Node* temp = front;
  while(temp != nullptr) // Iterates front to back, and if the content is the same return true
  {
    if(temp->getContent() == _itemSearchingFor)
    {
      return true;
    }
    temp = temp->getNext();
  }
  return false;
}

bool LinkedList::search(Node* _nodeSearchingFor) // Searches for a given node in the list
{
  if(front == nullptr && _nodeSearchingFor != nullptr) // If nothing in list and looking for something, throw error
  {
    return false;
  }
  Node* temp = front;
  while(temp != nullptr) // Iterates front to back, and if the content is the same return true
  {
    if(temp == _nodeSearchingFor)
    {
      return true;
    }
    temp = temp->getNext();
  }
  return false;
}

Node* LinkedList::index(int _n) // Returns the n'th item in the list
{
  Node* temp = front;
  for(int i = 0; i <= _n; i++)
  {
    if(temp == nullptr) // If there is no i'th item in the list, return nullptr
    {
      return nullptr;
    }
    if(i == _n)
    {
      return temp;
    }
    temp = temp->getNext();
  }
  return nullptr;
}

Node* LinkedList::findItem(Item* _itemSearchingFor) // Finds the first occurance of an item, and returns that node
{
  if (front == nullptr) // If nothing in the list, throw error
  {
    //throw invalid_argument("NOTHING IN LIST");
    return nullptr;
  }
  Node* temp = front;
  while(temp != nullptr) // Iterates front to back, and if the content is the same return the node
  {
    if(temp->getContent() == _itemSearchingFor)
    {
      return temp;
    }
    temp = temp->getNext();
  }
  return nullptr;
}

int LinkedList::findReturnIndex(Item* _itemSearchingFor)
{
  if (front == nullptr) // If nothing in the list, throw error
  {
    return -1;
  }
  Node* temp = front;
  int i = 0;
  while(temp != nullptr) // Iterates front to back, and if the content is the same return the node
  {
    if(temp->getContent() == _itemSearchingFor)
    {
      return i;
    }
    i++;
    temp = temp->getNext();
  }
  return -1;
}

void LinkedList::remove(Node* _nodeToRemove)
{
  if (front == nullptr || _nodeToRemove == nullptr || !search(_nodeToRemove)) // If nothing in the list or node to search for doesn't exist, return
  {
    return;
  }
  if(_nodeToRemove != front && _nodeToRemove != back) // If it's in an inside location
  {
    _nodeToRemove->getPrevious()->setNext(_nodeToRemove->getNext());
    _nodeToRemove->getNext()->setPrevious(_nodeToRemove->getPrevious());
    _nodeToRemove->setNext(nullptr);
    _nodeToRemove->setPrevious(nullptr);
    delete(_nodeToRemove);
    return;
  }
  if(front == back) // If there is only one node
  {
    front = nullptr;
    back = nullptr;
    _nodeToRemove->setNext(nullptr);
    _nodeToRemove->setPrevious(nullptr);
    delete(_nodeToRemove);
    return;
  }
  else if(_nodeToRemove == front) // If it's at the very front
  {
    front = _nodeToRemove->getNext();
    front->setPrevious(nullptr);
    _nodeToRemove->setNext(nullptr);
    _nodeToRemove->setPrevious(nullptr);
    delete(_nodeToRemove);
    return;
  }
  else if(_nodeToRemove == back) // If it's at the very back
  {
    back = _nodeToRemove->getPrevious();
    back->setNext(nullptr);
    _nodeToRemove->setNext(nullptr);
    _nodeToRemove->setPrevious(nullptr);
    delete(_nodeToRemove);
    return;
  }
  return;
}

int LinkedList::count()
{
  // Iterator to count every node in the list
  Node* iterator = front;
  int i = 0;
  while(iterator != nullptr)
  {
    i++;
    iterator = iterator->getNext();
  }
  return i;
}

// Private methods ||------------------------------------------------------------------------------------------------------------||

void LinkedList::insertAfter(Node* _nodeSearchingFor, Node* _passedNode) // Inserts a node after a node in the list
{
  if (_nodeSearchingFor == nullptr) // If node to search for is nullptr, insert at beginning
  {
    if(front == nullptr) // If list is empty
    {
      front = _passedNode;
      back = _passedNode;
      front->setNext(back);
      back->setNext(nullptr);
      front->setPrevious(nullptr);
      back->setPrevious(front);
      return;
    }
    if(front == back) // If the list has exactly 1 node
    {
      front = _passedNode;
      front->setNext(back);
      front->setPrevious(nullptr);
      back->setPrevious(front);
      return;
    }
    else
    {
      _passedNode->setNext(front);
      front->setPrevious(_passedNode);
      front = _passedNode;
      front->setPrevious(nullptr);
      return;
    }
  }
  if(!search(_nodeSearchingFor) && _nodeSearchingFor != nullptr) // Make sure that the node searching for is in the list
  {
    //throw invalid_argument("NOT IN LIST");
    return;
  }
  if(_nodeSearchingFor == back)
  {
    back->setNext(_passedNode);
    _passedNode->setNext(nullptr);
    _passedNode->setPrevious(back);
    back = _passedNode;
    return;
  }
  else
  {
    _passedNode->setNext(_nodeSearchingFor->getNext());
    _passedNode->getNext()->setPrevious(_passedNode);
    _nodeSearchingFor->setNext(_passedNode);
    _passedNode->setPrevious(_nodeSearchingFor);
    return;
  }
}

Node* LinkedList::searchReturn(Item* _itemSearchingFor) // Return the first node that has the given item
{
  if (front == nullptr) // If nothing in the list, throw error
  {
    throw invalid_argument("NOTHING IN LIST");
  }
  Node* temp = front;
  while(temp != nullptr) // Iterates front to back, and if the content is the same return true
  {
    if(temp->getContent() == _itemSearchingFor)
    {
      return temp;
    }
    temp = temp->getNext();
  }
  return nullptr;
}
