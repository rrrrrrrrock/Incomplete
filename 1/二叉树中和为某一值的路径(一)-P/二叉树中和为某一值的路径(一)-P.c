#include<stdbool.h>

struct TreeNode {
    *int val;
    *struct TreeNode* left;
    *struct TreeNode* right;
    *
};
*
*C������������ȫ�ֱ��������static����ֹ�ظ�����
* /
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param root TreeNode��
 * @param sum int����
 * @return bool������
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