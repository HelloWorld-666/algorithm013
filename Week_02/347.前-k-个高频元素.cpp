/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 优先级队列(大顶堆)
        unordered_map<int, int> cnt;            // 负责统计每个元素出现的次数 key:元素值 value：元素出现次数

        // for (auto num : nums) cnt[num]++;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]] += 1;
        }

        // for (auto kv : cnt) {
        //     pq.push({kv.second, kv.first});
        //     while (pq.size() > k) pq.pop();
        // }
        for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
        {
            pq.push({it->second, it->first});   // 根据map中的key(次数)来排序，value为次数对应的元素值
            if (pq.size() > k)                  // pq始终维护长度为k的队列(此处提前限定了pq长度为k，下面while不用for (int i = 0; i < k; i++) 了)
            {
                pq.pop();
            }
        }

        // vector<int> res;
        // while (!pq.empty())
        // {
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);     // 从队首依次从大到小获取每个元素的second域(元素值)，并存入v
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

