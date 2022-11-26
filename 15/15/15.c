int res = -1;
int part(int* a, int low, int high) {//ȷ����׼ֵ
    int pos = a[low];
    while (low < high) {
        while (low < high && a[high] >= pos) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pos) low++;
        a[high] = a[low];
    }
    a[low] = pos;
    return low;
}
void my_qsort(int* a, int low, int high, int k) {//����
    int mid = part(a, low, high);
    if (mid == k) res = a[mid];//�����ǰ��׼ֵ�±���k��Ӧ���õ���K��Ԫ��
    else if (mid < k) my_qsort(a, mid + 1, high, k);//�����ӱ�Ѱ��
    else my_qsort(a, low, mid - 1, k);//�����ӱ�Ѱ��
}
int findKth(int* a, int aLen, int n, int K) {
    // write code here
    my_qsort(a, 0, n - 1, n - K);
    return res;
}