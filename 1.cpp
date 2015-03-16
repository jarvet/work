#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

struct node    //node
{
    int value;      //numerical value
    int floor;
    struct node *next;
	struct node *down;
};

int num_floor = 1;   //the number of layers

struct node* New_floor(struct node *ini);
struct node* Insert(struct node *top);
void Output(struct node *top);
struct node* Delete(struct node *top, int data);
int Search(struct node *top, int data);

int main()
{
	srand(time(NULL));

	struct node *top;  //���ڴ洢����һ���ʼԪ�ص�ַ
	top = (struct node *)malloc(sizeof(struct node));

	struct node *ini;
	ini = (struct node *)malloc(sizeof(struct node));
	ini->value = -1;
	ini->floor = 1;
	ini->next = NULL;
	ini->down = NULL;

	struct node *pt;
	pt = ini;

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
        struct node *p;
        p = (struct node *)malloc(sizeof(struct node));
        pt->next = p;
        p->value = data;
        p->floor = 1;
        p->down = NULL;
        pt = p;
    }
    fclose(fp);
    pt->next = NULL;

    struct node *pp;
    pp = ini;
    cout << "�����ļ���ȡ��ʼ����Ϊ: " << endl;
    while (pp->next != NULL)
    {
        cout << pp->value << " -> ";
        pp = pp->next;
    }
    cout << pp->value <<endl;
    cout <<"---------------------------------"<<endl;

    struct node *pc;
    struct node *pd;
    pd = New_floor(ini);
    pc = ini;

    while (pd)
    {
        top = pd;
        pc = pd;
        while (pd->next != NULL)
        {
            pd = pd->next;
        }
        pd = New_floor(pc);
    }
    cout << "�����������Ϊ�� " << endl;
    Output(top);
    cout <<"---------------------------------"<<endl;

    top = Insert(top);
    cout << "����������Ϊ�� " << endl;
    Output(top);

    cout <<"---------------------------------"<<endl;
    int dat;
    cout << "ɾ��������Ϊ�� " << endl;
    cin >> dat;
    top = Delete(top, dat);

    cout << "ɾ���������Ϊ�� " << endl;
    Output(top);

    cout <<"---------------------------------"<<endl;
    cout << "���ҵ�����Ϊ�� " << endl;
    cin >> dat;
    int flag;
    flag = Search(top, dat);
    return 0;
}

struct node* New_floor(struct node *ini)
{
    if (ini->next->next->value == 1)
    {
        return NULL;
    }

    struct node *new_ini;
    new_ini = (struct node *)malloc(sizeof(struct node));
    new_ini->value = -1;
    new_ini->floor = ++num_floor;
    new_ini->down = ini;

    struct node *pa; //ָ���²�
    int num_a = 1; //�²�Ԫ�ظ���
    pa = ini->next;
    struct node *pb; //ָ���µ�һ��
    int num_b = 0; //�µ�һ��Ԫ�ظ���
    pb = new_ini;
    while (pa->next != NULL)
    {
        if(rand()%2 == 1)
        {
            struct node *new_next;
            new_next = (struct node *)malloc(sizeof(struct node));
            pb->next = new_next;
            new_next->value = pa->value;
            new_next->floor = num_floor;
            new_next->down = pa;
            pb = new_next;
            //cout <<"*"<<pa->value;
            num_b++;
        }
        pa = pa->next;
        num_a++;
    }

    struct node *new_next;
    new_next = (struct node *)malloc(sizeof(struct node));
    pb->next = new_next;
    new_next->next = NULL;
    new_next->floor = num_floor;
    new_next->value = 1;
    num_b++;

    if (new_ini->next->value == 1 || num_a == num_b)
    {
        //cout << "������� -1 -> 1" <<endl;
        num_floor--;
        return NULL;
    }
    return new_ini;
}

