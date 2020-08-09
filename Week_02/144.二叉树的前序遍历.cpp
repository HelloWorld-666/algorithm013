/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;

        while (root != NULL || !st.empty())
        {
            while (root != NULL)    	// 不断向左子节点遍历
            {
                v.push_back(root->val); 	// 输出
                st.push(root);
                root = root->left;
            }

            if (!st.empty())
            {
                root = st.top();    		// 获取栈顶元素
                root = root->right;
                st.pop();
            }
        }
        return v;
    }
};
// @lc code=end

