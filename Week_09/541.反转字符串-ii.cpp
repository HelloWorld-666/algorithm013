/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i += 2 * k)                   // 每次前进2k个(每次若能前进则剩余一定是>2k)
        {
            // 1. "每隔2k个字符" 或 "k < 剩余字符 < 2k":         // 反转前k个
            // 这里i每次前进2k个，若加了2k都能再次进入for循环，说明剩余字符一定大于等于2k
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);     
                continue;
            }
            // 2. 剩余字符 < k：                                // 剩余全部反转
            reverse(s.begin() + i, s.end());                
        }
        return s;
    }
};
// @lc code=end

