/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void combinationSum_helper(size_t cand_index, int target, vector<int> &curr_comb, vector<vector<int>> &ans,
                               vector<int> &candidiates)
    {
        if (target == 0)
        {
            ans.push_back(curr_comb);
            return;
        }

        if (target < 0)
        {
            return;
        }

        for (size_t i = cand_index; i < candidiates.size(); i++)
        {
            const int cand_val = candidiates.at(i);
            curr_comb.push_back(cand_val);
            // may add early exit condition for optimization
            combinationSum_helper(i, target - cand_val, curr_comb, ans, candidiates);
            curr_comb.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // Backtracking
        ranges::sort(candidates, less<>());
        vector<vector<int>> ans;
        vector<int> curr_comb;
        combinationSum_helper(0, target, curr_comb, ans, candidates);
        return ans;

        /*
        // DP
        ranges::sort(candidates, less<>());
        vector<vector<vector<int>>> dp(target + 1);
        dp.front().emplace_back();
        for (int curr_target = 1; curr_target <= target; curr_target++)
        {
            auto &curr_combs = dp.at(curr_target);
            for (const int candidate : candidates)
            {
                const int prev_target = curr_target - candidate;
                if (prev_target < 0)
                {
                    continue;
                }
                for (auto comb : dp.at(prev_target))
                {
                    if (!comb.empty() && candidate < comb.back())
                    {
                        continue;
                    }
                    comb.push_back(candidate);
                    curr_combs.push_back(comb);
                }
            }
        }
        return dp.back();
        */
    }
};
// @lc code=end
