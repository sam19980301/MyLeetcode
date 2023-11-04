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
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool findpath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root)
            return false;

        path.push_back(root);
        if (root == target || findpath(root->left, target, path) || findpath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
    void add_nodes(TreeNode*node, int dist, vector<int>& ans) {
        if (!node || dist < 0)
            return ;
        
        if (dist == 0)
        {
            ans.push_back(node->val);
            return ;
        }

        dist--;
        add_nodes(node->left, dist, ans);
        add_nodes(node->right, dist, ans);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // find path
        vector<TreeNode*> path;
        findpath(root, target, path);

        // divivde the tree
        for (int i = path.size() - 2; i >=0; i--)
        {
            if (path[i]->left == path[i+1])
                path[i]->left = nullptr;
            else
                path[i]->right = nullptr;
        }
        
        // add nodes
        vector<int> ans;
        while (k >= 0 && !path.empty())
        {
            add_nodes(path.back(), k, ans);
            k--;
            path.pop_back();
        }
        return ans;
    }
};
// @lc code=end

