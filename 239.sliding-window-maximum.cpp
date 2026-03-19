/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // TODO(sam): Review
        deque<vector<int>::iterator> q;
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            while (!q.empty() && *q.back() <= *it)
            {
                q.pop_back();
            }
            q.push_back(it);

            if (q.front() == it - k)
            {
                q.pop_front();
            }

            if (it >= nums.begin() + k - 1)
            {
                ans.push_back(*q.front());
            }
        }
        return ans;
    }
};
// @lc code=end
