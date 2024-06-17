#ifndef CONTAINERSTACK_H
#define CONTAINERSTACK_H


class ContainerStack
{
    public:
        ContainerStack();
        ContainerStack(char _content);
        ContainerStack(ContainerStack* _next, char _content);
        virtual ~ContainerStack();

        ContainerStack * getNext(){return next;};
        void setNext(ContainerStack* val){next = val;}
        char getContent(){return content;}
        void setContent(char val){content = val;}



    protected:

    private:
        ContainerStack* next;
        char content;
};

#endif // CONTAINERSTACK_H
