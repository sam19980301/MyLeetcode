/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            e.g.
                1 2 3 4 <-- to D
                1 2 4 3
                1 3 2 4
                1 3 4 2
                1 4 2 3
                1 4 3 2 <-- from A
                2 1 3 4 <-- to A
                2 1 4 3
                2 3 1 4
                2 3 4 1
                2 4 1 3
                2 4 3 1 <-- from B
                3 1 2 4 <-- to B
                3 1 4 2
                3 2 1 4
                3 2 4 1
                3 4 1 2
                3 4 2 1 <-- from C
                4 1 2 3 <-- to C
                4 1 3 2
                4 2 1 3
                4 2 3 1
                4 3 1 2
                4 3 2 1 <-- from D
        */

        int l = nums.size() - 2;
        while (l >= 0 && nums[l] >= nums[l+1])
            l--;
        
        if (l >= 0)
        {
            int r = nums.size() - 1;
            while (nums[r] <= nums[l])
                r--;
            swap(nums[l], nums[r]);
        }
        reverse(nums.begin() + l + 1, nums.end());
    }
};
// @lc code=end

