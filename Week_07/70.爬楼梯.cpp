/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 1.递归：
    // int climbStairs(int n) {
    //     if(n==1)
    //         return 1;
    //     else if(n==2) 
    //         return 2;
    //     else   
    //         return climbStairs(n-2)+climbStairs(n-1);
    // }

    // 2.dp：
    // int climbStairs(int n) {
    //     int* dp = new int[n + 1];   // 因为数组下标从0开始，故 n + 1.
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    // 3.dp基础上优化（不保存数组，只保存 n-1 和 n-2 两个临时变量）：
    int climbStairs(int n) {
        int temp1 = 1;
        int temp2 = 1;
        int sum = 1;                     // 初始值为1：当一阶台阶时，可能数为1
        for (int i = 2; i <= n; i++)     // 从第二阶台阶开始计算
        {
            sum = temp1 + temp2;
            temp1 = temp2;
            temp2 = sum;
        }
        return sum;
    }
};
// @lc code=end

