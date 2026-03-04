/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef LEETCODE_LOCAL_DEV
#include "236.lowest-common-ancestor-of-a-binary-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    /*
      private:
        using Result = tuple<bool, bool, TreeNode *>; // found p, found q, result if exists
        Result lowestCommonAncestor_helper(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            if (!root)
            {
                return make_tuple(false, false, nullptr);
            }

            auto [l_found_p, l_found_q, l_lca] = lowestCommonAncestor_helper(root->left, p, q);
            if (l_found_p && l_found_q)
            {
                return make_tuple(l_found_p, l_found_q, l_lca);
            }

            auto [r_found_p, r_found_q, r_lca] = lowestCommonAncestor_helper(root->right, p, q);
            if (r_found_p && r_found_q)
            {
                return make_tuple(r_found_p, r_found_q, r_lca);
            }

            const bool found_p = l_found_p || r_found_p || root->val == p->val;
            const bool found_q = l_found_q || r_found_q || root->val == q->val;
            TreeNode *lca = (found_p && found_q) ? root : nullptr; // NOLINT(misc-const-correctness)
            return make_tuple(found_p, found_q, lca);
        }
    */

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // TODO(sam): Review
        if (!root || root->val == p->val || root->val == q->val)
        {
            return root;
        }

        TreeNode *llca = lowestCommonAncestor(root->left, p, q);  // NOLINT(misc-const-correctness)
        TreeNode *rlca = lowestCommonAncestor(root->right, p, q); // NOLINT(misc-const-correctness)
        if (!llca)
        {
            return rlca;
        }
        if (!rlca)
        {
            return llca;
        }
        return root;
        /*
        return get<2>(lowestCommonAncestor_helper(root, p, q));
        */
    }
};
// @lc code=end
