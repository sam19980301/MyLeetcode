/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    class DisjointSet
    {
      private:
        struct DisjointSetNode
        {
            size_t parent; // set id
            size_t rank;
        };
        vector<DisjointSetNode> arr;

      public:
        explicit DisjointSet(const size_t n) : arr(n)
        {
            // iota(arr.begin(), arr.end(), ...);
            for (size_t i = 0; i < arr.size(); i++)
            {
                arr.at(i).parent = i;
            }
        }

        size_t find_set(const size_t x)
        {
            size_t &parent = arr.at(x).parent;
            if (parent != x)
            {
                parent = find_set(parent);
            }
            return parent;
        }

        void union_set(const size_t x, const size_t y)
        {
            DisjointSetNode &node_x = arr.at(find_set(x));
            DisjointSetNode &node_y = arr.at(find_set(y));
            if (node_x.parent == node_y.parent)
            {
                return;
            }

            if (node_x.rank < node_y.rank)
            {
                node_x.parent = node_y.parent;
            }
            else
            {
                node_y.parent = node_x.parent;
                node_x.rank = max(node_x.rank, 1 + node_y.rank);
            }
        }
    };

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // Disjoint set
        unordered_map<string, size_t> mail_m;
        for (auto &account : accounts)
        {
            for (auto it = account.begin() + 1; it != account.end(); it++)
            {
                mail_m.emplace(*it, mail_m.size());
            }
        }

        DisjointSet s(mail_m.size());
        for (auto &account : accounts)
        {
            const size_t set_id = mail_m.at(account.at(1));
            for (auto it = account.begin() + 2; it != account.end(); it++)
            {
                s.union_set(set_id, mail_m.at(*it));
            }
        }

        unordered_map<size_t, string> name_m;
        unordered_map<size_t, set<string>> mails_m;
        for (auto &account : accounts)
        {
            const size_t set_id = s.find_set(mail_m.at(account.at(1)));
            name_m[set_id] = account.front();
            mails_m[set_id].insert(account.begin() + 1, account.end());
        }

        vector<vector<string>> ans;
        for (auto &[set_id, mails] : mails_m)
        {
            vector<string> person_accounts;
            person_accounts.push_back(name_m[set_id]);
            person_accounts.insert(person_accounts.end(), mails.begin(), mails.end());
            ans.push_back(person_accounts);
        }
        return ans;
    }
};
// @lc code=end
