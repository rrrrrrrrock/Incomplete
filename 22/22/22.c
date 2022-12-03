/*
¶¯Ì¬¹æ»®£¬d[n] = min(d[i-1]+cost[i-1],d[i-2]+cost[i-2]);
*/

int min(int a, int b) {
    if (a > b) return b;
    else return a;
}


int minCostClimbingStairs(int* cost, int costLen) {
    if (costLen == 1) return cost[0];
    int dp[costLen + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < costLen + 1; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[costLen];
}