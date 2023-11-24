/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m; // right interval val : seq length
        for (int num : nums)
        {
            if (m[num-1].size() == 0)
            {
                m[num].push(1);
            }
            else
            {
                int len = m[num-1].top();
                m[num-1].pop();
                m[num].push(len + 1);
            }
        }

        for (auto& [value, lengths] : m)
        {
            while (!lengths.empty())
            {
                if (lengths.top() < 3)
                    return false;
                lengths.pop();
            }
        }
        return true;
    }
};
// @lc code=end

