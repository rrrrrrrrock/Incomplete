int res = -1;
int part(int* a, int low, int high) {//确定基准值
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
void my_qsort(int* a, int low, int high, int k) {//快排
    int mid = part(a, low, high);
    if (mid == k) res = a[mid];//如果当前基准值下标与k对应，得到第K大元素
    else if (mid < k) my_qsort(a, mid + 1, high, k);//在右子表寻找
    else my_qsort(a, low, mid - 1, k);//在左子表寻找
}
int findKth(int* a, int aLen, int n, int K) {
    // write code here
    my_qsort(a, 0, n - 1, n - K);
    return res;
}