/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
#include "863.all-nodes-distance-k-in-binary-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    bool distanceK_find_target_path(TreeNode *node, TreeNode *target, stack<TreeNode *> &s)
    {
        if (!node)
        {
            return false;
        }

        s.push(node);
        if (node == target || distanceK_find_target_path(node->left, target, s) ||
            distanceK_find_target_path(node->right, target, s))
        {
            return true;
        }
        s.pop();
        return false;
    }

    void distanceK_add_distance_nodes(TreeNode *node, int k, vector<int> &ans)
    {
        if (!node || k < 0)
        {
            return;
        }

        if (!k)
        {
            ans.push_back(node->val);
            return;
        }

        k--;
        distanceK_add_distance_nodes(node->left, k, ans);
        distanceK_add_distance_nodes(node->right, k, ans);
    }

  public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        stack<TreeNode *> s;
        distanceK_find_target_path(root, target, s);

        vector<int> ans;
        const TreeNode *child = nullptr;
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            if (node->left == child)
            {
                node->left = nullptr;
            }
            if (node->right == child)
            {
                node->right = nullptr;
            }
            distanceK_add_distance_nodes(node, k--, ans);
            child = node;
        }
        return ans;
    }
};
// @lc code=end
