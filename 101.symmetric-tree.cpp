/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric_helper(TreeNode* left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right || left->val != right->val)
            return false;
        return isSymmetric_helper(left->left, right->right) && isSymmetric_helper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric_helper(root->left, root->right);
    }
};
// @lc code=end

