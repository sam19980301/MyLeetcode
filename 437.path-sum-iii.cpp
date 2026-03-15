/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
#include "437.path-sum-iii.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void pathSum_helper(TreeNode *node, int64_t cumsum, int64_t target, unordered_map<int64_t, int> &m, int &ans)
    {
        if (!node)
        {
            return;
        }

        cumsum += node->val;
        ans += m[cumsum - target];
        m[cumsum]++;
        pathSum_helper(node->left, cumsum, target, m, ans);
        pathSum_helper(node->right, cumsum, target, m, ans);
        m[cumsum]--;
    }

  public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<int64_t, int> m{{0, 1}};
        int ans = 0;
        pathSum_helper(root, 0, targetSum, m, ans);
        return ans;
    }
};
// @lc code=end
