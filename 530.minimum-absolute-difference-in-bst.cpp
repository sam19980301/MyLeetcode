/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    pair<int, int> getMinimumDifference_helper(TreeNode* node, int& ans)
    {
        // return the max- & min- value of the node tree
        pair<int, int> pr = { node->val, node->val };
        if (node->left)
        {
            pair<int, int> l_pr = getMinimumDifference_helper(node->left, ans);
            pr.first = l_pr.first;
            ans = min(ans, node->val - l_pr.second);

        }
        if (node->right)
        {
            pair<int, int> r_pr = getMinimumDifference_helper(node->right, ans);
            pr.second = r_pr.second;
            ans = min(ans, r_pr.first - node->val);
        }
        return pr;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        getMinimumDifference_helper(root, ans);
        return ans;
    }
};
// @lc code=end

