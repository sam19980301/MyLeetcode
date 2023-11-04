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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long>> q; // node, index in heap order
        q.push({ root, 1 });
        while (!q.empty())
        {
            int qs = q.size();
            long min_index = LONG_MAX, max_index = LONG_MIN, level_offset = q.front().second * 2;
            for (int i = 0; i < qs; i++)
            {
                auto [node, index] = q.front();
                min_index = min(min_index, index);
                max_index = max(max_index, index);
                q.pop();
                if (node->left)
                    q.push({ node->left, index*2-level_offset});
                if (node->right)
                    q.push({ node->right, index*2+1-level_offset});
            }
            ans = max(ans, (int) (max_index-min_index+1));

        }
        return ans;
    }
};
// @lc code=end

