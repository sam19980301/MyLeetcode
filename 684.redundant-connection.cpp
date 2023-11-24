/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet s(edges.size());
        for (vector<int>& edge : edges)
            if (!s.union_set(edge[0] - 1, edge[1] - 1))
                return edge;
        return { };
    }
};
// @lc code=end

