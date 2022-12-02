/*
当前家不偷或偷
当前不偷所获最大利润 = max(前一天不偷，前一天偷)；
dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
当前偷所获最大利润 = 前一天没偷 + 今日所得
dp[i][1] = dp[i-1][0] + nums[i];
*/
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int rob(int* nums, int numsLen) {
    int dp[numsLen][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for (int i = 1; i < numsLen; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[numsLen - 1][0], dp[numsLen - 1][1]);
}