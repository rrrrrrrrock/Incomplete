int solve(char* s) {
    int topIdx = 0;
    char operator[100] = { 0 };
    char temp[100][10] = { 0 };
    int m = 0, j = 0;
    //******************逆波兰转换，将中缀表达式转换成后缀表达式***********
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '*' || s[i] == '(') {
            operator[topIdx++] = s[i];
        }
        else if (s[i] == '+' || s[i] == '-') {
            if (operator[topIdx - 1] == '*') {
                while (operator[--topIdx] != '(' && topIdx >= 0)
                    temp[j++][0] = operator[topIdx];
                operator[++topIdx] = s[i];
                topIdx++;
            }
            else
                operator[topIdx++] = s[i];
        }
        else if (s[i] == ')') {
            while (operator[--topIdx] != '(' && topIdx >= 0)
                temp[j++][0] = operator[topIdx];
        }
        else {
            temp[j][m++] = s[i];
            if ((s[i + 1]'9') && i < len - 1) {
                j++;
                m = 0;
            }
            else if (i == len - 1)
                j++;
        }
    }
    //******* 连续减号改加号操作***************
    for (int i = 0, j = 1; i < topIdx; i++) {
        if (operator[i] == '-')
            while (operator[i + j] == '-' && (i + j) < topIdx)
                operator[i + j++] = '+';
    }
    //**************************************
    int lenoftemp = 0;
    if (topIdx != 0) {
        for (int i = topIdx - 1; i >= 0; i--)
            temp[j++][0] = operator[i];
        lenoftemp = j;
    }
    //**************用逆波兰表达式求解最终结果***********
    int result = 0;
    int integer[100];
    // int *integer=(int *)malloc(sizeof(int)*lenoftemp);
    for (int i = 0, topIdx = 0; i < lenoftemp; i++) {
        if (strcmp(temp[i], "+") == 0) {
            result = integer[topIdx - 2] + integer[topIdx - 1];
            topIdx--;
            integer[topIdx - 1] = result;
        }
        else if (strcmp(temp[i], "*") == 0) {
            result = integer[topIdx - 2] * integer[topIdx - 1];
            topIdx--;
            integer[topIdx - 1] = result;
        }
        else if (strcmp(temp[i], "-") == 0) {
            result = integer[topIdx - 2] - integer[topIdx - 1];
            topIdx--;
            integer[topIdx - 1] = result;
        }
        else
            integer[topIdx++] = atoi(temp[i]);
    }
    return integer[0];
}