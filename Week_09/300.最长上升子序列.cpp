/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int len = nums.size(); 
        if (len == 0)
            return 0;
        vector<int> dp(len, 0);
        // dp[0] = 1;   
        for (int i = 0; i < len; i++)                               // error: for (int i = 1; i < len; i++)
        {
            dp[i] = 1;                                              // 元素本身，长度为1 
            for (int j = 0; j < i; j++)
            {                          
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1/*算上nums[i]*/);   // 若 nums[j] < nums[i]，则除dp[j]以外，还要算上nums[i]，所以长度+1
                }
            }
        }
        return *max_element(dp.begin(), dp.end());// dp[len - 1];   // 返回dp数组中最大值，即为最长递增子串的长度
    }
};
// @lc code=end

