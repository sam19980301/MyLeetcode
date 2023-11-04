/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = gcd(nums.size(), k);
        for (int i = 0; i < n; i++)
        {
            int j = (i + k) % nums.size();
            while (i != j)
            {
                swap(nums[i], nums[j]);
                j = (j + k) % nums.size();
            }
        }

        // k %= nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

