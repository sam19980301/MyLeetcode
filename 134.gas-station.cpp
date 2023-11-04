/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, step = 0, remained = 0;
        while (start < gas.size() && step < gas.size())
        {
            int index = (start + step) % gas.size();
            remained += (gas[index] - cost[index]);
            if (remained < 0)
            {
                start += step + 1;
                step = 0;
                remained = 0;
            }
            else
            {
                step++;
            }
        }
        return step == gas.size() ? start : -1;
    }
};
// @lc code=end

