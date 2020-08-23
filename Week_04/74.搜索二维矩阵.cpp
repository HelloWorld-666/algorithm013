/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if (matrix.size() == 0)
        //     return false;

        // int i = 0;
        // int j = matrix[0].size() - 1;   // matrix[i][j]右上角的数为基准值
        // while (i < matrix.size() && j < matrix[0].size())
        // {
        //     if (target < matrix[i][j]) {
        //         j--;
        //     }
        //     else if (target > matrix[i][j]) {
        //         i++;
        //     }
        //     else {  // matrix[i][j] == target
        //         return true;
        //     }
        // }
        // return false;

        if (matrix.size() == 0)
            return false;

        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;   // 最后一行最后一个元素：m * n - 1
        int oneRowValNum = matrix[0].size();                // 每行的元素个数
        while (left <= right)
        {
            int midPos = (left + right) / 2;                // 二维数组展开后中间元素mid的下标
            int midRow = midPos / oneRowValNum;             // mid的行坐标对应于原矩阵中的行
            int midCol = midPos % oneRowValNum;             // mid的列坐标对应于原矩阵中的列
            int midVul = matrix[midRow][midCol];
            if (target == midVul)
                return true;
            else if (target < midVul)
                right = midPos - 1;                         // 如果目标值在中间数midVul的左边，则target可能位于right的左边，故缩小right范围
            else // if (target > midVul)                    
            {
                left = midPos + 1;                          // 如果目标值在中间数midVul的右边，则target可能位于right的右边，故缩小left范围
            }
        }
        return false;
    }
};
// @lc code=end

