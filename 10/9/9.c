* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
*
*
* @param node int����
* @return ��
*
*C������������ȫ�ֱ��������static����ֹ�ظ�����
* /

#define Ele int
#define MIN -10000

struct Stack {
    Ele val;
    struct Stack* next;
};

typedef struct Stack Stack;

Stack* S1;
Stack* S2;


Stack* Create_Stack(void)
{
    Stack* p = (Stack*)malloc(sizeof(Stack));
    if (p == NULL)
        printf("�ռ䲻����\n");
    else
    {
        p->next = NULL;
        p->val = MIN;
    }
    return p;
}



void Spush(Stack * p, Ele a)
{

    Stack* tmp;
    tmp = (Stack*)malloc(sizeof(Stack));
    tmp->val = a;
    tmp->next = p->next;
    p->next = tmp;

}


Ele Spop(Stack * p)
{
    Ele tmp;
    Stack* t;
    if (!(p->next))
        printf("��ջΪ��\n");
    else
    {
        tmp = p->next->val;
        t = p->next;
        p->next = t->next;
        free(t);
        t = NULL;
    }
    return tmp;
}




void push(int node) {
    // write code here
    if (!S1)
        S1 = Create_Stack();
    if (!S2)
        S2 = Create_Stack();
    Spush(S1, node);
}



int pop() {
    // write code here
    Ele data;

    if (!S1)
        S1 = Create_Stack();
    if (!S2)
        S2 = Create_Stack();

    if (S2->next == NULL)
    {
        while (S1->next != NULL)
        {
            data = Spop(S1);
            Spush(S2, data);
        }
    }
    if (S2->next == NULL)
        printf("�����Ѿ�����");
    data = Spop(S2);
    return data;
}
