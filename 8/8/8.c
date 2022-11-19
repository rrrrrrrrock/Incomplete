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
  * @param pre int整型一维数组
  * @param preLen int pre数组长度
  * @param vin int整型一维数组
  * @param vinLen int vin数组长度
  * @return TreeNode类
  */
struct TreeNode* reConstructBinaryTree(int* pre, int preLen, int* vin, int vinLen) {
    // write code here
    struct TreeNode* pRoot = 0;
    int iSite = 0;

    if ((NULL == pre) || (0 == preLen))
        return NULL;

    pRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(pRoot, 0, sizeof(struct TreeNode));
    pRoot->val = pre[0];
    while (pre[0] != vin[iSite])
    {
        iSite++;
    }
    pRoot->left = reConstructBinaryTree(pre + 1, iSite, vin, iSite);
    pRoot->right = reConstructBinaryTree(pre + iSite + 1, preLen - iSite - 1, vin + iSite + 1, vinLen - iSite - 1);

    return pRoot;
}
