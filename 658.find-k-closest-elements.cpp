/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // TODO(sam): Review
        auto l_it = arr.begin(); // starting iterator for the ans
        auto r_it = arr.end() - k;
        while (l_it < r_it)
        {
            auto m_it = l_it + distance(l_it, r_it) / 2;
            if (x - *m_it > *(m_it + k) - x)
            {
                l_it = m_it + 1;
            }
            else
            {
                r_it = m_it;
            }
        }
        return {l_it, l_it + k};
    }
};
// @lc code=end
