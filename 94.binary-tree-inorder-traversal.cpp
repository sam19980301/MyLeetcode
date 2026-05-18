/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
#include "94.binary-tree-inorder-traversal.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void inorderTraversal_helper(TreeNode *node, vector<int> &ans)
    {
        if (!node)
        {
            return;
        }

        inorderTraversal_helper(node->left, ans);
        ans.push_back(node->val);
        inorderTraversal_helper(node->right, ans);
    }

  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorderTraversal_helper(root, ans);
        return ans;
    }
};
// @lc code=end
