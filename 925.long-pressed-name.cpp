/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int index_n = 0, index_t = 0;
        while (index_n < name.size())
        {
            char ch = name[index_n++];
            int cnt = 1;
            while (index_n < name.size() && name[index_n] == name[index_n-1])
            {
                index_n++;
                cnt++;
            }

            for (int i = 0; i < cnt; i++)
                if (typed[index_t++] != ch)
                    return false;
            while (index_t < typed.size() && typed[index_t] == typed[index_t-1])
                index_t++;
        }

        if (index_t != typed.size())
            return false;
        return true;
    }
};
// @lc code=end

