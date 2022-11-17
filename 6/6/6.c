* struct TreeNode {
    *int val;
    *struct TreeNode* left;
    *struct TreeNode* right;
    *
};
*
*C语言声明定义全局变量请加上static，防止重复定义
* /
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param root TreeNode类
 * @return bool布尔型
 */
#include <limits.h>
#include <stdbool.h>
    bool isValidBSTFunc(struct TreeNode* root, int l, int r) {
    if (root == NULL) {
        return true;
    }
    if (l > root->val || root->val > r) {
        return false;
    }
    return isValidBSTFunc(root->left, l, root->val) && isValidBSTFunc(root->right, root->val, r);
}
bool isValidBST(struct TreeNode* root) {
    // write code here

    return isValidBSTFunc(root, INT_MIN, INT_MAX);
}
