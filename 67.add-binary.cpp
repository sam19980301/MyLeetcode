/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n = 0;
        auto it_a = a.rbegin(), it_b = b.rbegin();
        while (it_a != a.rend() || it_b != b.rend())
        {
            if (it_a != a.rend())
                n += *it_a++ - '0';
            if (it_b != b.rend())
                n += *it_b++ - '0';
            ans.push_back(n % 2 + '0');
            n /= 2;
        }
        if (n)
            ans.push_back(n + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

