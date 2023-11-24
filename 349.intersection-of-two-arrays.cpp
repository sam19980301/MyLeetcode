/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (int num : nums1)
            s.insert(num);
        vector<int> ans;
        for (int num : nums2)
            if (s.erase(num))
                ans.push_back(num);
        return ans;
    }
};
// @lc code=end

