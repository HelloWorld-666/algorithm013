/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int len = s.size(); 
        for (int i = 0; i < len; i++)
        {
            int left  = i;
            int right = i;
            while (left >= 0 && right < len && s[left--] == s[right++])
            {
                cnt++;
            }  
        
            left = i;
            right = i + 1;
            while (left >= 0 && right < len && s[left--] == s[right++])
            {
                cnt++;
            }
            /*************为什么把s[left--] == s[right++]拆出来答案就错误了呢？*************/
        //     int left  = i;
        //     int right = i;
        //     while (left >= 0 && right < len)
        //     {
        //         if (s[left--] == s[right++])
        //         {
        //             cnt++;

        //         }
        //     }  
        
        //     left = i;
        //     right = i + 1;
        //     while (left >= 0 && right < len)
        //     {
        //         if (s[left--] == s[right++])
        //         {
        //             cnt++;

        //         }
        //     }  
        }
        return cnt;
    }
};
// @lc code=end

