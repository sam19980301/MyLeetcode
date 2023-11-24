/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void subsetsWithDup_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(curr);
            return ;
        }

        int count = 1;
        index++;
        while (index < nums.size() && nums[index] == nums[index-1])
        {
            count++;
            index++;
        }
        
        for (int i = 0; i <= count; i++)
        {
            subsetsWithDup_helper(nums, ans, curr, index);
            curr.push_back(nums[index-1]);
        }

        for (int i = 0; i <= count; i++)
            curr.pop_back();
    }

    // void subsetsWithDup_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, vector<bool>& visited, int index)
    // {
    //     ans.push_back(curr);
    //     for (int i = index; i < nums.size(); i++)
    //     {
    //         if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1]))
    //             continue;
    //         curr.push_back(nums[i]);
    //         visited[i] = true;
    //         subsetsWithDup_helper(nums, ans, curr, visited, i + 1);
    //         visited[i] = false;
    //         curr.pop_back();
    //     }
    // }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        subsetsWithDup_helper(nums, ans, curr, 0);
        return ans;

        // sort(nums.begin(), nums.end());
        // vector<vector<int>> ans;
        // vector<int> curr;
        // vector<bool> visited(nums.size(), false);
        // subsetsWithDup_helper(nums, ans, curr, visited, 0);
        // return ans;
    }
};
// @lc code=end

