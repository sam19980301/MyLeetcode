/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        const int sz = static_cast<int>(nums.size());
        for (int i = 0; i < sz; i++)
        {
            int &num = nums.at(i);
            while (num >= 1 && num <= sz /* && num != i + 1 */ && num != nums.at(num - 1))
            {
                swap(num, nums.at(num - 1));
            }
        }

        for (int i = 0; i < sz; i++)
        {
            if (nums.at(i) != i + 1)
            {
                return i + 1;
            }
        }
        return sz + 1;
    }
};
// @lc code=end
