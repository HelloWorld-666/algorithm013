/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // //1.
        // unordered_map<int, int> hm;         // key存元素值，value存元素下标
        // vector<int> v;                      // 存符合条件的元素下标
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int n = target - nums[i];
        //     if (hm.find(n) != hm.end())    // 如果nums[i]与hm中的已有元素匹配
        //     {
        //         v.push_back(hm[sub]);
        //         v.push_back(i);
        //         return v;                 // 返回下标
        //     }
        //     hm[nums[i]] = i;               // 不匹配，直接存入hm中
        // }
        // return v;

        // 2.类似于1，只是不使用vector存下标，直接返回
        unordered_map<int, int> hm;     // key存元素值，value存元素下标
        for (int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i];
            if (hm.find(n) != hm.end()) // 如果nums[i]与hm中的已有元素匹配
            {
                return {hm[n], i};      // 返回下标
            }
            hm[nums[i]] = i;            // 不匹配，直接存入hm中 
        }
        return {};

    }
};
// @lc code=end

