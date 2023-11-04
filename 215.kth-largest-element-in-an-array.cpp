/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> min_heap(k, INT_MIN);
        for (int num : nums)
        {
            if (min_heap.front() < num)
            {
                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.back() = num;
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());
            }
        }
        return min_heap.front();
    }
};
// @lc code=end

