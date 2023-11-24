/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int num : arr)
            m[num]++;
        unordered_set<int> s;
        for (auto [num, count] : m)
            if (!s.insert(count).second)
                return false;
        return true;
    }
};
// @lc code=end

