/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i = 0;
        while (true)
        {
            int unique_ch = -1;
            for (string& str : strs)
            {
                if (i == str.size())
                    return ans;
                if (unique_ch < 0) // first
                    unique_ch = str[i];
                else if (str[i] != unique_ch)
                    return ans;
            }
            i++;
            ans.push_back(unique_ch);
        }
    }
};
// @lc code=end

