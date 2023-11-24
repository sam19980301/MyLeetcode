/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
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
        int find_set(int x)
        {
            if (arr[x].parent != x)
                arr[x].parent = find_set(arr[x].parent);
            return arr[x].parent;
        }

        // union
        bool union_set(int x, int y)
        {
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet s(n);
        for (vector<int>& edge : edges)
            s.union_set(edge[0], edge[1]);
        return s.find_set(source) == s.find_set(destination);
    }
};
// @lc code=end

