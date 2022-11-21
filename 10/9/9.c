* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param node int整型
* @return 无
*
*C语言声明定义全局变量请加上static，防止重复定义
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
        printf("空间不够了\n");
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
        printf("堆栈为空\n");
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
        printf("队列已经空了");
    data = Spop(S2);
    return data;
}
