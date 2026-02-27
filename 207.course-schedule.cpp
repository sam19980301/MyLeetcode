/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
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
    bool canFinished_helper(int node, vector<State> &node_states, Graph &graph)
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
            if (!canFinished_helper(neighbor, node_states, graph))
            {
                return false;
            }
        }
        state = State::kVisited;
        return true;
    }

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // TODO(sam): Review
        // topological sorting

        // DFS
        // build graph
        Graph graph(numCourses);
        for (auto &prerequisite : prerequisites)
        {
            graph.at(prerequisite.front()).push_back(prerequisite.back());
        }

        // check if there's any cycle
        vector<State> node_states(numCourses, State::kUnvisited);
        for (int node = 0; node < numCourses; node++)
        {
            if (!canFinished_helper(node, node_states, graph))
            {
                return false;
            }
        }
        return true;

        /*
        // Kahn's algo. (BFS)
        // build graph
        using Graph = vector<pair<int, vector<int>>>; // indegree, neighbors
        Graph graph(numCourses);
        for (auto &prerequisite : prerequisites)
        {
            graph.at(prerequisite.front()).second.push_back(prerequisite.back());
            graph.at(prerequisite.back()).first++;
        }

        int visited_node = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!graph.at(i).first)
            {
                q.push(i);
                visited_node++;
            }
        }

        while (!q.empty())
        {
            for (const int neighbor : graph.at(q.front()).second)
            {
                int &indegree = graph.at(neighbor).first;
                if (!--indegree)
                {
                    q.push(neighbor);
                    visited_node++;
                }
            }
            q.pop();
        }
        return visited_node == numCourses;
        */
    }
};
// @lc code=end
