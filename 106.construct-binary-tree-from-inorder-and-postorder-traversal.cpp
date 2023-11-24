/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree_helper(vector<int>& inorder, vector<int>& postorder, int& post, int in_lo, int in_hi)
    {
        if (in_lo > in_hi)
            return nullptr;
        
        int index = in_hi, value = postorder[post--];
        while (inorder[index] != value)
            index--;
        
        TreeNode *node = new TreeNode(value);
        node->right = buildTree_helper(inorder, postorder, post, index + 1, in_hi);
        node->left = buildTree_helper(inorder, postorder, post, in_lo, index - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
            postorder : (left, ... ), (right, ... ), node
            inorder   : (left, ... ), node, (right, ... )
        */
        int post = inorder.size() - 1;
        return buildTree_helper(inorder, postorder, post, 0, inorder.size() - 1);
    }
};
// @lc code=end

