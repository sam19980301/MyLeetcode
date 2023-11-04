/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSamtree(TreeNode* p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q || p->val != q->val)
            return false;
        return isSamtree(p->left, q->left) && isSamtree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) || isSamtree(root, subRoot);
                
    }
};
// @lc code=end

