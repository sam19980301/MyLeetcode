/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum_helper(TreeNode* node, int& ans) {
        if (!node)
            return 0;
        
        int l_val = maxPathSum_helper(node->left, ans);
        int r_val = maxPathSum_helper(node->right, ans);
        ans = max(ans, node->val + l_val + r_val);
        return max(0, node->val + max(l_val, r_val));
    }
public:
    int maxPathSum(TreeNode* root) {
        /*
            ans = max{ maxpathsum(i) for all nodes }

            maxpathsum(node) = node value + maxpathsum_sd(left) + maxpathsum_sd(right)

            // single-direction path
            maxpathsum_sd(node) = max(
                // excluding node
                0,
                // including node
                node value + max(maxpathsum_sd(left), maxpathsum_sd(right))
            )
        */

        int ans = INT_MIN;
        maxPathSum_helper(root, ans);
        return ans;
    }
};
// @lc code=end

