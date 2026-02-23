/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
#include "108.convert-sorted-array-to-binary-search-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    TreeNode *sortedArrayBST_helper(vector<int>::iterator lo, vector<int>::iterator hi)
    {
        if (lo > hi)
        {
            return nullptr;
        }
        auto mid = lo + (hi - lo) / 2;
        // NOLINTBEGIN(cppcoreguidelines-owning-memory)
        auto *node = new TreeNode(*mid, sortedArrayBST_helper(lo, mid - 1), sortedArrayBST_helper(mid + 1, hi));
        // NOLINTEND(cppcoreguidelines-owning-memory)
        return node;
    }

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayBST_helper(nums.begin(), nums.end() - 1);
    }
};
// @lc code=end
