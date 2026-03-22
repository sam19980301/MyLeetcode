/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    // NOLINTNEXTLINE(clang-diagnostic-unused-parameter, misc-unused-parameters)
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        auto it_1 = nums1.rbegin() + static_cast<int>(nums1.size()) - m;
        auto it_2 = nums2.rbegin();
        for (int &num : ranges::reverse_view(nums1))
        {
            if (it_1 != nums1.rend() && (it_2 == nums2.rend() || *it_1 > *it_2))
            {
                num = *it_1++;
            }
            else
            {
                num = *it_2++;
            }
        }
    }
};
// @lc code=end
