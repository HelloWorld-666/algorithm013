/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    // dp:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j == 0) // (1) 位于原点(0,0)时
                {
                    continue;
                }
                else if (i == 0)      // (2) 当前点位于最上面一行（上边界x=0）时：只能从原点向右移动，从"左"边过来
                {
                    grid[i][j] = grid[i][j - 1] + grid[i][j]; 
                }
                else if (j == 0)      // (3) 当前点位于最左边一列（左边界y=0）时：只能从原点向下移动，从"上"边过来
                {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
                else                  // (4) 当前点既不在最上面一行(i != 0)，也不在最左边一列(j != 0)，此时选取其上或其左位置点的最小值
                {
                    grid[i][j] = min(grid[i - 1][j]/*上面位置*/, grid[i][j - 1]/*左面位置*/) + grid[i][j];
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];   // 最终返回右下角的累计的最小路径和
    }
};
// @lc code=end

