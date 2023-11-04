/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // num : index
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = m.find(target - nums[i]);
            if (it != m.end())
                return { it->second, i };
            m[nums[i]] = i;
        }
        return { };
    }
};
// @lc code=end

