/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
#include "105.construct-binary-tree-from-preorder-and-inorder-traversal.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    using ivec_it = vector<int>::iterator;
    TreeNode *buildTree_helper(ivec_it &preorder_it, ivec_it inorder_st_it, ivec_it inorder_ed_it)
    {
        if (inorder_st_it == inorder_ed_it)
        {
            return nullptr;
        }

        const int node_val = *preorder_it++;
        auto inorder_mid_it = inorder_st_it;
        while (*inorder_mid_it != node_val)
        {
            inorder_mid_it++;
        }
        // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
        auto *node = new TreeNode(node_val, buildTree_helper(preorder_it, inorder_st_it, inorder_mid_it),
                                  buildTree_helper(preorder_it, inorder_mid_it + 1, inorder_ed_it));
        return node;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        /*
            preorder: node, (left nodes, ...), (right nodes, ...)
            inorder:  (left nodes, ...), node, (right nodes, ...)
        */
        auto preorder_it = preorder.begin();
        return buildTree_helper(preorder_it, inorder.begin(), inorder.end());
    }
};
// @lc code=end
