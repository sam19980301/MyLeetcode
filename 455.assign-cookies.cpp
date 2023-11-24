/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        auto g_it = g.begin();
        for (int size : s)
        {
            if (g_it == g.end())
                break;

            if (*g_it <= size)
            {
                ans++;
                g_it++;
            }
        }
        return ans;
    }
};
// @lc code=end

