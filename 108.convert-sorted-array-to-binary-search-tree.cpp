/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST_helper(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        
        int m = l + (r - l) / 2;
        return new TreeNode(
            nums[m],
            sortedArrayToBST_helper(nums, l, m-1),
            sortedArrayToBST_helper(nums, m+1, r)
        );
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

