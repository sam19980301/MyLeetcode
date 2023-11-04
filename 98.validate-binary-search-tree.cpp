/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST_helper(TreeNode* node, int lo, int hi) {
        /* node should be within range [lo, hi] */
        if (lo > node->val || node->val > hi)
            return false;
        if (node->left && (node->val == INT_MIN || !isValidBST_helper(node->left, lo, node->val - 1)))
            return false;
        if (node->right && (node->val == INT_MAX || !isValidBST_helper(node->right, node->val + 1, hi)))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root, INT_MIN, INT_MAX);
    }
};
// @lc code=end

