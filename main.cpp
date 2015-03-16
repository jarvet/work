#include "stack.h"
#include "LinkList.h"
#include <iostream>
#define maxlength 100
using namespace std;

typedef int elementtype;


int main()
{
    Stack<elementtype,maxlength> s1;
    if (s1.Empty())
        cout<<"empty"<<endl;
    for (int i=0; i<10; i++)
        s1.Push(i);
    while (!s1.Empty())
    {
        cout<<s1.Top()<<endl;
        s1.Pop();
    }

    return 0;
}
