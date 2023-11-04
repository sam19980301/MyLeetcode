/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree_helper(vector<int>& preorder, vector<int>& inorder, int& pre, int in_lo, int in_hi) {
        if (in_lo > in_hi)
            return nullptr;
        
        int index = in_lo, value = preorder[pre++];
        while (inorder[index] != value)
            index++;
        
        TreeNode *node = new TreeNode(value);
        node->left = buildTree_helper(preorder, inorder, pre, in_lo, index - 1);
        node->right = buildTree_helper(preorder, inorder, pre, index + 1, in_hi);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
            preorder :  node, (left, ... ), (right, ... )
            inorder  :  (left, ... ), node, (right, ... )
        */
        int pre = 0;
        return buildTree_helper(preorder, inorder, pre, 0, inorder.size() - 1);
    }
};
// @lc code=end

