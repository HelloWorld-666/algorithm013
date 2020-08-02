/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // // 1.精简版：
        // int i,j;    // i：慢指针 j：快指针
        // for (i = 0, j = 0; j < nums.size(); j++)    
        // {
        //     if (nums[j] != 0)
        //     {
        //         swap(nums[i++], nums[j]);
        //     }
        // }

        // 2.原版
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            if (nums[j] == 0)
            {
                j++;
            }
            else
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            }
        }

    }
};
// @lc code=end

