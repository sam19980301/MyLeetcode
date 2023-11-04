/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
            swap non-zero value with zero value in relative order
        */

        int i = 0;
        for (int j = 0; j < nums.size(); j++)
            if (nums[j])
                swap(nums[i++], nums[j]);
    }
};
// @lc code=end

