/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // int lowestCommonAncestor_helper(TreeNode *node, TreeNode *p, TreeNode *q, TreeNode *&ans) {
    //     if (!node)
    //         return 0; // found none
        
    //     int cnt = lowestCommonAncestor_helper(node->left, p, q, ans);
    //     if (cnt > 2)
    //         return cnt; // found both and updated before

    //     cnt += lowestCommonAncestor_helper(node->right, p, q, ans);
    //     if (cnt > 2)
    //         return cnt; // found both and updated before
        
    //     if (node == p || node == q)
    //         cnt++;

    //     if (cnt == 2) // found both but not updated
    //     {
    //         cnt++;
    //         ans = node;
    //     }
    //     return cnt;
    // }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        
        TreeNode *llca = lowestCommonAncestor(root->left, p, q);
        TreeNode *rlca = lowestCommonAncestor(root->right, p, q);
        if (!llca)
            return rlca;
        if (!rlca)
            return llca;
        return root;
    }
};
// @lc code=end

