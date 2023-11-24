/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree_helper(vector<int>& nums, int lo, int hi)
    {
        if (lo > hi)
            return nullptr;

        pair<int, int> pr = { INT_MIN, -1 };
        for (int i = lo; i <= hi; i++)
            pr = max(pr, { nums[i], i });
        
        TreeNode *node = new TreeNode(pr.first);
        node->left = constructMaximumBinaryTree_helper(nums, lo, pr.second - 1);
        node->right = constructMaximumBinaryTree_helper(nums, pr.second + 1, hi);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree_helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

