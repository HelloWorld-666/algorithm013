/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int i, j;
        for (i = 0, j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                // nums[i + 1] = nums[j];
                i++;
                nums[i] = nums[j];
                // j++;
            }
            // else
            // {
            //     j++;
            // }
        }
        return i + 1;
    }
};
// @lc code=end

