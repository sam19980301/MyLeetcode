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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return { };
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (i == qs - 1) // last
                    ans.push_back(node->val);
            }
        }
        return ans;
    }
};
// @lc code=end

