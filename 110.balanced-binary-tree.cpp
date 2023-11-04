/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int isBalanced_helper(TreeNode* node) {
        // return the height of the node if balanced else -1
        if (!node)
            return 0;

        int l_height = isBalanced_helper(node->left);
        if (l_height < 0)
            return -1;

        int r_height = isBalanced_helper(node->right);
        if (r_height < 0)
            return -1;
        
        if (abs(l_height - r_height) > 1)
            return -1;
        return max(l_height, r_height) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        // balanced : height difference <= 1
        return isBalanced_helper(root) >= 0;
    }
};
// @lc code=end

