/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        // 1.判断原串是否符合回文要求
        // 2.如果原串不符合回文，那试图删除一个元素，看最终能否构成回文
        int left = 0;
        int right = s.length() - 1;
        while (left <= right) 
        {
            if (s[left] == s[right]) {  // equal
                left++;
                right--;
            } else {                    // not equal: 删除左或右的一个字符后再判断
                // 删除一个，两种情况:(1)发现不为回文字符时，删掉左边字符 (2) 发现不为回文字符时，删掉右边字符
                return checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right - 1); 
            }
        }

        return true;
    }

    bool checkPalindrome(string s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

