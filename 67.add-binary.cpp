/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string addBinary(string a, string b)
    {
        string ans;
        auto a_it = a.rbegin();
        auto b_it = b.rbegin();
        unsigned int n = 0;
        while (a_it != a.rend() || b_it != b.rend() || n != 0)
        {
            if (a_it != a.rend())
            {
                n += *a_it++ - '0';
            }
            if (b_it != b.rend())
            {
                n += *b_it++ - '0';
            }
            ans.push_back(static_cast<char>('0' + (n & 1U)));
            n >>= 1U;
        }
        ranges::reverse(ans);
        return ans;
    }
};
// @lc code=end
