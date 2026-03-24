/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m; // num : freq
        for (const int num : nums)
        {
            ++m[num];
        }

        priority_queue<pair<int, int>> q; // freq, num
        for (auto [num, freq] : m)
        {
            q.emplace(freq, num);
        }
        vector<int> ans;
        ans.reserve(k);
        while (k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end
