/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> v;                                                  // 函数外定义全局vector容器v !!!
    vector<int> preorder(Node* root) {
        // 1.递归
        // if (root == NULL)
        //     return {};
        
        // v.push_back(root->val);
        // for (int i = 0; i < root->children.size(); i++)          // 将root的子节点从右向左压入栈中
        // {
        //     preorder(root->children[i]);
        // }
        
        // return v;

        // 2.迭代：
        if (root == NULL) 
            return {};

        vector<int> v;
        stack<Node*> st;
        st.push(root);
        while (!st.empty())                                         // error: while (root != NULL)
        {
            root = st.top();
            v.push_back(root->val);                                 // root出栈前先将val值存入vector容器中
            st.pop();
            for (int i = root->children.size() - 1; i >= 0; i--)    // 将root的子节点从右向左压入栈中
            {
                st.push(root->children[i]);
            }
        }
        return v;
    }
};
// @lc code=end

