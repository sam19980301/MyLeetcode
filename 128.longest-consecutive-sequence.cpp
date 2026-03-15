/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        const unordered_set<int> s(nums.begin(), nums.end());
        int lcs_len = 0;
        for (const int num : s)
        {
            if (s.contains(num - 1))
            {
                continue;
            }

            int curr_lcs_len = 1;
            while (s.contains(num + curr_lcs_len))
            {
                curr_lcs_len++;
            }
            lcs_len = max(lcs_len, curr_lcs_len);
        }
        return lcs_len;

        /*
        int ans = 0;
        unordered_map<int, int> m; // num : longest consecutive seq. length that starts/ends at num
        for (const int num : nums)
        {
            auto [curr_it, success] = m.emplace(num, 1);
            if (!success)
            {
                continue;
            }

            auto prev_it = m.find(num - 1);
            auto next_it = m.find(num + 1);
            const int prev_lcs_len = prev_it != m.end() ? prev_it->second : 0;
            const int curr_lcs_len = curr_it->second;
            const int next_lcs_len = next_it != m.end() ? next_it->second : 0;
            const int lcs_len = prev_lcs_len + curr_lcs_len + next_lcs_len;
            m[num - prev_lcs_len] = lcs_len;
            m[num + next_lcs_len] = lcs_len;
            ans = max(ans, lcs_len);
        }
        return ans;
        */

        /*
        int ans = 0;
        unordered_map<int, pair<int, int>> m; // num : longest consecutive seq. containing num
        for (const int num : nums)
        {
            auto [it, success] = m.emplace(num, make_pair(num, num));
            if (!success)
            {
                continue;
            }

            auto l_it = m.find(num - 1);
            if (l_it != m.end())
            {
                l_it = m.find(l_it->second.first);
            }
            else
            {
                l_it = it;
            }

            auto r_it = m.find(num + 1);
            if (r_it != m.end())
            {
                r_it = m.find(r_it->second.second);
            }
            else
            {
                r_it = it;
            }

            const int lo = l_it->second.first;
            const int hi = r_it->second.second;
            l_it->second.second = hi;
            r_it->second.first = lo;
            ans = max(ans, hi - lo + 1);
        }
        return ans;
        */
    }
};
// @lc code=end
