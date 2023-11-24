/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    void convertBST_helper(TreeNode* node, int& sum)
    {
        if (!node)
            return ;
        
        convertBST_helper(node->right, sum);
        sum += node->val;
        node->val = sum;
        convertBST_helper(node->left, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBST_helper(root, sum);
        return root;
    }
};
// @lc code=end

