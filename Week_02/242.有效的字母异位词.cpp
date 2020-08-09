/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1.题目要求:你可以假设字符串只包含小写字母
        int sLength = s.length();
        int tLength = t.length();
        if (sLength != tLength)
            return false;

        int sArray[123] = {};
        int tArray[123] = {};
        for (int i = 0; i < sLength; i++)
        {
            sArray[(int)s[i]] += 1; // 使用字符串s和t的ascii码值做为 “临时数组下标”
            tArray[(int)t[i]] += 1; // 使用字符串s和t的ascii码值做为 “临时数组的值”
        } 
        for (int i = 97; i < 123; i++)  // 注意这里只比较97('a')-123('z')的数组下标中的值
        {
            if (sArray[i] != tArray[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

