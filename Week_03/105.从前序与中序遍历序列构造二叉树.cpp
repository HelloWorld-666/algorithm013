/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
private:
    unordered_map<int, int> map;            // 全局map
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 0.判断前序遍历和中序遍历节点数是否一致
        int preLen = preorder.size();
        int inLen = inorder.size();
        if (preLen != inLen) 
            return NULL;

        // 1.先将中序遍历结果的数组映射到hash表（值:下标）中，方便快速定位根节点位置：
        for (int i = 0; i < inLen; i++)  
        {
            map[inorder[i]] = i;
        }

        return myBuildTree(preorder, 0, preLen - 1, inorder, 0, inLen - 1); // 数组下标从0开始
    }

    TreeNode* myBuildTree(vector<int> preorder, int preLeft, int preRight, 
                        vector<int> inorder, int inLeft, int inRight)
    {
        /**************递归终止条件：**************/
        // 2.当preLeft最终于preRight相遇则返回NULL：
        if (preLeft > preRight || inLeft > inRight)
        {
            return NULL;
        }

        // 3.通过之前的map，在中序遍历中定位根节点位置pIndex
        int rootVal = preorder[preLeft];                // 获取前序遍历的根节点
        int pIndex = map[rootVal];                      // 获取中序遍历根节点rootVal的下标
        TreeNode* root = new TreeNode(rootVal);         // 构建的二叉树的根节点

        /**************处理当前逻辑层 + 下探到下一层：**************/
        // 4.递归构建左子树，并连接到根节点（root->left）：
        root->left = myBuildTree(preorder, preLeft + 1, pIndex - inLeft + preLeft, inorder, inLeft, pIndex - 1);  
        // 5.递归构建右子树，并连接到根节点（root->right）：
        root->right = myBuildTree(preorder, pIndex - inLeft + preLeft + 1, preRight, inorder, pIndex + 1, inRight); 

        return root;
    }       
};
// @lc code=end

