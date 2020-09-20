/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
         /*
			方法一：
			思路：
			1.有效的字母异位词 两字符串长度一定相等，否则false
			2.将两字符串每个字符分别存储到vector容器中
			3.排序
			4.equal()比较
		*/
		// int sLength = s.length();
		// int tLength = t.length();
		// if (sLength != tLength)
		// {
		// 	return false;
		// }

		// vector<char> vecS(sLength);
		// vector<char> vecT(tLength);
		// for (int i = 0; i < sLength; i++)
		// {
		// 	vecS[i] = s[i];
		// 	vecT[i] = t[i];
		// }

		// sort(vecS.begin(), vecS.end());
		// sort(vecT.begin(), vecT.end());

		// return vecS == vecT; // return equal(vecS.begin(), vecS.end(), vecT.begin()); // equal()：判断排序后的两容器是否相等

		/*
			方法二（最优）：
			思路：
			通过ascII码来操作
			1.若两字符串长度不同，返回false
			2.因为题目要求为小写字母，其ASCII码范围是a-z(97-122)，所以可以创建两个大小为123的数组sArray，tArray(下标从0开始)
			3.然后遍历两个字符串，两个字符串的每个元素的ASCII码值为x=(int)srr,将对应的两数组下标为x的值累加
			4.最后比较两数组是否相等(只用比较97-122的元素值即可，之前全部为0)
		*/
		int sLength = s.length();
		int tLength = t.length();
		if (sLength != tLength)
		{
			return false;
		} 

		int sArray[123] = {};
		int tArray[123] = {};
		for (int i = 0; i < sLength; i++)	// 'z'的ascII码为122，'a'的ascII码为97
		{
			sArray[(int)s[i]]++;
			tArray[(int)t[i]]++;
		}

		for (int i = 97; i < 123; i++)
		{
			if (sArray[i] != tArray[i])
			{
				return false;
			}
		}
		return true;

        // 3：时间复杂度较高（不推荐） 类似于方法一：
        // int sLength = s.length();
		// int tLength = t.length();
        // if (sLength != tLength)
        // {
        //     return false;
        // }
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // for (int i = 0; i < sLength; i++)
        // {
        //     if (s[i] != t[i])
        //     {
        //         return false;
        //     }
        // }
        // return true;
    }
};
// @lc code=end

