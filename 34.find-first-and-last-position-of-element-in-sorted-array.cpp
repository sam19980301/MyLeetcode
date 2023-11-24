/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
            lower/upper-bound interval : [0, nums size]
            binary search interval     : [0, nums size)
        */
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        int start = lo;

        lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
                lo = mid + 1;
            else
                hi = mid;
        }
        int end = lo;
        if (start == end)
            return { -1, -1 };
        return { start, end - 1 };

        // auto l_it = lower_bound(nums.begin(), nums.end(), target);
        // auto u_it = upper_bound(nums.begin(), nums.end(), target);
        // if (l_it == u_it)
        //     return { -1, -1 };
        // return { (int) (l_it - nums.begin()), (int) (u_it - nums.begin() - 1) };

        // if (nums.size() == 0)
        //     return { -1, -1 };
        // int lo = 0, hi = nums.size() - 1;
        // while (lo < hi)
        // {
        //     int mid = lo + (hi - lo) / 2;
        //     if (nums[mid] < target)
        //         lo = mid + 1;
        //     else
        //         hi = mid;
        // }
        // int start = lo;
        // if (nums[start] != target)
        //     return { -1, -1 };
        
        // lo = 0, hi = nums.size() - 1;
        // while (lo < hi)
        // {
        //     int mid = lo + (hi - lo) / 2;
        //     if (nums[mid] <= target)
        //         lo = mid + 1;
        //     else
        //         hi = mid;
        // }
        // int end = lo;
        // if (nums[end] == target)
        //     return { start, end };
        // return { start, end - 1};
    }
};
// @lc code=end

