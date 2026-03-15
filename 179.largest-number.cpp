/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> nums_str(nums.size());
        ranges::transform(nums, nums_str.begin(), [](const int num) { return to_string(num); });
        ranges::sort(nums_str, [](const string &lhs, const string &rhs) { return lhs + rhs > rhs + lhs; });
        /*
        auto num_str_greater = [](const string lhs, const string rhs) {
            auto l_it = lhs.begin();
            auto r_it = rhs.begin();
            while (l_it != lhs.end() || r_it != rhs.end())
            {
                if (l_it == lhs.end())
                {
                    l_it = lhs.begin();
                }
                if (r_it == rhs.end())
                {
                    r_it = rhs.begin();
                }

                if (*l_it != *r_it)
                {
                    return *l_it > *r_it;
                }
                l_it++;
                r_it++;
            }
            return false;
        };
        ranges::sort(nums_str, num_str_greater);
        */
        if (nums_str.front().front() == '0')
        {
            return "0";
        }

        string ans;
        for (const string &num_str : nums_str)
        {
            ans += num_str;
        }
        return ans;
    }
};
// @lc code=end
