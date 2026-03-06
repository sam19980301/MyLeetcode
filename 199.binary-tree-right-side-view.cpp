/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
#include "199.binary-tree-right-side-view.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    /*
      private:
        void rightSideView_helper(TreeNode *node, size_t depth, vector<int> &ans)
        {
            if (!node)
            {
                return;
            }

            // 0-based depth
            if (depth == ans.size())
            {
                ans.push_back(node->val);
            }

            rightSideView_helper(node->right, depth + 1, ans);
            rightSideView_helper(node->left, depth + 1, ans);
        }
    */
  public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            size_t qs = q.size();
            while (qs--)
            {
                const TreeNode *node = q.front();
                q.pop();
                if (node->right)
                {
                    q.push(node->right);
                }
                if (node->left)
                {
                    q.push(node->left);
                }
            }
        }
        return ans;
        /*
        vector<int> ans;
        rightSideView_helper(root, 0, ans);
        return ans;
        */
    }
};
// @lc code=end
