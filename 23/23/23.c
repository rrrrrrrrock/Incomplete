int helper(int* f, int n) {
    if (n == 1 || n == 2)
        f[n] = n;
    else if (f[n] == 0) // n>2 �� f[n] δ����
        f[n] = helper(f, n - 2) + helper(f, n - 1);
    return f[n];
}

int jumpFloor(int n) {
    int f[n + 1]; // f[n] ��¼������ n ���ж����ַ���
    memset(f, 0, sizeof(int) * (n + 1)); // �˴�ֵ��ע�⣬�����ֽ�Ϊ��λȥ��ʼ����
    return helper(f, n);
}