/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    void balanceBST_helper1(TreeNode *node, vector<TreeNode*>& arr)
    {
        // inorder traversal
        if (!node)
            return ;
        balanceBST_helper1(node->left, arr);
        arr.push_back(node);
        balanceBST_helper1(node->right, arr);
    }
    TreeNode* balanceBST_helper2(vector<TreeNode*>& arr, int lo, int hi)
    {
        // build from soreted values
        if (lo > hi)
            return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode *node = arr[mid];
        node->left = balanceBST_helper2(arr, lo, mid - 1);
        node->right = balanceBST_helper2(arr, mid + 1, hi);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        balanceBST_helper1(root, arr);
        return balanceBST_helper2(arr, 0, arr.size() - 1);
    }
};
// @lc code=end

