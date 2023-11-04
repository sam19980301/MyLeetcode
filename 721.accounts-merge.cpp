/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Notes : template for disjoint set
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
        // make set
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
        void union_set(int x, int y) {
            x = find_set(x);
            y = find_set(y);
            if (x == y)
                return ;
            if (arr[x].rank < arr[y].rank)
            {
                arr[x].parent = y;
            }
            else
            {
                arr[y].parent = x;
                arr[x].rank = max(arr[x].rank, 1 + arr[y].rank);
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m; // email : index
        for (vector<string>& account : accounts)
            for (int i = 1; i < account.size(); i++)
                m.insert({ account[i], m.size() });
        
        DisjointSet dj(m.size());
        for (vector<string>& account : accounts)
        {
            int x = m[account[1]];
            for (int i = 2; i < account.size(); i++)
                dj.union_set(x, m[account[i]]);
        }

        unordered_map<int, pair<string, unordered_set<string>>> ans_m; // dj-group : name : { email ... }
        for (vector<string>& account : accounts)
        {
            unordered_set<string>& s = ans_m.insert({ dj.find_set(m[account[1]]), { account[0], { } } }).first->second.second;
            for (int i = 1; i < account.size(); i++)
                s.insert(account[i]);
        }

        vector<vector<string>> ans;
        for (auto& [group_id, pr] : ans_m)
        {
            auto& [name, mails] = pr;
            ans.push_back({ name });
            for (string mail : mails)
                ans.back().push_back(mail);
            sort(ans.back().begin() + 1, ans.back().end());
        }
        return ans;
    }
};
// @lc code=end

