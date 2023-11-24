/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=star
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void permuteUnique_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, vector<bool>& visited)
    {
        if (curr.size() == nums.size())
        {
            ans.push_back(curr);
            return ;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1]))
                continue;
            curr.push_back(nums[i]);
            visited[i] = true;
            permuteUnique_helper(nums, ans, curr, visited);
            visited[i] = false;
            curr.pop_back();
        }
    }
    // void permuteUnique_helper(vector<int>& nums, vector<vector<int>>& ans, int index)
    // {
    //     if (index == nums.size())
    //     {
    //         ans.push_back(nums);
    //         return ;
    //     }

    //     unordered_set<int> s;
    //     for (int i = index; i < nums.size(); i++)
    //     {
    //         if (!s.insert(nums[i]).second)
    //             continue;
    //         swap(nums[i], nums[index]);
    //         permuteUnique_helper(nums, ans, index + 1);
    //         swap(nums[i], nums[index]);
    //     }
    // }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        permuteUnique_helper(nums, ans, curr, visited);
        return ans;
    }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> ans;
    //     permuteUnique_helper(nums, ans, 0);
    //     return ans;
    // }
};
// @lc code=end

