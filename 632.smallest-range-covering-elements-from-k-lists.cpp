/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        // TODO(sam): Review
        using num_it = pair<vector<int>::iterator, vector<int>::iterator>;
        auto greater_num_it = [](const num_it &lhs, const num_it &rhs) { return *lhs.first > *rhs.first; };

        int ed = numeric_limits<int>::min();
        priority_queue<num_it, vector<num_it>, decltype(greater_num_it)> q;
        for (vector<int> &num : nums)
        {
            ed = max(ed, num.front());
            q.emplace(num.begin(), num.end());
        }
        int ans_st = *q.top().first;
        int ans_ed = ed;

        while (q.top().first + 1 != q.top().second)
        {
            auto [it, ed_it] = q.top();
            q.pop();
            q.emplace(++it, ed_it);
            const int st = *q.top().first;
            ed = max(ed, *it);
            if (make_pair(ed - st, st) < make_pair(ans_ed - ans_st, ans_st))
            {
                ans_st = st;
                ans_ed = ed;
            }
        }
        return {ans_st, ans_ed};
    }
};
// @lc code=end
