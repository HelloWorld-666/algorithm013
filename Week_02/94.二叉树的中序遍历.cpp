/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;

        while (root != NULL || !st.empty())
        {
            while (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            if (!st.empty())
            {
                root = st.top();
                v.push_back(root->val); // cout << root->val;
                st.pop();
                root = root->right;
            }
        }
        return v;
    }
};
// @lc code=end

