/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cnts(3, 0);
        for (int bill : bills)
        {
            if (bill == 5)
            {
                cnts[0]++;
            }
            else if (bill == 10)
            {
                if (cnts[0] > 0)
                {
                    cnts[0]--;
                    cnts[1]++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (cnts[1] > 0 && cnts[0] > 0)
                {
                    cnts[0]--;
                    cnts[1]--;
                    cnts[2]++;
                }
                else if (cnts[0] > 2)
                {
                    cnts[0] -= 3;
                    cnts[2]++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

