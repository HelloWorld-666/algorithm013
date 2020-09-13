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
            for (int j = 0; j < grid[i].size(); j++)
            {
                // 不能任何情况都去加1操作，只有最初遍历到岛屿的时候，才加1
                if (grid[i][j] == '1')
                {
                    dfs(grid,i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        // 结束边界条件：0~size()之间，且grid[i][j]
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '0';    // 遍历过的位置标记为'0'（水），会改变原二维数组的数据
        dfs(grid, i - 1, j); // 左
        dfs(grid, i + 1, j); // 右
        dfs(grid, i, j + 1); // 上
        dfs(grid, i, j - 1); // 下
    }
};
// @lc code=end

