/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;  // 初始时为有足够空间的nums1末尾下标
        while (n)               // 条件：当nums2中的所有元素都移动至nums1中时，直至0
        {
            if (m == 0)
            {
                nums1[index--] = nums2[--n];
                // n--;    // 下标从0开始
                // nums1[index] = nums2[n];
            }
            else if (nums1[m - 1] < nums2[n - 1]) // n-1：下标从0开始
            {
                nums1[index--] = nums2[n - 1];
                n--;
            }
            else                // 包含 nums1[i] == nums2[j] 的情况
            {
                nums1[index--] = nums1[m - 1];
                m--;
            }
        }
    }
};
// @lc code=end

