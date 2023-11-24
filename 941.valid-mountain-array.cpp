/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[1] <= arr[0] || arr[arr.size()-1] >= arr[arr.size()-2])
            return false;
        bool inc = true;
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i-1])
                return false;

            if (arr[i] > arr[i-1])
            {
                if (!inc)
                    return false;
            }
            else
            {
                if (inc)
                    inc = false;
            }
        }
        return true;
    }
};
// @lc code=end

