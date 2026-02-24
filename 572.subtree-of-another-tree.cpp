/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
#include "572.subtree-of-another-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    bool isSametree(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        if (!a || !b || a->val != b->val)
        {
            return false;
        }
        return isSametree(a->left, b->left) && isSametree(a->right, b->right);
    }

  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
        {
            return false;
        }
        return isSametree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
// @lc code=end
