/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 方法1：两端不同则分别取反，相同则不做操作
        // bitset<32> b=n;
        // for (int i = 0; i < 16; i++)
        // {
        //     if (b[i] != b[31 - i])
        //     {
        //         b[i] = !b[i];          // 第0位  取反
        //         b[31-i] = !b[31-i];    // 第31位 取反
        //     }
        // }
        // return b.to_ulong();//将bitset转换成unsigned long类型
     
        // 方法2：用bitset库   // 110 -> 011
        uint32_t res = 0;
        for (int i = 32; i > 0; i--)
        {
            res = res << 1; 
            res = res + (n & 0x1);  // 每次与上n的末位，然后n右移一位... 0 01 011
            n = n >> 1;            
        }

        return res;
    }
};
// @lc code=end

