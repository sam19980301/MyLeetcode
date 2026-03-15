/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include "103.binary-tree-zigzag-level-order-traversal.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        bool l_first = true;
        stack<TreeNode *> s_curr;
        s_curr.push(root);
        while (!s_curr.empty())
        {
            ans.emplace_back();
            stack<TreeNode *> s_next;
            while (!s_curr.empty())
            {
                const TreeNode *node = s_curr.top();
                s_curr.pop();
                ans.back().push_back(node->val);
                if (l_first && node->left)
                {
                    s_next.push(node->left);
                }
                if (node->right)
                {
                    s_next.push(node->right);
                }
                if (!l_first && node->left)
                {
                    s_next.push(node->left);
                }
            }
            s_curr.swap(s_next);
            l_first = !l_first;
        }
        return ans;
    }
};
// @lc code=end
