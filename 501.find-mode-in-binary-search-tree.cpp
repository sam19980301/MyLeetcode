/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    void findMode_helper(TreeNode *node, pair<int, int>& curr, pair<int, vector<int>>& ans)
    {
        if (!node)
            return ;
        
        findMode_helper(node->left, curr, ans);
        
        if (curr.second == node->val)
            curr.first++;
        else
            curr = { 1, node->val };
        
        if (curr.first >= ans.first)
        {
            if (curr.first > ans.first)
            {
                ans.first = curr.first;
                ans.second.clear();
            }
            ans.second.push_back(curr.second);
        }

        findMode_helper(node->right, curr, ans);
    }
public:
    vector<int> findMode(TreeNode* root) {
        pair<int, int> curr = { 0, INT_MIN }; // count : value
        pair<int, vector<int>> ans; // count : values
        findMode_helper(root, curr, ans);
        return ans.second;

        // pair<int, int> curr; // count : value
        // pair<int, vector<int>> ans;
        // findMode_helper(root, curr, ans);
        // return ans.second;
    }
};
// @lc code=end

