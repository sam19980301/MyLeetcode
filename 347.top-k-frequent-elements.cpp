/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // value, count
        for (int num : nums)
            m[num]++;
        
        vector<pair<int, int>> arr;
        for (auto it = m.begin(); it != m.end(); it++)
            arr.push_back({ it->second, it->first });
        make_heap(arr.begin(), arr.end());

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr.front().second);
            pop_heap(arr.begin(), arr.end() - i);
        }
        return ans;
    }
};
// @lc code=end

