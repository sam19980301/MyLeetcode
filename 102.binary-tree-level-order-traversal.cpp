/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
#include "102.binary-tree-level-order-traversal.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            vector<int> level;
            size_t qs = q.size();
            while (qs--)
            {
                const TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
// @lc code=end
