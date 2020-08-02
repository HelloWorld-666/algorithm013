/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)    // 数组下标从0开始
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;

            }
            else
            {
                digits[i] += 1;
                break;
            }
        }

        // 如果是9，99,999...那么经上面操作后，digits中所有元素都进位为0，digits长度 +1（末尾追加0），且首元素由于进位变为1
        if (digits[0] == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
// @lc code=end

