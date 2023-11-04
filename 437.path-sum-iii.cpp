/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum_helper(TreeNode *node, unordered_map<long, int>& m, long cumsum, int target) {
        if (!node)
            return 0;
        
        cumsum += node->val;
        int count = m[cumsum - target];
        m[cumsum]++;
        count += pathSum_helper(node->left, m, cumsum, target);
        count += pathSum_helper(node->right, m, cumsum, target);
        m[cumsum]--;
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> m;
        m[0]++;
        return pathSum_helper(root, m, 0, targetSum);
    }
};
// @lc code=end

