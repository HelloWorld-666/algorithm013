/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five++;
            } 
            else if (bills[i] == 10)
            {
                if (five == 0)
                {
                    return false;
                }
                ten++;
                five--;
            }
            else    // 20 
            {
                if (ten > 0 && five > 0)             // ok
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)                  // ok
                {
                    five -= 3;
                }
                else // if (ten > 0 && five == 0)    // not ok
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

