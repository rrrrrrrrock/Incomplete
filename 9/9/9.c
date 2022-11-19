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
  * @param root TreeNode��
  * @return bool������
  */
#include <stdbool.h>

bool isCompleteTree(struct TreeNode* root) {
    // write code here

    //����ǿ���������0
    if (root == NULL) {
        return 0;
    }
    //������ǿ�������ʼ��һ���������ӣ����ڲ��������
    struct TreeNode* queue[100];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;//ͷ������

    //���Ӳ��ǿյ�ʱ��
    while (head != tail) {
        struct TreeNode* node = queue[head];
        //�����ǰ�����գ��Ҳ��գ��Ȳ�����ȫ������
        if (node->left == NULL && node->right != NULL) {
            return 0;
        }
        //�����ǰ�ڵ����Ҷ����ǿգ���ô�������ҽڵ���ӣ�����ͷ������
        if (node->left != NULL && node->right != NULL) {
            queue[tail++] = node->left;
            queue[tail++] = node->right;
            head++;
        }
        //�����ǰ��� �󲻿����ҿգ����ߣ����Ҷ��գ���ôֻ�ж����д˽ڵ�֮������н�㶼û���ӽڵ㣬
        //������Ҷ�ӽ�㣬������ȫ������
        if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right == NULL)) {
            //�����ǰ�������ڵ㣬��ô����ڵ����
            if (node->left != NULL && node->right == NULL) {
                queue[tail++] = node->left;
            }

            head += 1;//�Ӷ��е�ǰ���֮��һ�������

            //һ�������if����ô�ؽ�һֱִ�������whileֱ������ֵ
            while (head != tail) {
                struct TreeNode* node = queue[head];
                //�жϽ���ǲ���Ҷ�ӽ�㣬�����Ҷ�ӽ�㣬��ô����ͷ��㣬�����һ�����
                if (node->left == NULL && node->right == NULL) {
                    head++;
                }
                else {//�������Ҷ�ӽ�㣬����0
                    return 0;
                }
            }
            return 1;
        }
    }
    return 1;
}
