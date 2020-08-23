/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;  // 每次保留遍历过的元素中最远位置，若最远位置大于末尾元素所在位置，则可到达返回true
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
                return false;
            k = max(k, i + nums[i]);    // 当前能到达的最远位置 (i + nums[i])为: (当前位置i + 当前最远能跳到的步数nums[i])，然后与之前能到达的最远位置k比较，保留较大的一个
        }
        return true;
    }
};
// @lc code=end

