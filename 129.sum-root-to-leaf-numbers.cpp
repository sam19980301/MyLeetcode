/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers_helper(TreeNode* node, int curr)
    {
        curr = curr * 10 + node->val;
        if (!node->left && !node->right)
            return curr;
        
        int sum = 0;
        if (node->left)
            sum += sumNumbers_helper(node->left, curr);
        if (node->right)
            sum += sumNumbers_helper(node->right, curr);
        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers_helper(root, 0);
    }
};
// @lc code=end

