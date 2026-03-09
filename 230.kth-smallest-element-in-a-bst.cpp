/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
#include "230.kth-smallest-element-in-a-bst.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void kthSmallest_helper(TreeNode *node, int &k, int &ans)
    {
        if (!node || k <= 0)
        {
            return;
        }

        kthSmallest_helper(node->left, k, ans);
        if (k < 0)
        {
            return;
        }

        if (!--k)
        {
            ans = node->val;
            return;
        }
        kthSmallest_helper(node->right, k, ans);
    }

  public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1;
        kthSmallest_helper(root, k, ans);
        return ans;
    }
};
// @lc code=end
