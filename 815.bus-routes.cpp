/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
        {
            return 0;
        }

        // routes: (bus: stops)

        // sentinel
        routes.emplace_back(vector<int>{source});

        unordered_map<int, vector<int>> m_buses; // (stop: buses)
        const int sz = static_cast<int>(routes.size());
        for (int i = 0; i < sz; i++)
        {
            for (const int stop : routes.at(i))
            {
                m_buses[stop].push_back(i);
            }
        }

        vector<bool> visited(routes.size());
        queue<int> q;
        q.push(static_cast<int>(routes.size()) - 1);

        int bus_took = -1;
        while (!q.empty())
        {
            bus_took++;
            size_t qs = q.size();
            while (qs--)
            {
                const int bus = q.front();
                q.pop();
                const vector<int> &route = routes.at(bus);
                for (const int stop : route)
                {
                    if (target == stop)
                    {
                        return bus_took;
                    }
                    for (const int next_bus : m_buses[stop])
                    {
                        if (!visited.at(next_bus))
                        {
                            visited.at(next_bus) = true;
                            q.push(next_bus);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
