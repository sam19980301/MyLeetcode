/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*
            If no k-step restriction: Dijkstra algo for single source SP problem & weight > 0, O(E+VlogV)
            
            c.f.
            Bellman Ford single-source SP, O(VE):   dist(s to j, k step) = min(dist(s to j, k-1 step), dist(s to ?, k-1 step) + weight(?, j))
            Floyd Warshall all-pairs SP, O(V^3):    dist(from i, to j, using k nodes) = min(
                                                                                            dist(from i, to j, using k-1 nodes),
                                                                                            dist(from i, to *, using k-1 nodes) + dist(from *, to j, using k-1 nodes)
                                                                                        )
        */

        // Bellman Ford        
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        for (int i = 0; i < k + 1; i++)
        {
            dp[1] = dp[0];
            for (vector<int>& flight : flights) // from, to, value
            {
                if (dp[0][flight[0]] != INT_MAX)
                {
                    dp[1][flight[1]] = min(dp[1][flight[1]], dp[0][flight[0]] + flight[2]);
                }
            }
            dp[0].swap(dp[1]);
        }
        return (dp[0][dst] == INT_MAX) ? -1 : dp[0][dst];
    }
};
// @lc code=end

