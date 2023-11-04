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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> ans;
        bool left_first = true;
        stack<TreeNode*> s, sub_s;
        s.push(root);
        while (!s.empty())
        {
            ans.push_back({ });
            while (!s.empty())
            {
                TreeNode *node = s.top();
                s.pop();
                ans.back().push_back(node->val);
                if (left_first && node->left)
                    sub_s.push(node->left);
                if (node->right)
                    sub_s.push(node->right);
                if (!left_first && node->left)
                    sub_s.push(node->left);
            }
            left_first = !left_first;
            s.swap(sub_s);
        }
        return ans;
    }
};
// @lc code=end

