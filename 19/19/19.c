/*
当天持股/不持股所能获得的最大利益
当天持股 = max（前一天持股，前一天不持股 - 今天买入所花费）
dp[i][0] = max(dp[i-1][0],dp[i-1][1] - prices[i]);
当天不持股 = max（前一天不持股，前一天持股最大利益 + 今天卖出）
dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i]);
*/
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}


int maxProfit(int* prices, int pricesLen) {
    int dp[pricesLen][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < pricesLen; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[pricesLen - 1][1];
}