#include "Node.h"
#include <iostream>

using namespace std;

// Constructors and destructors
Node::Node()
{
  next = nullptr;
  previous = nullptr;
  content = nullptr;
}
Node::Node(Item * _content)
{
  next = nullptr;
  previous = nullptr;
  content = _content;
}
Node::Node(Node* _next, Node* _previous, Item * _content)
{
  next = _next;
  previous = _previous;
  content = _content;
}
Node::~Node()
{
}

// Getters and setters
Node* Node::getNext()
{
  return next;
}
Node* Node::getPrevious()
{
  return previous;
}
Item* Node::getContent()
{
  return content;
}
void Node::setNext(Node* _next)
{
  next = _next;
  return;
}
void Node::setPrevious(Node* _previous)
{
  previous = _previous;
  return;
}
void Node::setContent(Item* _content)
{
  content = _content;
  return;
}

// Public methods ||-------------------------------------------------------------------------------------------------------------||

// Overloaded comparison operator
bool Node::operator == (Node* _node2)
{
  return ((content == _node2->content) && (next == _node2->next) && (previous == _node2->previous));
}
