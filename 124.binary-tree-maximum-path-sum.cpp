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
#ifdef LEETCODE_LOCAL_DEV
#include "124.binary-tree-maximum-path-sum.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    int maxPathSum_helper(TreeNode *node, int &ans)
    {
        if (!node)
        {
            return 0;
        }

        const int lps = maxPathSum_helper(node->left, ans);
        const int rps = maxPathSum_helper(node->right, ans);
        ans = max(ans, node->val + lps + rps);
        return max(node->val + max(lps, rps), 0);
    }

  public:
    int maxPathSum(TreeNode *root)
    {
        /*
            ans = max{ max_path_sum(node) of all nodes }

            max_path_sum(node) = \
                node value + \
                max_path_sum_single_dir( left child) + \
                max_path_sum_single_dir(right child)

            // single direction path sum, empty path allowed
            max_path_sum_single_dir = max(
                0,
                node value + max(
                    max_path_sum_single_dir( left child),
                    max_path_sum_single_dir(right child)
                )
            )
        */
        int ans = numeric_limits<int>::min();
        maxPathSum_helper(root, ans);
        return ans;
    }
};
// @lc code=end
