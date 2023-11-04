/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> m; // stop : buses
        for (int bus = 0; bus < routes.size(); bus++)
            for (int stop : routes[bus])
                m[stop].push_back(bus);

        vector<vector<int>> graph(routes.size() + 2);
        for (auto& [stop, buses] : m)
        {
            for (int i = 0; i < buses.size(); i++)
            {
                for (int j = i + 1; j < buses.size(); j++)
                {
                    graph[buses[i]].push_back(buses[j]);
                    graph[buses[j]].push_back(buses[i]);
                }
            }
            // meta source and meta target
            if (stop == source)
            {
                for (int bus : buses)
                {
                    graph[graph.size() - 2].push_back(bus);
                    graph[bus].push_back(graph.size() - 2);
                }
            }
            if (stop == target)
            {
                for (int bus : buses)
                {
                    graph[graph.size() - 1].push_back(bus);
                    graph[bus].push_back(graph.size() - 1);
                }
            }
        }
        
        vector<bool> visited(graph.size(), false);
        queue<int> q;
        visited[graph.size() - 2] = true;
        q.push(graph.size() - 2);

        int ans = -1;
        while (!q.empty())
        {
            ans++;
            int qs = q.size();
            cout << ans << " " << qs << endl;
            for (int i = 0; i < qs; i++)
            {
                cout << q.front() << endl;
                for (int j : graph[q.front()])
                {
                    if (j == graph.size() - 1)
                        return ans;
                    if (!visited[j])
                    {
                        cout << "push " << j << endl;
                        visited[j] = true;
                        q.push(j);
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};
// @lc code=end

