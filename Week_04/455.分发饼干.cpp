/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 贪心算法：优先满足胃口值小的孩子，再满足胃口值大的孩子...
        // if (g.size() == 0 || s.size() == 0)
        //     return 0; 

        sort(g.begin(), g.end());               // 先对孩子胃口值从小到大排序
        sort(s.begin(), s.end());               // 再对饼的干尺寸从小到大排序 
        int num = 0;
        int i = 0;                              // 胃口值：g[i] 
        int j = 0;                              // 每块饼干尺寸：s[j]
        
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])                   // 若饼干尺寸 >= 孩子胃口值，满足的孩子数量+1，遍历下一个孩子和下一个饼干
            {
                num++;
                i++;                            // 满足条件则轮到下一个孩子（排好序）
                j++;                            // 当前饼干使用完，使用下一块饼干（排好序）
            }
            else 
            {
                j++;                            // 不满足的话，试探下一块儿更大的饼干，看是否满足当前孩子
            }
        }
        return num;
    }
};
// @lc code=end

