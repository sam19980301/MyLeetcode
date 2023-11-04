/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> ls; // non-ascending list
        for (int i = 0; i < nums.size(); i++)
        {
            if (i-k>=0 && !ls.empty() && ls.front() == nums[i-k])
                ls.pop_front();
            
            while (!ls.empty() && ls.back() < nums[i])
                ls.pop_back();
            ls.push_back(nums[i]);

            if (i>=k-1)
                ans.push_back(ls.front());
        }
        return ans;
    }
};
// @lc code=end

