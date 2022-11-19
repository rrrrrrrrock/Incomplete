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
  * @return bool布尔型
  */
#include <stdbool.h>

bool isCompleteTree(struct TreeNode* root) {
    // write code here

    //如果是空树，返回0
    if (root == NULL) {
        return 0;
    }
    //如果不是空树，初始化一个数组做队，用于层序遍历树
    struct TreeNode* queue[100];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;//头结点入队

    //当队不是空的时候
    while (head != tail) {
        struct TreeNode* node = queue[head];
        //如果当前结点左空，右不空，既不是完全二叉树
        if (node->left == NULL && node->right != NULL) {
            return 0;
        }
        //如果当前节点左右都不是空，那么将其左右节点入队，队列头结点出队
        if (node->left != NULL && node->right != NULL) {
            queue[tail++] = node->left;
            queue[tail++] = node->right;
            head++;
        }
        //如果当前结点 左不空且右空，或者，左右都空，那么只有队列中此节点之后的所有结点都没有子节点，
        //即都是叶子结点，才是完全二叉树
        if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right == NULL)) {
            //如果当前结点有左节点，那么把左节点入队
            if (node->left != NULL && node->right == NULL) {
                queue[tail++] = node->left;
            }

            head += 1;//从队中当前结点之后一个结点检查

            //一旦进入此if，那么必将一直执行下面的while直到返回值
            while (head != tail) {
                struct TreeNode* node = queue[head];
                //判断结点是不是叶子结点，如果是叶子结点，那么出队头结点，检查下一个结点
                if (node->left == NULL && node->right == NULL) {
                    head++;
                }
                else {//如果不是叶子结点，返回0
                    return 0;
                }
            }
            return 1;
        }
    }
    return 1;
}
