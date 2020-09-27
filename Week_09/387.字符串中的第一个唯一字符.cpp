/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    /*
        思路(类似于上一题)：
		1.定义长度为123的字符数组sArray
		2.先遍历字符串s，将其中每个字符的ASCII码值作为下标index，将sArray[index]的值累加，index++
		3.再顺序遍历一遍字符串s，在字符数组sArray中找到第一个sArray[(int)s[i]]为1的字符，并返回
    */
    int firstUniqChar(string s) {
        // int sLength = s.length();
        // int sArray[123] = {};
        // for (int i = 0; i < sLength; i++)
        // {
        // 	sArray[(int)s[i]]++;
        // }


        // for (int i = 0; i < sLength; i++)
        // {
        // 	if (sArray[(int)s[i]] == 1)
        // 	    return i;
        // }

        // return -1;

        // 二： 数组长度由123 -> 27:
        int len = s.length();
        int cntArray[27] = {};                      // 下标为0的元素占位用
        // 计数：
        for (int i = 0; i < len; i++)
        {
            cntArray[(int)(s[i] - 'a' + 1)] += 1;   // 数组下标从1开始，需要+1
        } 

        // 筛选：
        for (int i = 0; i < len; i++)
        {
            if (cntArray[(int)(s[i] - 'a' + 1)] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
