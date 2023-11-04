/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, bal = 0; // balanced value
        unordered_map<int, int> m; // #0 - #1 : index
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                bal--;
            else
                bal++;

            m.insert({ bal, i });
            ans = max(ans, i - m[bal]);
        }
        return ans;
    }
};
// @lc code=end

