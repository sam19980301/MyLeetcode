/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
            ------------------------
                ^           ^
                l           h
            
            1. x l h
            2. l x   h
            3. l   x h
            4. l h x            
        */
        int l = 0, h = arr.size() - k;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (x - arr[m] > arr[m+k] - x)
                l = m + 1;
            else
                h = m;
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);

        // auto it_r = lower_bound(arr.begin(), arr.end(), x);
        // auto it_l = it_r - 1;
        // for (int i = 0; i < k; i++)
        // {
        //     if (it_r == arr.end() || (it_l >= arr.begin() && abs(*it_l - x) <= abs(*it_r - x)))
        //         it_l--;
        //     else
        //         it_r++;
        // }
        // return vector<int>(it_l + 1, it_r);
    }
};
// @lc code=end

