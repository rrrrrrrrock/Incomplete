import java.util.*;
public class Solution {
    public int minmumNumberOfHost(int n, int[][] startEnd) {
        int[] start = new int[n];
        int[] end = new int[n];
        //�ֱ�õ����ʼʱ��
        for (int i = 0; i < n; i++) {
            start[i] = startEnd[i][0];
            end[i] = startEnd[i][1];
        }
        //��������
        Arrays.sort(start, 0, start.length);
        Arrays.sort(end, 0, end.length);
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            //�¿�ʼ�Ľ�Ŀ������һ�ֽ�����ʱ�䣬�����˲���
            if (start[i] >= end[j])
                j++;
            else
                //����������
                res++;
        }
        return res;
    }
}
