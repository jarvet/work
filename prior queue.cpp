#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int Insert(struct node* a, int num);
int Search(struct node* a, int num);
int Delete(struct node* a, int num);

struct node
{
    int value;
    int prior;
}a[20];

int main()
{
    int num = 0;
    int data;
    FILE *fp=fopen("in.txt","r");
    if(!fp)
    {
        printf("can't open file\n");
        return -1;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d",&data);
        a[num+1].prior = data;
        fscanf(fp,"%d",&data);
        a[num+1].value = data;
        num++;
    }
    fclose(fp);

    int i, j;
    for(i = 0, j = 1; i <num; i++)
    {
        if(i == pow(2,j)-1 && i!=0)
        {
            cout<<endl;
            j++;
        }
        cout<<a[i+1].prior<<"("<<a[i+1].value<<")"<<" ";
    }
    cout<<endl;

    cout << "---------------------------"<<endl;
    num = Insert(a, num);
    cout << "�µ����ȶ��У�"<<endl;
    for(i = 0, j = 1; i <num; i++)
    {
        if(i == pow(2,j)-1 && i!=0)
        {
            cout<<endl;
            j++;
        }
        cout<<a[i+1].prior<<"("<<a[i+1].value<<")"<<" ";
    }
    cout<<endl;

    cout << "---------------------------"<<endl;
    int loc = Search(a, num);

    cout << "---------------------------"<<endl;
    num = Delete(a, num);
    cout << "ɾ����Ԫ�غ�����ȶ��У�"<<endl;
    for(i = 0, j = 1; i <num; i++)
    {
        if(i == pow(2,j)-1 && i!=0)
        {
            cout<<endl;
            j++;
        }
        cout<<a[i+1].prior<<"("<<a[i+1].value<<")"<<" ";
    }
    cout<<endl;

    return 0;
}

int Insert(struct node* a, int num)
{
    num++;
    cout << "������Ҫ����Ԫ�ص����ȼ�" ;
    cin >> a[num].prior;
    cout << "������Ҫ����Ԫ�ص���ֵ" ;
    cin >> a[num].value;

    cout << "��Ԫ����ӵ��ӵ����һ��λ�ã�" <<endl;
    int i, j;
    for(i = 0, j = 1; i <num; i++)
    {
        if(i == pow(2,j)-1 && i!=0)
        {
            cout<<endl;
            j++;
        }
        cout<<a[i+1].prior<<"("<<a[i+1].value<<")"<<" ";
    }
    cout<<endl;
    int rec = num;
    while(rec > 1)
    {
        if (a[rec].prior < a[rec/2].prior)
        {
            /*int temp = a[rec].prior;
            a[rec].prior = a[rec/2].prior;
            a[rec/2].prior = temp;
            rec = rec/2;*/
            struct node temp = a[rec];
            a[rec] = a[rec/2];
            a[rec/2] = temp;
            rec = rec/2;
        }
        else return num;
    }
    return num;
}

int Search(struct node* a, int num)
{
    cout<<"������Ҫ���ҵ�Ԫ����ֵ��"<<endl;
    int sea;
    cin >> sea;
    int i;
    int flag = 0;
    for(i = 1; i <= num; i++)
    {
        if(a[i].value == sea)
        {
            cout<<"Found����Ԫ�����ȼ�Ϊ��"<<a[i].prior<<endl;
            return i;
        }
    }
    cout <<"Not Found!"<<endl;
    return -1;
}

int Delete(struct node* a, int num)
{
    a[1] = a[num];
    num--;
    int i = 1;
    while(2*i<=num)
    {
        if(a[i].prior > a[2*i].prior)
        {
            struct node temp = a[i];
            a[i] = a[2*i];
            a[2*i] = temp;
            i = 2*i;
        }
        else if(a[i].prior > a[2*i+1].prior)
        {
            struct node temp = a[i];
            a[i] = a[2*i+1];
            a[2*i+1] = temp;
            i = 2*i+1;
        }
        else break;
    }
    return num;
}
/*cout << "������Ҫɾ����Ԫ����ֵ" <<endl;
    int del;
    cin >> del;
    del = Search(a, num);
    if (del == -1)
    {
        cout << "�޴�Ԫ��!" <<endl;
        return num;
    }
    else
    {
        a[del].value = 100;
        a[del].prior = 100;
        int i = del;
        while(2*i<=num)
        {
            if(a[del].prior > a[2*del+1])
            {
                int struct temp = a[del];
                a[del] = a[2*del+1];
                a[2*del+1] = temp;
                i = 2*i+1;
            }
            else if(a[del].prior > a[2*del])
            {
                int struct temp = a[del];
                a[del] = a[2*del];
                a[2*del] = temp;
                i = 2*i;
            }
            else
        }
    }*/
