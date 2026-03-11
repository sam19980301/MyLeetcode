/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#ifdef LEETCODE_LOCAL_DEV
#include "113.path-sum-ii.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void pathSum_helper(TreeNode *node, int diff, vector<int> &curr_path_nums, vector<vector<int>> &ans)
    {
        curr_path_nums.push_back(node->val);
        diff -= node->val;
        if (!node->left && !node->right && diff == 0)
        {
            ans.push_back(curr_path_nums);
        }
        if (node->left)
        {
            pathSum_helper(node->left, diff, curr_path_nums, ans);
        }
        if (node->right)
        {
            pathSum_helper(node->right, diff, curr_path_nums, ans);
        }
        curr_path_nums.pop_back();
    }

  public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        vector<int> curr_path_nums;
        pathSum_helper(root, targetSum, curr_path_nums, ans);
        return ans;
    }
};
// @lc code=end
