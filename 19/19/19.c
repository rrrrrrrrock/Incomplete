/*
����ֹ�/���ֹ����ܻ�õ��������
����ֹ� = max��ǰһ��ֹɣ�ǰһ�첻�ֹ� - �������������ѣ�
dp[i][0] = max(dp[i-1][0],dp[i-1][1] - prices[i]);
���첻�ֹ� = max��ǰһ�첻�ֹɣ�ǰһ��ֹ�������� + ����������
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