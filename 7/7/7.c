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
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    TreeNode* process(TreeNode* root, int o1, int o2) {
        if (root == nullptr)
            return nullptr;
        if (root->val == o1 || root->val == o2)		//如果当前节点是其中一个，只有两个可能，一是公共节点，二是一个分支
            return root;
        TreeNode* left = process(root->left, o1, o2);
        TreeNode* right = process(root->right, o1, o2);
        //如果左右子树不为空，则当前节点必为公共节点，返回root
        //如果左子树为空，则公共节点必在右子树上
        return left != nullptr ? right != nullptr ? root : left : right;
    }

    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        int common_father = process(root, o1, o2)->val;
        return common_father;
    }
};
