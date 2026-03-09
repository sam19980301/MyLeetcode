/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // Kahn's algo. (BFS)
        using Graph = vector<vector<int>>;
        Graph graph(n);
        vector<int> indegress(n);
        for (auto &edge : edges)
        {
            const int node_a = edge.front();
            const int node_b = edge.back();
            graph.at(node_a).push_back(node_b);
            graph.at(node_b).push_back(node_a);
            indegress.at(node_a)++;
            indegress.at(node_b)++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegress.at(i) == 1)
            {
                q.push(i);
            }
        }

        vector<int> ans{0};
        while (!q.empty())
        {
            ans.clear();
            size_t qs = q.size();
            while (qs--)
            {
                const int node = q.front();
                ans.push_back(node);
                q.pop();
                for (const int neighbor : graph.at(node))
                {
                    if (--indegress.at(neighbor) == 1)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }
        return ans;

        /*
        using Graph = vector<vector<int>>;
        Graph graph(n);
        for (auto &edge : edges)
        {
            const int node_a = edge.front();
            const int node_b = edge.back();
            graph.at(node_a).push_back(node_b);
            graph.at(node_b).push_back(node_a);
        }

        vector<int> parents(n, -1);
        queue<int> q;

        auto findMinHeightTrees_helper = [&](int st_node) -> int {
            int ed_node = -1;
            parents.at(st_node) = st_node;
            q.push(st_node);

            while (!q.empty())
            {
                const int node = q.front();
                q.pop();
                ed_node = node;
                for (const int neighbor : graph.at(node))
                {
                    int &parent = parents.at(neighbor);
                    if (parent < 0)
                    {
                        parent = node;
                        q.push(neighbor);
                    }
                }
            }
            return ed_node;
        };

        // Assuming the diameter pair is [node_x, node_y]
        // 1st bfs starting from arbitrary node for node_x
        const int node_x = findMinHeightTrees_helper(0);

        // 2nd bfs starting from node_x for node_y
        ranges::fill(parents, -1);
        const int node_y = findMinHeightTrees_helper(node_x);

        // calculate the diameter
        int fast_node = node_y;
        int slow_node = node_y;
        while (fast_node != parents.at(fast_node) && parents.at(fast_node) != parents.at(parents.at(fast_node)))
        {
            fast_node = parents.at(parents.at(fast_node));
            slow_node = parents.at(slow_node);
        }
        if (fast_node != parents.at(fast_node))
        {
            return {slow_node, parents.at(slow_node)};
        }
        return {slow_node};
        */
    }
};
// @lc code=end
