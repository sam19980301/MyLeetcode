/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> curr(26, 100);
        for (string& word : words)
        {
            vector<int> prev(26, 0);
            curr.swap(prev);
            for (char ch : word)
                if (prev[ch-'a']-- > 0)
                    curr[ch-'a']++;
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < curr[i]; j++)
            {
                string s;
                s.push_back('a' + i);
                ans.push_back(s);
            }
        }
        return ans;
    }
};
// @lc code=end

