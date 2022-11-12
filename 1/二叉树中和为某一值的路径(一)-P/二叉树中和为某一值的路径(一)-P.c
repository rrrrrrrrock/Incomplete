#include<stdbool.h>

struct TreeNode {
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
 * @param sum int整型
 * @return bool布尔型
 */
    bool hasPathSum(struct TreeNode* root, int sum) {
    // write code here
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        if (sum == root->val) {
            return true;
        }
        return false;
    }
    return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
}
}