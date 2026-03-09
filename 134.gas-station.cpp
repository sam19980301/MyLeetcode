/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        const size_t sz = gas.size();
        int cumsum = 0;
        int curr_cumsum = 0;
        size_t st = 0;
        for (size_t i = 0; i < sz; i++)
        {
            const int delta = gas.at(i) - cost.at(i);
            cumsum += delta;
            curr_cumsum += delta;

            if (curr_cumsum < 0)
            {
                curr_cumsum = 0;
                st = i + 1;
            }
        }
        return (cumsum >= 0) ? static_cast<int>(st) : -1;

        /*
        const size_t sz = gas.size();
        size_t st = 0;
        size_t len = 0;
        int cumsum = 0;
        while (st < sz && len != sz)
        {
            // cumsum [st, st + len)
            const size_t index = (st + len) % sz;
            cumsum += gas.at(index) - cost.at(index);
            len++;

            if (cumsum < 0)
            {
                st += len;
                cumsum = 0;
                len = 0;
            }
        }
        return (len == sz) ? static_cast<int>(st) : -1;
        */
    }
};
// @lc code=end
