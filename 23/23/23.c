int helper(int* f, int n) {
    if (n == 1 || n == 2)
        f[n] = n;
    else if (f[n] == 0) // n>2 且 f[n] 未更新
        f[n] = helper(f, n - 2) + helper(f, n - 1);
    return f[n];
}

int jumpFloor(int n) {
    int f[n + 1]; // f[n] 记录爬到第 n 阶有多少种方法
    memset(f, 0, sizeof(int) * (n + 1)); // 此次值得注意，是以字节为单位去初始化的
    return helper(f, n);
}