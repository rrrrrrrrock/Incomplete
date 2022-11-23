* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param s string字符串
* @return bool布尔型
*
*C语言声明定义全局变量请加上static，防止重复定义
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
