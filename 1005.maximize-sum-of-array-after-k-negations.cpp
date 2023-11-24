/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ans = 0;
        for (int num : nums)
            ans += num;
        
        make_heap(nums.begin(), nums.end(), greater<int>());
        while (nums.front() < 0 && k > 0)
        {
            pop_heap(nums.begin(), nums.end(), greater<int>());
            nums.back() = -nums.back();
            ans += 2 * nums.back();
            push_heap(nums.begin(), nums.end(), greater<int>());
            k--;
        }
        if (k % 2) // nums.front() >= 0
            ans -= 2 * nums.front();
        return ans;
    }
};
// @lc code=end

