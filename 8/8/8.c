/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 *
 * C������������ȫ�ֱ��������static����ֹ�ظ�����
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param pre int����һά����
  * @param preLen int pre���鳤��
  * @param vin int����һά����
  * @param vinLen int vin���鳤��
  * @return TreeNode��
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
