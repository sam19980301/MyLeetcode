/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        while (!s.empty() && isspace(s.back()))
            s.pop_back();
        reverse(s.begin(), s.end());
        while (!s.empty() && isspace(s.back()))
            s.pop_back();

        int index = 0;
        for (int i = 0; i < s.size(); i++)
            if (!isspace(s[i]) || !isspace(s[index-1]))
                s[index++] = s[i];
        s.resize(index);

        auto it_b = s.begin(), it_e = s.begin();
        while (it_e < s.end())
        {
            while (it_e < s.end() && !isspace(*it_e))
                it_e++;
            reverse(it_b, it_e++);
            it_b = it_e;
        }
        return s;
    }
};
// @lc code=end

