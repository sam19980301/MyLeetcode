/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end
