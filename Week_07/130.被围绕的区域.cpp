/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int rowSize;
    int colSize;

    void solve(vector<vector<char>>& board) {
        rowSize = board.size();
        if (rowSize == 0) {
            return;
        }
        colSize = board[0].size();
  
        // 寻找最左面和最右面行为0的区域
        for (int i = 0; i < rowSize; i++)
        {
            dfs(board, i, 0);                   // 矩阵最左侧一列
            dfs(board, i, colSize - 1);         // 矩阵最右侧一列: colSize - 1
        }

        // 寻找最上面和最下面行为0的区域
        for (int j = 1; j < colSize - 1; j++)   // j = 1
        {
            dfs(board, 0, j);                   // 矩阵最上面一行
            dfs(board, rowSize - 1, j);         // 矩阵最下面一行: rowSize - 1
           
        }

        // 
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (board[i][j] == 'A')         // 说明该位置直接或间接的连接到了边缘'O'(未被'X'包围的区域)
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')    // 说明该位置没有直接或间接的连接到了边缘'O'
                    board[i][j] = 'X';
            }
        }        
    }

    // 深度遍历：
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        // if (i > rowSize || i < 0 || j > colSize || j < 0 || board[i][j] != 'O')  // ???
        if (i >= rowSize || i < 0 || j >= colSize || j < 0 || board[i][j] != 'O')   // 遍历到非'O'位置的元素时，停止
            return;

        board[i][j] = 'A';                      // 对直接或间接连接'左右上下'边界的'O'(未被'X'包围的区域)位置做标记
        dfs(board, i - 1, j);                   // 左
        dfs(board, i + 1, j);                   // 右
        dfs(board, i, j + 1);                   // 上
        dfs(board, i, j - 1);                   // 下
    }
};
// @lc code=end

