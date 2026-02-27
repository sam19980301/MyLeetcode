/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
#include "98.validate-binary-search-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    bool isValidBST_helper(TreeNode *node, int64_t lb, int64_t ub)
    {
        if (!node)
        {
            return true;
        }
        const int64_t val = node->val;
        if (val < lb || val > ub)
        {
            return false;
        }
        return isValidBST_helper(node->left, lb, val - 1) && isValidBST_helper(node->right, val + 1, ub);
    }

  public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST_helper(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
    }
};
// @lc code=end
