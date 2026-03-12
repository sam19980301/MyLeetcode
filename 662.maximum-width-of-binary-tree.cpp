/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
#include "662.maximum-width-of-binary-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int widthOfBinaryTree(TreeNode *root)
    {
        // TODO(sam): Review
        queue<pair<TreeNode *, int64_t>> q;
        q.emplace(root, 0);

        int64_t ans = 0;
        while (!q.empty())
        {
            size_t qs = q.size();
            const int64_t lo = q.front().second;
            const int64_t hi = q.back().second;
            ans = max(ans, hi - lo + 1);
            while (qs--)
            {
                auto [node, index] = q.front();
                q.pop();
                if (node->left)
                {
                    q.emplace(node->left, (index - lo) * 2);
                }
                if (node->right)
                {
                    q.emplace(node->right, ((index - lo) * 2) + 1);
                }
            }
        }
        return static_cast<int>(ans);
    }
};
// @lc code=end
