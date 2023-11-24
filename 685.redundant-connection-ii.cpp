/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    class DisjointSet
    {
    private:
        struct DisjointSetNode
        {
            int parent;
            int rank;
        };
        vector<DisjointSetNode> arr; 
    public:
        DisjointSet(int n = 0): arr(n) {
            for (int i = 0; i < n; i++)
                arr[i].parent = i;
        }

        // find
        int find_set(int x) {
            if (arr[x].parent != x)
                arr[x].parent = find_set(arr[x].parent);
            return arr[x].parent;
        }

        // union
        bool union_set(int x, int y) {
            x = find_set(x);
            y = find_set(y);
            if (x == y)
                return false;
            if (arr[x].rank < arr[y].rank)
            {
                arr[x].parent = y;
            }
            else
            {
                arr[y].parent = x;
                arr[x].rank = max(arr[x].rank, 1 + arr[y].rank);
            }
            return true;
        }
    };    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /*
            case 1 : two parents (cand_a & cand_b)
            case 2 : cycle (edge)
        */
        int n = edges.size();
        vector<int> parents(n + 1, -1), cand_a = { }, cand_b = { };
        bool has_removed = false;
        for (vector<int>& edge : edges)
        {
            if (parents[edge[1]] != -1)
            {
                cand_a = { parents[edge[1]], edge[1] };
                cand_b = edge;
                edge.clear();
                has_removed = true;
                break;
            }
            parents[edge[1]] = edge[0];
        }

        DisjointSet s(n);
        for (vector<int>& edge : edges)
        {
            if (edge.empty())
                continue;
            if (!s.union_set(edge[0] - 1, edge[1] - 1))
            {
                if (has_removed)
                    return cand_a;
                return edge;
            }
        }
        return cand_b;
    }
};
// @lc code=end

