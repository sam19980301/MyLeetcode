/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        auto l_it = numbers.begin();
        auto r_it = numbers.end() - 1;
        while (l_it < r_it)
        {
            const int sum = *l_it + *r_it;
            if (sum < target)
            {
                l_it++;
            }
            else if (sum > target)
            {
                r_it--;
            }
            else // sum == target
            {
                return {static_cast<int>(distance(numbers.begin(), l_it)) + 1,
                        static_cast<int>(distance(numbers.begin(), r_it)) + 1};
            }
        }
        return {};
    }
};
// @lc code=end
