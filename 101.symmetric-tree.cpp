/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
#include "101.symmetric-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    bool isSymmetric_helper(TreeNode *l_node, TreeNode *r_node)
    {
        if (!l_node && !r_node)
        {
            return true;
        }
        if (!l_node || !r_node || l_node->val != r_node->val)
        {
            return false;
        }
        return isSymmetric_helper(l_node->left, r_node->right) && isSymmetric_helper(l_node->right, r_node->left);
    }

  public:
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetric_helper(root->left, root->right);
    }
};
// @lc code=end