struct node* Insert(struct node *top)
{
    int add_floor = rand()%(num_floor+1)+1; //ȷ��Ԫ��Ҫռ�ݵĲ���
    cout << "���������Ԫ��ռ�ݵĲ���Ϊ��"<<add_floor<<endl;
    if (add_floor > num_floor)  //��������Ĳ�����Ҫ����µĲ�
    {
        struct node *new_top;
        new_top = (struct node *)malloc(sizeof(struct node));
        new_top->down = top;
        top = new_top;
        new_top->value = -1;
        new_top->floor = add_floor;

        struct node *ins;
        ins = (struct node *)malloc(sizeof(struct node));
        new_top->next = ins;
        cout << "��������Ҫ�����Ԫ��: ";
        cin >> ins->value;
        ins->floor = add_floor;
        struct node *new_fin;
        new_fin = (struct node *)malloc(sizeof(struct node));
        new_fin->next = NULL;
        new_fin->value = 1;
        new_fin->floor = add_floor;
        ins->next = new_fin;

        struct node *p_ins = ins;
        struct node *p_top = top->down;  //top��������
        while(p_top != NULL)
        {
            struct node *p_next = p_top;  //���κ�����һ��
            while(ins->value > p_next->next->value && p_next->next->value != 1)
            {
                //cout<<"&"<<p_next->value<<"&";
                p_next = p_next->next;

            }
            struct node *new_ins;
            new_ins = (struct node *)malloc(sizeof(struct node));
            new_ins->value = ins->value;
            new_ins->next = p_next->next;
            p_next->next = new_ins;
            p_ins->down = new_ins;
            p_ins = new_ins;

            p_top = p_next->down;
        }
        return new_top;
    }
    else
    {
        struct node *ins;
        ins = (struct node *)malloc(sizeof(struct node));
        cout << "��������Ҫ�����Ԫ��";
        cin >> ins->value;
        ins->floor = add_floor;

        struct node *p_ins = ins;
        struct node *p_top = top;  //top��������
        while(p_top->floor != add_floor)
        {
            p_top = p_top->down;
        }

        while(p_top != NULL)
        {
            struct node *p_next = p_top;  //���κ�����һ��
            while(ins->value > p_next->next->value && p_next->next->value != 1)
            {
                p_next = p_next->next;
            }
            struct node *new_ins;
            new_ins = (struct node *)malloc(sizeof(struct node));
            new_ins->value = ins->value;
            new_ins->next = p_next->next;
            p_next->next = new_ins;
            p_ins->down = new_ins;
            p_ins = new_ins;

            p_top = p_next->down;
        }
        return top;
    }
};

void Output(struct node *top)
{
    struct node *px;
    struct node *py = top;
    while(py != NULL)
    {
        px = py;
        cout << "Floor " << px->floor <<": ";
        while(px->next != NULL)
        {
            cout << px->value << " -> ";
            px = px->next;
        }
        cout << px->value <<endl;
        py = py->down;
    }
}

struct node* Delete(struct node *top, int data)
{
    node *p = top;

    while (p!=NULL)
    {
        while (p->next->value < data && p->next->value != 1)
            p = p->next;
        if (p->next->value == data)
        {
            if (p==top && p->next->next->value == 1)
            {
                top = p->down;
                free(p->next->next);
                free(p->next);
                free(p);
                p = top;
            }
            else
            {
                node *pdel = p->next;
                p->next = pdel->next;
                free(pdel);
            }
        }
        p = p->down;
    }

    return top;
}
int Search(struct node *top, int data)
{
    struct node* px = top;
    struct node* py = top;
    while(py != NULL)
    {
        if(data == px->next->value)
        {
            cout << "Found!" << endl;
            return 1;
        }
        else if(data > px->next->value && px->next->value != 1)
        {
            px = px->next;
        }
        else
        {
            px = px->down;
            py = py->down;
        }
    }
    if(py == NULL)
    {
        cout << "Not Found!" << endl;
        return 0;
    }
}
