/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, maj = 0;
        for (int num : nums)
        {
            if (cnt == 0)
            {
                cnt++;
                maj = num;
            }
            else if (num == maj)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return maj;
    }
};
// @lc code=end

