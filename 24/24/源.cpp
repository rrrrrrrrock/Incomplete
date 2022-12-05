import java.util.*;
public class Solution {
    public void recursion(ArrayList<ArrayList<Integer>> res, int[] num, ArrayList<Integer> temp, Boolean[] vis) {
        //��ʱ�������˼������
        if (temp.size() == num.length) {
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        //��������Ԫ��ѡȡһ������
        for (int i = 0; i < num.length; i++) {
            //�����Ԫ���Ѿ�������������Ҫ�ټ�����
            if (vis[i])
                continue;
            if (i > 0 && num[i - 1] == num[i] && !vis[i - 1])
                //��ǰ��Ԫ��num[i]��ͬһ���ǰһ��Ԫ��num[i-1]��ͬ��num[i-1]�Ѿ��ù���
                continue;
            //���Ϊʹ�ù�
            vis[i] = true;
            //��������
            temp.add(num[i]);
            recursion(res, num, temp, vis);
            //����
            vis[i] = false;
            temp.remove(temp.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        //�Ȱ��ֵ�������
        Arrays.sort(num);
        Boolean[] vis = new Boolean[num.length];
        Arrays.fill(vis, false);
        ArrayList<ArrayList<Integer> > res = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> temp = new ArrayList<Integer>();
        recursion(res, num, temp, vis);
        return res;
    }
}
