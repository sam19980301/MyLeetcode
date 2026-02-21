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
#ifdef LEETCODE_LOCAL_DEV
#include "543.diameter-of-binary-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    int diameterOfBinaryTree_helper(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
        {
            return 0;
        }
        const int l_h = diameterOfBinaryTree_helper(root->left, diameter);
        const int r_h = diameterOfBinaryTree_helper(root->right, diameter);
        diameter = max(diameter, l_h + r_h);
        return 1 + max(l_h, r_h); // tree height (1-based)
    }

  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        /*
            diameter(node) = max(
                l_child height + r_child height, // diameter path passing node
                diameter(l_child),               // diameter path passing left child
                diameter(r_child)                // diameter path passing right child
            )
        */
        int diameter = 0;
        diameterOfBinaryTree_helper(root, diameter);
        return diameter;
    }
};
// @lc code=end
