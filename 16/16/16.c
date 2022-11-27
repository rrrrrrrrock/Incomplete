void Swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
int MyQsort(int* arr, int start, int end) {
    int low, high;
    int temp = arr[start];//It doesn't matter what the value is

    if (start >= end) {
        return 0;
    }
    low = start + 1;
    high = end;
    while (low < high) {
        if (arr[low] > temp) {
            Swap(&arr[high], &arr[low]);
            high--;

        }
        else {
            low++;
        }

    }
    if (arr[low] >= temp) { //the position of low should be less than temp
        low--;
    }
    Swap(&arr[start], &arr[low]);//put the temp in a proper position

    MyQsort(arr, start, low);
    MyQsort(arr, high, end);

    return 0;
}




/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param input int����һά����
 * @param inputLen int input���鳤��
 * @param k int����
 * @return int����һά����
 * @return int* returnSize ������������
 */
int* GetLeastNumbers_Solution(int* input, int inputLen, int k,
    int* returnSize) {
    // write code here
    MyQsort(input, 0, inputLen - 1);

    *returnSize = k;

    int* retarr = (int*)malloc((sizeof(int) * k));
    if (retarr == NULL) {
        return  NULL;
    }
    memcpy(retarr, input, sizeof(int) * k);

    return retarr;
}