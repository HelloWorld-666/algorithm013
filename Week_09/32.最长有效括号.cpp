/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> st;
        st.push(-1);                // 处理边界条件
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')        
                st.push(i);
            else
            {
                st.pop();           // 先出栈
                if (st.empty())     // 若栈为空，即使是')'也要入栈
                    st.push(i);
                else
                    maxLength = max(maxLength, i - st.top());
            }
        }
        
        return maxLength;
    }
};
// @lc code=end

