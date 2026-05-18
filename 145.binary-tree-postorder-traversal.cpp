/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
#include "145.binary-tree-postorder-traversal.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void postorderTraversal_helper(TreeNode *node, vector<int> &ans)
    {
        if (!node)
        {
            return;
        }
        postorderTraversal_helper(node->left, ans);
        postorderTraversal_helper(node->right, ans);
        ans.push_back(node->val);
    }

  public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorderTraversal_helper(root, ans);
        return ans;
    }
};
// @lc code=end
