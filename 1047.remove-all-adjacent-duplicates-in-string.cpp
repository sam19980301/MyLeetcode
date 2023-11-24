/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (char ch : s)
        {
            ans.push_back(ch);
            while (ans.size() > 1 && ans[ans.size()-1] == ans[ans.size()-2])
            {
                ans.pop_back();
                ans.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end

