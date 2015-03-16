#include <stdio.h>
typedef int position;

template<typename elementtype,int maxlength>
class Liner
{
public:
    Liner(int a=0);
    void Insert(elementtype x,position p);//在位置p插入元素x
    position Locate(elementtype x);//返回表中第一个元素x的位置
    elementtype Retrive(position p);//返回位置p的元素
    void Delete(position p);//删除位置p的元素
    position Previous(position p);//位置的上一个位置
    position Next(position p);//位置p的下一个位置
    void Makenull();//清空
    position First();//首位置
    position End();//末位置
private:
    elementtype elements[maxlength];
    int last;
};

template<typename elementtype,int maxlength>
Liner<elementtype,maxlength>::Liner(int a)
{
    last = a;
}

template<typename elementtype,int maxlength>
void Liner<elementtype,maxlength>::Insert(elementtype x,position p)
{
    position q;
    if (last>=maxlength - 1)
    {
        printf("the list is full.\n");
    }
    else if ( p>last+1 || p<1 )
    {
        printf("position not found.\n");
    }
    else
    {
        for (q=last; q>=p; q--)
            elements[q+1] = elements[q];
        last = last + 1;
        elements[p] = x;
    }
}

template<typename elementtype,int maxlength>
position Liner<elementtype,maxlength>::Locate(elementtype x)
{
    position q;
    for (q=1; q<=last; q++)
        if (elements[q]==x)
            return q;
    return last+1;
}

template<typename elementtype,int maxlength>
elementtype Liner<elementtype,maxlength>::Retrive(position p)
{
    if (p>last)
        printf("not found.\n");
    else
        return elements[p];
    return 0;
}

template<typename elementtype,int maxlength>
void Liner<elementtype,maxlength>::Delete(position p)
{
    position q;
    if (p>last || p<1)
        printf("position not found.\n");
    else
    {
        last = last - 1;
        for (q=p; q<=last; q++)
            elements[q] = elements[q+1];
    }
}

template<typename elementtype,int maxlength>
position Liner<elementtype,maxlength>::Previous(position p)
{
    if ( p<=1 || p>last)
        printf("not exist.\n");
    else
        return p-1;
    return 0;
}

template<typename elementtype,int maxlength>
position Liner<elementtype,maxlength>::Next(position p)
{
    if (p>=last || p<1)
        printf("not exist\n");
    else
        return p+1;
    return 0;
}

template<typename elementtype,int maxlength>
void Liner<elementtype,maxlength>::Makenull()
{
    last = 1;
}

template<typename elementtype,int maxlength>
position Liner<elementtype,maxlength>::First()
{
    return 1;
}

template<typename elementtype,int maxlength>
position Liner<elementtype,maxlength>::End()
{
    return last;
}
