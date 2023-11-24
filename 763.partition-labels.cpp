/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> indexes(26, -1);
        for (int i = 0; i < s.size(); i++)
            indexes[s[i]-'a'] = i;
        vector<int> ans;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, indexes[s[i]-'a']);
            if (i == end)
                ans.push_back(end);
        }
        for (int i = ans.size() - 1; i > 0; i--)
            ans[i] -= ans[i-1];
        ans.front()++;
        return ans;
    }
};
// @lc code=end

