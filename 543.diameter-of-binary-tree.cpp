/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree_helper(TreeNode* node, int& ans)
    {
        // return the depth of node
        if (!node)
            return 0;
        
        int l_depth = diameterOfBinaryTree_helper(node->left, ans);
        int r_depth = diameterOfBinaryTree_helper(node->right, ans);
        ans = max(ans, l_depth + r_depth);
        return 1 + max(l_depth, r_depth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        /*
            diameter(node) = max(
                l_child depth + r_child depth,  // pass the node
                max(diameter(l_child, r_child)) // not pass the node
            )
        */

        int ans = 0;
        diameterOfBinaryTree_helper(root, ans);
        return ans;
    }
};
// @lc code=end

