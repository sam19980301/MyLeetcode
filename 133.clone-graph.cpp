/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#ifdef LEETCODE_LOCAL_DEV
#include "133.clone-graph.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    Node *cloneGraph_helper(Node *node, unordered_map<Node *, Node *> &m)
    {
        auto [it, success] = m.insert({node, nullptr});
        if (success)
        {
            // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
            it->second = new Node(node->val);
            for (Node *neighbor : node->neighbors)
            {
                it->second->neighbors.push_back(cloneGraph_helper(neighbor, m));
            }
        }
        return it->second;
    }

  public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> m;
        return cloneGraph_helper(node, m);
    }
};
// @lc code=end
