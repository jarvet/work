#include "LinerList.h"

template<typename elementtype,int maxlength>
class Stack
{
public:
    Stack();
    void MakeStackNull();//将栈清空
    elementtype Top();//返回栈顶元素
    void Pop();//退栈
    void Push(elementtype x);//元素x入栈
    bool Empty();//判断栈是否为空
private:
    Liner<elementtype,maxlength> s;
    int top;
};

template<typename elementtype,int maxlength>
Stack<elementtype,maxlength>::Stack()
{
    top = 0;
}

template<typename elementtype,int maxlength>
void Stack<elementtype,maxlength>::MakeStackNull()
{
    top = 0;
}

template<typename elementtype,int maxlength>
bool Stack<elementtype,maxlength>::Empty()
{
    if (top<1)
        return true;
    else
        return false;
}

template<typename elementtype,int maxlength>
elementtype Stack<elementtype,maxlength>::Top()
{
    if (Empty())
        printf("the stack is empty\n");
    else
        return s.Retrive(top);
    return 0;
}

template<typename elementtype,int maxlength>
void Stack<elementtype,maxlength>::Pop()
{
    if (Empty())
        printf("the stack is empty\n");
    else
        top--;
}

template<typename elementtype,int maxlength>
void Stack<elementtype,maxlength>::Push(elementtype x)
{
    if (top == maxlength - 1)
        printf("the stack is full\n");
    else
    {
        top++;
        s.Insert(x,top);
    }
}
