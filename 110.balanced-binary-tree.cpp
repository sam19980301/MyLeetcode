/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include "110.balanced-binary-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    int isBalanced_helper(TreeNode *root)
    {
        /*
            return value = tree height (1-based), if tree is balanced
                           -1,                    otherwise
        */
        if (!root)
        {
            return 0;
        }

        const int l_h = isBalanced_helper(root->left);
        if (l_h < 0)
        {
            return -1;
        }

        const int r_h = isBalanced_helper(root->right);
        if (r_h < 0)
        {
            return -1;
        }

        if (abs(l_h - r_h) > 1)
        {
            return -1;
        }
        return 1 + max(l_h, r_h);
    }
    /*
    int isBalanced_helper(TreeNode *root, bool &is_balanced)
    {
        // node height (0-based)
        if (!root)
        {
            return -1;
        }
        const int l_h = isBalanced_helper(root->left, is_balanced);
        const int r_h = isBalanced_helper(root->right, is_balanced);
        if (abs(l_h - r_h) > 1)
        {
            is_balanced = false;
        }
        return 1 + max(l_h, r_h);
    }
    */

  public:
    bool isBalanced(TreeNode *root)
    {
        return isBalanced_helper(root) >= 0;
        /*
        bool is_balanced = true;
        isBalanced_helper(root, is_balanced);
        return is_balanced;
        */
    }
};
// @lc code=end
