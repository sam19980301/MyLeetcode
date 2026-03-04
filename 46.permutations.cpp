/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void permute_helper(vector<int>::iterator st_it, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (st_it == nums.end())
        {
            ans.push_back(nums);
            return;
        }

        for (auto it = st_it; it != nums.end(); it++)
        {
            swap(*st_it, *it);
            permute_helper(st_it + 1, ans, nums);
            swap(*st_it, *it);
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permute_helper(nums.begin(), ans, nums);
        return ans;

        /*
        ranges::sort(nums, less<>{});
        vector<vector<int>> ans;
        ans.push_back(nums);
        while (ranges::next_permutation(nums, less<>{}).found)
        {
            ans.push_back(nums);
        }
        return ans;
        */
    }
};
// @lc code=end
