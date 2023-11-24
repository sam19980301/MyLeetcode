/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m; // value : cnt
        for (int num1 : nums1)
        {
            for (int num2 : nums2)
            {
                m[num1 + num2]++;
            }
        }
        
        int ans = 0;
        for (int num3 : nums3)
        {
            for (int num4 : nums4)
            {
                auto it = m.find(-num3-num4);
                if (it != m.end())
                    ans += it->second;
            }
        }
        return ans;
    }
};
// @lc code=end

