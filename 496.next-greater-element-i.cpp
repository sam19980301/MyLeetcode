/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        s.push(nums2[0]);
        for (int num : nums2)
        {
            while (!s.empty() && s.top() < num)
            {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        while (!s.empty())
        {
            m[s.top()] = -1;
            s.pop();
        }

        vector<int> ans;
        for (int num : nums1)
            ans.push_back(m[num]);
        return ans;
    }
};
// @lc code=end

