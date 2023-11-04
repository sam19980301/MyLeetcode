/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnts(128, 0);
        for (char ch : t)
            cnts[ch]++;
        
        int unmatched = t.size(), start = 0, end = 0;
        pair<int, int> pr = { INT_MAX, INT_MAX }; // length, start index
        while (end < s.size())
        {
            if (cnts[s[end++]]-- > 0)
                unmatched--;
            if (unmatched == 0)
            {
                while (cnts[s[start++]]++ < 0)
                    ;
                unmatched++;
                pr = min(pr, { end - start + 1, start - 1 });
            }
        }
        return pr.first == INT_MAX ? "" : s.substr(pr.second, pr.first);
    }
};
// @lc code=end

