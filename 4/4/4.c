//重构二叉树
struct TreeNode* reConstruct(int* xianxu, int xianxuLen, int* zhongxu, int zhongxuLen) {
    if (xianxuLen == 0)
        return NULL;
    struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    head->val = xianxu[0];
    int k = 0;
    int left_length = 0;
    int right_length = 0;
    while (xianxu[0] != zhongxu[k]) {
        k++;
    }
    left_length = k;
    right_length = zhongxuLen - k - 1;
    head->left = reConstruct(xianxu + 1, left_length, zhongxu, left_length);
    head->right = reConstruct(xianxu + k + 1, right_length, zhongxu + k + 1, right_length);
    return head;
}

//层序遍历二叉树
int** leveltraves(struct TreeNode* Thead, int* returnSize, int* returnCsize) {
    if (Thead == NULL) {
        return NULL;
    }
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * 10000);
    struct TreeNode* q[10000];
    int head = 0, tail = 0;
    q[tail++] = Thead;
    while (head != tail) {
        int pretail = tail;
        int k = 0;
        res[*returnSize] = (int*)malloc(sizeof(int) * pretail - head);
        while (head != pretail) {
            struct TreeNode* p = q[head];
            res[*returnSize][k++] = p->val;
            if (p->left) {
                q[tail++] = p->left;
            }
            if (p->right) {
                q[tail++] = p->right;
            }
            head++;
        }
        returnCsize[*returnSize] = k;
        (*returnSize)++;
    }
    return res;
}
//主函数
int* solve(int* xianxu, int xianxuLen, int* zhongxu, int zhongxuLen, int* returnSize) {
    if (xianxuLen == 0) {
        return NULL;
    }
    //重构二叉树
    struct TreeNode* Thead = reConstruct(xianxu, xianxuLen, zhongxu, zhongxuLen);
    //层序遍历二叉树
    int returnCsize[10000];
    int** res = leveltraves(Thead, returnSize, returnCsize);
    //将每一层的结点个数取出放入一个数组中（可以整合到下一步中，单独写出来比较清楚）
    int count_of_each_level[*returnSize];
    for (int i = 0; i < *returnSize; i++) {
        count_of_each_level[i] = returnCsize[i];
    }
    //将每一层最后一个结点输出
    int resArry[*returnSize];
    for (int i = 0; i < *returnSize; i++) {
        int j = count_of_each_level[i];
        resArry[i] = res[i][j - 1];
    }
    return resArry;
}
