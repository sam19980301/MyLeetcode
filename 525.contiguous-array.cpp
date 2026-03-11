/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> m; // #1 - #0, index
        m.emplace(0, -1);

        int diff = 0;
        int ans = 0;
        const int sz = static_cast<int>(nums.size());
        for (int i = 0; i < sz; i++)
        {
            const int num = nums.at(i);
            if (num)
            {
                diff++;
            }
            else
            {
                diff--;
            }

            auto [it, success] = m.emplace(diff, i);
            if (!success)
            {
                ans = max(ans, i - it->second);
            }
        }
        return ans;
    }
};
// @lc code=end
