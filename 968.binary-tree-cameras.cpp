/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
    enum { COVERED, UNCOVERED, MONITOR };
    int minCameraCover_helper(TreeNode *node, int& ans)
    {
        /*
            children state : parent state
            any U -> M
            no U all C -> U
            no U any M -> C
        */
        if (!node)
            return COVERED;
        int lstate = minCameraCover_helper(node->left, ans);
        int rstate = minCameraCover_helper(node->right, ans);
        if (lstate == UNCOVERED || rstate == UNCOVERED)
        {
            ans++;
            return MONITOR;
        }
        if (lstate == MONITOR || rstate == MONITOR)
            return COVERED;
        return UNCOVERED;
    }
public:
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if (minCameraCover_helper(root, ans) == UNCOVERED)
            ans++;
        return ans;
    }
};
// @lc code=end

