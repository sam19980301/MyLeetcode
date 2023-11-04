/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void pathSum_helper(TreeNode* node, vector<vector<int>>& ans, vector<int>& curr, int remained) {
        curr.push_back(node->val);
        remained -= node->val;

        if (node->left)
            pathSum_helper(node->left, ans, curr, remained);
        if (node->right)
            pathSum_helper(node->right, ans, curr, remained);
        
        if (!node->left && !node->right && remained == 0)
            ans.push_back(curr);

        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return { };
        
        vector<vector<int>> ans;
        vector<int> curr;
        pathSum_helper(root, ans, curr, targetSum);
        return ans;
    }
};
// @lc code=end

