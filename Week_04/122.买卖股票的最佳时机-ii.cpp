/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 1.贪心算法：初始设为今天的股价，若今天股价较昨天有上涨，则累加，否则不操作
        // 参考：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
        // int res = 0;
        // for (int i = 1; i < prices.size(); i++)
        // {   
        //     int sub = prices[i] - prices[i - 1];
        //     if (sub > 0)
        //     {
        //         res += sub;
        //     }

        // }
        // return res;

        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0)
            {
                res += diff;
            }
        }
        return res;
    }
};
// @lc code=end

