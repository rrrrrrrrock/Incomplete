* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
*
*
* @param s string�ַ���
* @return bool������
*
*C������������ȫ�ֱ��������static����ֹ�ظ�����
* /
char trans(char char_r)
{
    if (char_r == ')')return '(';
    if (char_r == ']')return '[';
    if (char_r == '}')return '{';
    return 0;
}

bool isValid(char* s) {
    // write code here
    char* stack;
    int topIdx = 0;
    stack = (char*)malloc(strlen(s) * sizeof(char));
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[topIdx++] = s[i];
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (topIdx < 1)return 0;
            if (stack[topIdx - 1] == trans(s[i]))
            {
                stack[--topIdx] = '\0';
            }
        }
    }
    if (strlen(stack) > 0)return 0;
    else return 1;
}
