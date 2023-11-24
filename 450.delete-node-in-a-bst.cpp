/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }

        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        // root->val == key
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        TreeNode *max_lchild = root->left;
        while (max_lchild->right)
            max_lchild = max_lchild->right;
        root->val = max_lchild->val;
        root->left = deleteNode(root->left, max_lchild->val);
        return root;

        // TreeNode *sentinel = new TreeNode(INT_MIN, nullptr, root);
        // TreeNode *node = sentinel, *parent = nullptr;
        // while (node && node->val != key)
        // {
        //     parent = node;
        //     if (node->val < key)
        //         node = node->right;
        //     else
        //         node = node->left;
        // }
        // if (!node)
        //     return sentinel->right;
        
        // TreeNode *del_parent = parent;
        // bool l_dir = (del_parent->left && del_parent->left->val == key);
        // TreeNode *&del_parent_child = l_dir ? del_parent->left : del_parent->right;
        // if (!node->left)
        // {
        //     node = node->right;
        // }
        // else
        // {
        //     parent = node;
        //     node = node->left;
        //     if (node->right)
        //     {
        //         while (node->right)
        //         {
        //             parent = node;
        //             node = node->right;
        //         }
        //         parent->right = node->left;
        //         node->left = del_parent_child->left;
        //         node->right = del_parent_child->right;
        //     }
        //     else
        //     {
        //         node->right = parent->right;
        //     }
        // }
        // del_parent_child = node;
        // return sentinel->right;
    }
};
// @lc code=end

