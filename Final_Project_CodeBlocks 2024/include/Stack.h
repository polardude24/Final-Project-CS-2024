#ifndef STACK_H
#define STACK_H

#include "ContainerStack.h"

// It's a stack... no need for further explanation

class Stack
{
    public:
        Stack();
        Stack(ContainerStack*);
        virtual ~Stack();

        ContainerStack * getTop(){return top;}
        void setTop(ContainerStack* val){top = val;}

        void push(ContainerStack* _newTop);
        void push(char _contentOfNewTop);
        char pop();
        char peek();
        int count();

    protected:

    private:
        ContainerStack * top;
};

#endif // STACK_H
