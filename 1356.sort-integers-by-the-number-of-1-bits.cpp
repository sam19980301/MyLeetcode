/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto bit_lt = [](int a, int b) -> bool {
            auto count_bit = [](int n) -> int {
                int cnt = 0;
                while (n)
                {
                    n &= (n - 1);
                    cnt++;
                }
                return cnt;
            };
            int ca = count_bit(a), cb = count_bit(b);
            return (ca == cb) ? (a < b) : (ca < cb);
        };
        sort(arr.begin(), arr.end(), bit_lt);
        return arr;
    }
};
// @lc code=end

