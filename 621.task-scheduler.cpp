/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnts[26]{ };
        for (char task : tasks)
            cnts[task-'A']++;
        
        int maxcnt = 0, freq = 0;
        for (int cnt : cnts)
        {
            if (maxcnt < cnt)
            {
                maxcnt = cnt;
                freq = 1;
            }
            else if (maxcnt == cnt)
            {
                freq++;
            }
        }
        return max(
            max(1 + n, freq) * (maxcnt - 1) + freq,
            (int) tasks.size()
        );
    }
};
// @lc code=end

