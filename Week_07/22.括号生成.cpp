/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
         _generate(0, 0, n, "");  // 自定向下
        return v;
    }

    void _generate(int left, int right, int n, string s) {
        // 1.递归终止条件
        if (left == n && right == n)
        {
            v.push_back(s);
            return;
        }
        
        // 2.处理当前逻辑层
        string s1 = s + '(';
        string s2 = s + ')';

        // 3.下探到下一层
        if (left < n)                           // 左括号数量 < n
            _generate(left + 1, right, n, s + '(');   // 左
        if (right < n && right < left)          // 右括号数量 < left 且 < n
            _generate(left, right + 1, n, s + ')');   // 右
    }

private: 
    vector<string> v;
};
// @lc code=end

