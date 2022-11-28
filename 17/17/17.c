import java.util.*;
public class Solution {
    //��¼�ĸ�����
    private int[][] dirs = new int[][]{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    private int n, m;
    //��������������������Ԫ����
    public int dfs(int[][] matrix, int[][] dp, int i, int j) {
        if (dp[i][j] != 0)
            return dp[i][j];
        dp[i][j]++;
        for (int k = 0; k < 4; k++) {
            int nexti = i + dirs[k][0];
            int nextj = j + dirs[k][1];
            //�ж�����
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && matrix[nexti][nextj] > matrix[i][j])
                dp[i][j] = Math.max(dp[i][j], dfs(matrix, dp, nexti, nextj) + 1);
        }
        return dp[i][j];
    }
    public int solve(int[][] matrix) {
        //����Ϊ��
        if (matrix.length == 0 || matrix[0].length == 0)
            return 0;
        int res = 0;
        n = matrix.length;
        m = matrix[0].length;
        //i��j���ĵ�Ԫ��ӵ�е������·��
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                //�������ֵ
                res = Math.max(res, dfs(matrix, dp, i, j));
        return res;
    }
}
