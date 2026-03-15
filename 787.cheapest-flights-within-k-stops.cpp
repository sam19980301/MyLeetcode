/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr int max_dist = numeric_limits<int>::max();
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        /*
            Shortest Path
            Bellman Ford (Single-Source) SP, Complexity O(VE): based on edge count attribute
                dist(src, dst, at most k steps) = min(
                    dist(src, dst, at most k-1 steps),
                    dist(src, mid, at most k-1 steps) + weight(mid, dst) for every possible mid node
                )

            Floyd Warshall (All-Pairs) SP, Complexity O(V^3): based on intermediate node attribute
                dist(src, dst, using first k nodes) = min(
                    // not passing node k
                    dist(src, dst, using first k-1 nodes),
                    // passing node k
                    dist(src, k,   using first k-1 nodes) + dist(k,   dst, using first k-1 nodes)
                )
        */

        // Bellman Ford
        vector<int> dp_prev(n, max_dist);
        dp_prev.at(src) = 0;

        for (int stop = 0; stop <= k; stop++)
        {
            vector<int> dp_curr(dp_prev);
            for (auto &flight : flights)
            {
                const int flight_src = flight.at(0);
                const int flight_dst = flight.at(1);
                const int flight_price = flight.at(2);
                if (dp_prev.at(flight_src) != max_dist)
                {
                    dp_curr.at(flight_dst) = min(dp_curr.at(flight_dst), dp_prev.at(flight_src) + flight_price);
                }
            }
            dp_prev.swap(dp_curr);
        }
        return dp_prev.at(dst) != max_dist ? dp_prev.at(dst) : -1;
    }
};
// @lc code=end
