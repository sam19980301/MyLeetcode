/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s; // index of non-increasing value
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                while (!s.empty() && nums[s.top()] < nums[j])
                {
                    ans[s.top()] = nums[j];
                    s.pop();
                }
                if (i == 0)
                    s.push(j);
            }
        }
        return ans;
    }
};
// @lc code=end

