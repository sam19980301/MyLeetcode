/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, cumsum = 0;
        unordered_map<int, int> m;
        m[0]++;

        for (int num : nums)
        {
            cumsum += num;
            ans += m[cumsum - k];
            m[cumsum]++;
        }
        return ans;
    }
};
// @lc code=end

