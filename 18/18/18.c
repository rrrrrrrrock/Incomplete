
// 递归求全排列
void func(
    int* num, // 输入 一维数组
    int** Res, // 输出 一维数组
    int* res, // 递归 一维数组
    int* flag, // 排列 标记
    int numLen, // 排列 长度
    int inx, // 当前 长度
    int* p) // 输出 一维数组的下标
{
    if (inx < numLen) // 递归排列中
    {
        for (int i = 0; i < numLen; i++)
        {
            if (flag[i] == 0)
            {
                res[inx] = num[i]; // 记录
                flag[i] = 1;  // 向前!!!!!
                func(num, Res, res, flag, numLen, inx + 1, p); // 递归
                flag[i] = 0; // 回溯!!!!!!
            }
        }
    }
    else
    {
        int* temp = (int*)malloc(sizeof(int) * numLen);
        memcpy(&temp[0], &res[0], sizeof(int) * numLen);
        Res[p[0]] = temp; // 指针指向拷贝的数组
        p[0] += 1; // 指针偏移,就是下标,不写成*p,写成p[0],一样,大概``
    }
}


int** permute(
    int* num, // 输入 一维数组
    int numLen, // 输入 一维数组的长度
    int* returnSize, // 返回 二维数组的一维长度
    int** returnColumnSizes)  // 返回 二维数组的二维长度
{
    // 对输入排序,之后生成的排列就有顺序了
    for (int i = 0; i < numLen - 1; i++)
    {
        int k = i;
        for (int j = k + 1; j < numLen; j++)
        {
            if (num[k] > num[j])
            {
                k = j;
            }
        }
        if (k != i)
        {
            int temp = num[k];
            num[k] = num[i];
            num[i] = temp;
        }
    }

    // 求长度
    int sum = 1;
    for (int i = 1; i <= numLen; i++)
        sum *= i;
    returnSize[0] = sum;
    int* col = (int*)malloc(sizeof(int) * sum);
    for (int i = 0; i < sum; i++)
        col[i] = numLen;
    returnColumnSizes[0] = col;

    // 递归全排列
    int** Res = (int**)malloc(sizeof(int*) * sum);
    int* res = (int*)malloc(sizeof(int) * numLen);
    int* flag = (int*)malloc(sizeof(int) * numLen);
    int p = 0;
    // 本来没想加这个的,想在递归函数里用指针偏移,不知道为什么不成功,找不到问题,最后发现换成数组的形式可以,还是数组好用
    func(num, Res, res, flag, numLen, 0, &p); // 递归

    return Res;
}
