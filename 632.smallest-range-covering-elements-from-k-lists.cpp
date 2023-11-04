/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        using pr = pair<vector<int>::iterator, vector<int>::iterator>;
        auto greater_it = [](pr a, pr b) -> bool {
            // if (a.first == a.second)
            //     return true;
            // if (b.first == b.second)
            //     return false;
            return *a.first > *b.first;
        };

        priority_queue<pr, vector<pr>, decltype(greater_it)> heap;
        int lo = INT_MAX, hi = INT_MIN;
        for (vector<int>& num : nums)
        {
            heap.push({ num.begin(), num.end() });
            lo = min(lo, num[0]);
            hi = max(hi, num[0]);
        }

        pair<int, int> ans = { hi - lo, lo };
        while (heap.top().first + 1 != heap.top().second)
        {
            auto [it, it_end] = heap.top();
            heap.pop();
            heap.push({ ++it, it_end });
            lo = *heap.top().first;
            hi = max(hi, *it);
            ans = min(ans, { hi - lo, lo });
        }
        return { ans.second, ans.first + ans.second };
    }
};
// @lc code=end

