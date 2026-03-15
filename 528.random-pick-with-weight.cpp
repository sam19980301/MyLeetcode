/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    vector<int> cumsum;

  public:
    explicit Solution(vector<int> &w) : cumsum(w)
    {
        for (auto it = cumsum.begin() + 1; it != cumsum.end(); it++)
        {
            *it += *(it - 1);
        }
    }

    int pickIndex()
    {
        const int rand_num = rand() % static_cast<int>(cumsum.back());
        auto it = ranges::upper_bound(cumsum, rand_num, less<>());
        return static_cast<int>(distance(cumsum.begin(), it));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
