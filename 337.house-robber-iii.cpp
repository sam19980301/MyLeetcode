/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    pair<int, int> rob_helper(TreeNode* node)
    {
        if (!node)
            return { 0, 0 };
        
        // robbing allowed / not robbing
        auto [l_r, l_nr] = rob_helper(node->left);
        auto [r_r, r_nr] = rob_helper(node->right);
        return { max(node->val + l_nr + r_nr, l_r + r_r), l_r + r_r };
    }
public:
    int rob(TreeNode* root) {
        return rob_helper(root).first;
    }
};
// @lc code=end

