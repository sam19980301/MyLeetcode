/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
#include "144.binary-tree-preorder-traversal.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void preorderTraversal_helper(TreeNode *node, vector<int> &ans)
    {
        if (!node)
        {
            return;
        }
        ans.push_back(node->val);
        preorderTraversal_helper(node->left, ans);
        preorderTraversal_helper(node->right, ans);
    }

  public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorderTraversal_helper(root, ans);
        return ans;
    }
};
// @lc code=end
