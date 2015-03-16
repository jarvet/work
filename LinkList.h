#include <stdio.h>

template<typename elementtype>
struct celltype
{
elementtype element;
celltype *next;
};

template<typename elementtype>
class Link
{
public:
    /*typedef celltype<elementtype> *LIST;
    typedef celltype<elementtype> *position;*////prototype for 'position Link::locate'does not match any in class link
    Link();
    ~Link();
    void Insert(elementtype x,celltype<elementtype> * p);//在位置p插入元素x
    celltype<elementtype> * Locate(elementtype x);//返回表中第一个元素x的位置
    elementtype Retrive(celltype<elementtype> * p);//返回位置p的元素
    void Delete(celltype<elementtype> * p);//删除位置p的元素
    celltype<elementtype> * Previous(celltype<elementtype> * p);//位置的上一个位置
    celltype<elementtype> * Next(celltype<elementtype> * p);//位置p的下一个位置
    void Makenull();//清空
    celltype<elementtype> * First();//首位置
    celltype<elementtype> * End();//末位置
private:
    celltype<elementtype> * header;
};

template<typename elementtype>
Link<elementtype>::Link()
{
    header = new celltype<elementtype>;
    header.next = NULL;
}

template<typename elementtype>
Link<elementtype>::~Link()
{
    ;///
}

template<typename elementtype>
void Link<elementtype>::Insert(elementtype x,celltype<elementtype> * p)
{
        celltype<elementtype> * q,s;
        s = header;
        while (s->next != p)
            s = s->next;
        q = new celltype<elementtype>;
        q->element = x;
        q->next = s->next;
        s->next = q;
}

template<typename elementtype>
celltype<elementtype> * Link<elementtype>::Locate(elementtype x)
{
    celltype<elementtype> * p;
}

template<typename elementtype>
elementtype Link<elementtype>::Retrive(celltype<elementtype> * p)
{
    if (p>last)
        printf("not found.\n");
    else
        return elements[p];
    return 0;
}

template<typename elementtype>
void Link<elementtype>::Delete(celltype<elementtype> * p)
{
    celltype<elementtype> * q;
    if (p>last || p<1)
        printf("not found.\n");
    else
    {
        last = last - 1;
        for (q=p; q<=last; q++)
            elements[q] = elements[q+1];
    }
}

template<typename elementtype>
celltype<elementtype> * Link<elementtype>::Previous(celltype<elementtype> * p)
{
    if ( p<=1 || p>last)
        printf("not exist.\n");
    else
        return p-1;
    return 0;
}

template<typename elementtype>
celltype<elementtype> * Link<elementtype>::Next(celltype<elementtype> * p)
{
    if (p>=last || p<1)
        printf("not exist\n");
    else
        return p+1;
    return 0;
}

template<typename elementtype>
void Link<elementtype>::Makenull()
{
    last = 1;
}

template<typename elementtype>
celltype<elementtype> * Link<elementtype>::First()
{
    return 1;
}

template<typename elementtype>
celltype<elementtype> * Link<elementtype>::End()
{
    return last;
}
