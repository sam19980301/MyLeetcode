/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
#include "100.same-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        const bool p_valid = (p != nullptr);
        const bool q_valid = (q != nullptr);
        if (!p_valid && !q_valid)
        {
            return true;
        }
        if (p_valid != q_valid || p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
