/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
  private:
    stack<pair<int, int>> s; // price, day

  public:
    // TODO(sam): Review
    StockSpanner()
    {
        s.emplace(numeric_limits<int>::max(), -1);
    }

    int next(int price)
    {
        const int day = s.top().second + 1;
        while (s.top().first <= price)
        {
            s.pop();
        }
        const int span = day - s.top().second;
        s.emplace(price, day);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
