/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void subsets_helper(size_t index, vector<int> &nums, vector<int> &curr_subset, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(curr_subset);
            return;
        }

        subsets_helper(index + 1, nums, curr_subset, ans);
        curr_subset.push_back(nums.at(index));
        subsets_helper(index + 1, nums, curr_subset, ans);
        curr_subset.pop_back();
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr_subset;
        subsets_helper(0, nums, curr_subset, ans);
        return ans;
    }
};
// @lc code=end
