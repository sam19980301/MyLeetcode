/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 128;

  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        array<int, arr_size> freqs{};
        for (const char task : tasks)
        {
            freqs.at(task)++;
        }

        int max_freq = -1;
        int count = 0;
        for (const int freq : freqs)
        {
            if (max_freq < freq)
            {
                max_freq = freq;
                count = 1;
            }
            else if (max_freq == freq)
            {
                count++;
            }
        }
        return max(((1 + n) * (max_freq - 1)) + count, static_cast<int>(tasks.size()));
    }
};
// @lc code=end
