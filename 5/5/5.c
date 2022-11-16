/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param root TreeNode类
  * @return int整型二维数组
  * @return int* returnSize 返回数组行数
  * @return int** returnColumnSizes 返回数组列数
  */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;   //特殊情况，空树
    if (root == NULL)
        return NULL;
    struct TreeNode* queue[100001];  //新建队列
    int** res = (int**)malloc(sizeof(int*) * 100001);  //为res分配内存，res实际上是一个数组，数组内存的内容是指向int型数组的地址，即构成一个二维数组
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100001);  //为存储数组列数的数组分配空间，即存入每层多少个元素

    int head = 0, rear = 0;  //设队列的头尾指针
    queue[rear] = root;   //根结点入队，尾指针后移一位
    rear++;

    while (head != rear) {    //队列非空时
        int preRear = rear;  //记录当前层的尾结点
        int k = 0;           //当前层的结点数量
        res[*returnSize] = (int*)malloc(sizeof(int) * (preRear - head)); //为二维数组res的第*returnSize行分配空间
        while (head < preRear) {  //遍历当前层结点
            struct TreeNode* p = queue[head];   //队头元素出队
            res[*returnSize][k++] = p->val; //更新返回数组中的值
            if (p->left != NULL)   //将当前出队元素的左孩子结点入队
                queue[rear++] = p->left;
            if (p->right != NULL)  //将当前出队元素的右孩子结点入队
                queue[rear++] = p->right;
            head++;  //队头指针后移一位
        }
        (*returnColumnSizes)[*returnSize] = k;  //更新返回数组本层结点个数
        (*returnSize)++;  //指针指向下一层返回数组
    }


    return res;
}
