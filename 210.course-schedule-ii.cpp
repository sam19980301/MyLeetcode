/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    using Graph = vector<vector<int>>;
    enum class State : uint8_t
    {
        kUnvisited,
        kVisiting,
        kVisited
    };
    bool findOrder_helper(int node, vector<State> &node_states, Graph &graph, vector<int> &ans)
    {
        auto &state = node_states.at(node);
        if (state == State::kVisiting)
        {
            return false;
        }
        if (state == State::kVisited)
        {
            return true;
        }
        // state == State::kUnvisited
        state = State::kVisiting;
        for (const int neighbor : graph.at(node))
        {
            if (!findOrder_helper(neighbor, node_states, graph, ans))
            {
                return false;
            }
        }
        ans.push_back(node);
        state = State::kVisited;
        return true;
    }

  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        Graph graph(numCourses);
        for (auto &prerequisite : prerequisites)
        {
            graph.at(prerequisite.front()).push_back(prerequisite.back());
        }

        vector<State> node_states(numCourses, State::kUnvisited);
        vector<int> ans;
        for (int node = 0; node < numCourses; node++)
        {
            if (!findOrder_helper(node, node_states, graph, ans))
            {
                return {};
            }
        }
        return ans;

        /*
        using Graph = vector<pair<int, vector<int>>>; // indegree, neighbors
        Graph graph(numCourses);
        for (auto &prerequisite : prerequisites)
        {
            graph.at(prerequisite.back()).second.push_back(prerequisite.front());
            graph.at(prerequisite.front()).first++;
        }

        vector<int> ans;
        ans.reserve(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            if (!graph.at(i).first)
            {
                ans.push_back(i);
            }
        }

        auto it = ans.begin();
        while (it != ans.end())
        {
            for (const int neighbor : graph.at(*it).second)
            {
                int &indegree = graph.at(neighbor).first;
                if (!--indegree)
                {
                    // Notes: must reserve first in case iterator being invalid after reallocation!
                    ans.push_back(neighbor);
                }
            }
            it++;
        }

        if (cmp_not_equal(ans.size(), numCourses))
        {
            return {};
        }
        return ans;
        */
    }
};
// @lc code=end
