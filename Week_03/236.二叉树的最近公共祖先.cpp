/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // 1.递归终止条件：
    if (root == p || root == q || root == NULL)                 // root为三种情况之一，直接返回
        return root;
 
    // 2.下探到下一层：分别向左向右递归
    TreeNode* left = lowestCommonAncestor(root->left  , p, q);  // 检查左子树是否含有p或q
    TreeNode* right = lowestCommonAncestor(root->right, p, q);  // 检查右子树是否含有p或q
 
    // 3.处理当前逻辑层：
    if (left == NULL && right == NULL)                          // 找到叶子节点后依然没找到（叶子节点左右都为空时）
        return NULL;
    else if (left != NULL && right == NULL)                     // 右子树中没有，说明在左子树
        return left;                        
    else if (left == NULL && right != NULL)                     // 左子树中没有，说明在右子树
        return right;
    else // else if (left != NULL && right != NULL)             // 如果在root的左右子树中都找到了，返回root（左右子树分叉前的根节点）
        return root;

    }
};
// @lc code=end

