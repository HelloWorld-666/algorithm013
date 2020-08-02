/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        while (k > size)    // 注意不是if而是while，需不断循环取模，直到 k < size
        {
            k = k % size;
        }

        // 1.整个数组元素交换
        swapFun(nums, 0, size - 1);
        // 2.前半段：前 k 个元素交换
        swapFun(nums, 0, k - 1);
        // 3.后半段：后 size - k 个元素交换
        swapFun(nums, k, size - 1);
    }

    // 翻转函数
    void swapFun(vector<int>& nums, int left, int right)
    {
        while (left <= right)
        {
            swap(nums[left++], nums[right--]);  // 使用c++算法库自带交换函数，头文件为：#include <algorithm>
            // int tmp = nums[left];
            // nums[left] = nums[right];
            // nums[right] = tmp;
            // left++;
            // right--;
        }
    }
};
// @lc code=end

