/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param value int����
 * @return ��
 *
 * C������������ȫ�ֱ��������static����ֹ�ظ�����
 */
struct stack {
    int val;
    struct stack* next;
};


static struct stack* s1;
static struct stack* s2;






void push(int value) {
    // write code here
    if (s1 == NULL) {
        s1 = malloc(sizeof(struct stack*));
        s1->val = value;
        s2 = malloc(sizeof(struct stack*));
        s2->val = value;
    }
    else {
        struct stack* tmp = malloc(sizeof(struct stack*));
        struct stack* tmp2 = malloc(sizeof(struct stack*));
        tmp->val = value;
        tmp->next = s1;
        s1 = tmp;
        if (s2->val > value) {
            tmp2->val = value;
            tmp2->next = s2;
            s2 = tmp2;
        }
        else {
            tmp2->val = s2->val;
            tmp2->next = s2;
            s2 = tmp2;
        }
    }


}

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param ��
 * @return ��
 */
void pop() {
    // write code here
    struct stack* tmp = s1->next;
    struct stack* tmp2 = s2->next;
    free(s1);
    free(s2);
    s1 = tmp;
    s2 = tmp2;

}

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param ��
 * @return int����
 */
int top() {
    // write code here
    return s1->val;
}

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param ��
 * @return int����
 */
int min() {
    // write code here
    return s2->val;
}