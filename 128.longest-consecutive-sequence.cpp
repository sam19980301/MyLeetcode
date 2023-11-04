/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m; // value : consecutive count
        for (int num : nums)
        {
            if (m.find(num) != m.end())
                continue;
            auto it_l = m.find(num-1), it_r = m.find(num+1);
            int l_cnt = (it_l == m.end()) ? 0 : it_l->second;
            int r_cnt = (it_r == m.end()) ? 0 : it_r->second;
            int cnt = l_cnt + 1 + r_cnt;
            m[num-l_cnt] = cnt;
            m[num] = cnt;
            m[num+r_cnt] = cnt;
            ans = max(ans, cnt);
        }
        return ans;

        // int ans = 0;
        // unordered_set<int> s;
        // for (int num : nums)
        //     s.insert(num);
        // for (int num : nums)
        // {
        //     if (s.find(num-1) != s.end())
        //         continue;
        //     int cnt = 0;
        //     while (s.find(num++) != s.end())
        //         ans = max(ans, ++cnt);
        // }
        // return ans;
    }
};
// @lc code=end

