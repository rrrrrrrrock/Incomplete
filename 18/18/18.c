
// �ݹ���ȫ����
void func(
    int* num, // ���� һά����
    int** Res, // ��� һά����
    int* res, // �ݹ� һά����
    int* flag, // ���� ���
    int numLen, // ���� ����
    int inx, // ��ǰ ����
    int* p) // ��� һά������±�
{
    if (inx < numLen) // �ݹ�������
    {
        for (int i = 0; i < numLen; i++)
        {
            if (flag[i] == 0)
            {
                res[inx] = num[i]; // ��¼
                flag[i] = 1;  // ��ǰ!!!!!
                func(num, Res, res, flag, numLen, inx + 1, p); // �ݹ�
                flag[i] = 0; // ����!!!!!!
            }
        }
    }
    else
    {
        int* temp = (int*)malloc(sizeof(int) * numLen);
        memcpy(&temp[0], &res[0], sizeof(int) * numLen);
        Res[p[0]] = temp; // ָ��ָ�򿽱�������
        p[0] += 1; // ָ��ƫ��,�����±�,��д��*p,д��p[0],һ��,���``
    }
}


int** permute(
    int* num, // ���� һά����
    int numLen, // ���� һά����ĳ���
    int* returnSize, // ���� ��ά�����һά����
    int** returnColumnSizes)  // ���� ��ά����Ķ�ά����
{
    // ����������,֮�����ɵ����о���˳����
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

    // �󳤶�
    int sum = 1;
    for (int i = 1; i <= numLen; i++)
        sum *= i;
    returnSize[0] = sum;
    int* col = (int*)malloc(sizeof(int) * sum);
    for (int i = 0; i < sum; i++)
        col[i] = numLen;
    returnColumnSizes[0] = col;

    // �ݹ�ȫ����
    int** Res = (int**)malloc(sizeof(int*) * sum);
    int* res = (int*)malloc(sizeof(int) * numLen);
    int* flag = (int*)malloc(sizeof(int) * numLen);
    int p = 0;
    // ����û��������,���ڵݹ麯������ָ��ƫ��,��֪��Ϊʲô���ɹ�,�Ҳ�������,����ֻ����������ʽ����,�����������
    func(num, Res, res, flag, numLen, 0, &p); // �ݹ�

    return Res;
}
