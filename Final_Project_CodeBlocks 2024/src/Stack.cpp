#include "Stack.h"

Stack::Stack()
{
    top = nullptr;
    //ctor
}
Stack::Stack(ContainerStack* _top)
{
    top = _top;
    //ctor
}

Stack::~Stack()
{
    //dtor
}

void Stack::push(ContainerStack* _newTop)
{
    if(_newTop == nullptr)
    {
        return;
    }
    _newTop->setNext(top);
    top = _newTop;
    return;
}
void Stack::push(char _contentOfNewTop)
{
    push(new ContainerStack(_contentOfNewTop));
    return;
}
char Stack::pop()
{
    if(top == nullptr)
    {
        return ' ';
    }
    char temp = top->getContent();
    top = top->getNext();
    return temp;
}
char Stack::peek()
{
    if (top == nullptr)
    {
        return ' ';
    }
    return top->getContent();
}
