/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr({ INT_MIN });
        for (int num : nums)
        {
            auto it = lower_bound(arr.begin(), arr.end(), num);
            if (it == arr.end())
                arr.push_back(num);
            else
                *it = num;
        }
        return arr.size() - 1;
    }
};
// @lc code=end

