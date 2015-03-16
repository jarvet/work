#include "LinerList.h"

template<typename elementtype,int maxlength>
class Stack
{
public:
    Stack();
    void MakeStackNull();//��ջ���
    elementtype Top();//����ջ��Ԫ��
    void Pop();//��ջ
    void Push(elementtype x);//Ԫ��x��ջ
    bool Empty();//�ж�ջ�Ƿ�Ϊ��
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
