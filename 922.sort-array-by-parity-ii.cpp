/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int index = 1;
        for (int i = 0; i < nums.size(); i+=2)
        {
            while (nums[i] % 2) // odd at even location
            {
                swap(nums[i], nums[index]);
                index += 2;
            }
        }
        return nums;
    }
};
// @lc code=end

