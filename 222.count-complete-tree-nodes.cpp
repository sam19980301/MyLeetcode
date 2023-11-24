/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
public:
    int countNodes(TreeNode* root) {
        /*
                       1
                 2           3
              4     5     6     7
            8   9 A   B C   D E   F
        */
        
        int level = 0, ans = 0;
        TreeNode *node = root;
        while (node)
        {
            ans += 1 << level++;
            node = node->right;
        }

        int lo = 0, hi = 1 << level;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            TreeNode *node = root;
            for (int i = 0; i < level; i++)
            {
                if (mid & 1 << (level - i - 1))
                    node = node->right;
                else
                    node = node->left;
            }
            if (node)
                lo = mid + 1;
            else
                hi = mid;
        }
        ans += lo;
        return ans;
    }
};
// @lc code=end

