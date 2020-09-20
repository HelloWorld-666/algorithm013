/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) 
            return false;
        while (n % 2 == 0 /*&& n > 1*/) // 若n为2的幂次方，则当 n > 1 时：n % 2 = 0；若 n % 2 != 0，退出循环，判断最终n是否为1
        {                           
            n = n >> 1;
        }
        if (n == 1)                 // 最终 n == 1 则是2的幂次方数
            return true;
        else 
            return false;           // 最终 n != 1 则不是2的幂次方数
        
        // if (n == 0) 
        //     return false;
        // while (n % 2 == 0) 
        // {
        //     n /= 2;
        // }
        // return n == 1;
    }
};
// @lc code=end

