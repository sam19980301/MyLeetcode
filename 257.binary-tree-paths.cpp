/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
private:
    void binaryTreePaths_helper(TreeNode* node, vector<string>& ans, string& curr)
    {
        string s_val = to_string(node->val);
        curr += s_val;

        if (!node->left && !node->right)
        {
            ans.push_back(curr);
        }
        else
        {
            curr.push_back('-');
            curr.push_back('>');
            if (node->left)
                binaryTreePaths_helper(node->left, ans, curr);
            if (node->right)
                binaryTreePaths_helper(node->right, ans, curr);
            curr.pop_back();
            curr.pop_back();
        }

        for (int i = 0; i < s_val.size(); i++)
            curr.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr;
        binaryTreePaths_helper(root, ans, curr);
        return ans;
    }
};
// @lc code=end

