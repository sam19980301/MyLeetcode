/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums)
            arr.push_back(to_string(num));

        auto my_greater = [](const string& a, const string& b) -> bool { return a + b > b + a; };
        // auto my_greater = [](const string& a, const string& b) -> bool {
        //     int i = 0, j = 0, n = lcm(a.size(), b.size());
        //     while (i < n)
        //     {
        //         char ch_a = a[i++%a.size()], ch_b = b[j++%b.size()];
        //         if (ch_a != ch_b)
        //             return ch_a > ch_b;
        //     }
        //     return false;
        // };
        sort(arr.begin(), arr.end(), my_greater);

        if (arr[0][0] == '0')
            return "0";
        
        string ans;
        for (string& str : arr)
            ans += str;
        return ans;
    }
};
// @lc code=end

