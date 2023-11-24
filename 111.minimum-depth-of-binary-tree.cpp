/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            ans++;
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (!node->left && !node->right)
                    return ans;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return -1;
    }
};
// @lc code=end

