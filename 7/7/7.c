/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode��
     * @param o1 int����
     * @param o2 int����
     * @return int����
     */
    TreeNode* process(TreeNode* root, int o1, int o2) {
        if (root == nullptr)
            return nullptr;
        if (root->val == o1 || root->val == o2)		//�����ǰ�ڵ�������һ����ֻ���������ܣ�һ�ǹ����ڵ㣬����һ����֧
            return root;
        TreeNode* left = process(root->left, o1, o2);
        TreeNode* right = process(root->right, o1, o2);
        //�������������Ϊ�գ���ǰ�ڵ��Ϊ�����ڵ㣬����root
        //���������Ϊ�գ��򹫹��ڵ������������
        return left != nullptr ? right != nullptr ? root : left : right;
    }

    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        int common_father = process(root, o1, o2)->val;
        return common_father;
    }
};
