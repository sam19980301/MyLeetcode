/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    constexpr static int64_t divisior = 10;

  public:
    bool isPalindrome(int x)
    {
        // TODO(sam): Review
        if (x < 0)
        {
            return false;
        }
        int64_t n = x;
        int64_t rn = 0;
        while (n)
        {
            auto [q, r] = div(n, divisior);
            rn = (rn * divisior) + r;
            n = q;
        }
        return cmp_equal(x, rn);

        /*
        if (x < 0)
        {
            return false;
        }
        vector<int> vec;
        while (x)
        {
            auto [q, r] = div(x, divisior);
            vec.push_back(static_cast<char>(r));
            x = q;
        }

        size_t lo = 0;
        size_t hi = vec.size();
        while (lo < hi)
        {
            if (vec.at(lo++) != vec.at(--hi))
            {
                return false;
            }
        }
        return true;
        */
    }
};
// @lc code=end
