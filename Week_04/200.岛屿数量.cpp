/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid,  int i, int j)
    {
        // 左右上下
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
            return; 

        grid[i][j] = '0';       // 将当前的值设为0，表示已经遍历过，标记以避免重复遍历
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
// @lc code=end

