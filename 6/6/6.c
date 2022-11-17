* struct TreeNode {
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
 * @return bool������
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
