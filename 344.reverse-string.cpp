/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        ranges::reverse(s);
        /*
        auto l_it = s.begin();
        auto r_it = s.end();
        while (l_it < r_it)
        {
            swap(*l_it++, *--r_it);
        }
        */
    }
};
// @lc code=end
