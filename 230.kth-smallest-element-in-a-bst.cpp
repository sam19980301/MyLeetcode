/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    void kthSmallest_helper(TreeNode *node, int& n, int& ans) {
        if (!node || n < 0)
            return ;

        kthSmallest_helper(node->left, n, ans);
        if (n < 0)
            return ;

        n--;
        if (n == 0)
        {
            ans = node->val;
            n--;
            return ;
        }

        kthSmallest_helper(node->right, n, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MIN, n = k;
        kthSmallest_helper(root, n, ans);
        return ans;
    }
};
// @lc code=end

