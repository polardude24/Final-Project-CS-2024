#include "ContainerStack.h"

ContainerStack::ContainerStack()
{
    next = nullptr;
    content = ' ';
    //ctor
}
ContainerStack::ContainerStack(char _content)
{
    next = nullptr;
    content = _content;
    //ctor
}
ContainerStack::ContainerStack(ContainerStack* _next, char _content)
{
    next = _next;
    content = _content;
    //ctor
}

ContainerStack::~ContainerStack()
{
    //dtor
}
