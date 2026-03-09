/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> m; // string: negative count
        for (const string &word : words)
        {
            m[word]++;
        }

        vector<pair<string, int>> heap;
        auto it = m.begin();
        while (k--)
        {
            heap.emplace_back(*it++);
        }
        auto greater_int_str = [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
            if (lhs.second > rhs.second)
            {
                return true;
            }
            if (lhs.second == rhs.second)
            {
                return lhs.first < rhs.first;
            }
            return false;
        };
        ranges::make_heap(heap, greater_int_str);

        while (it != m.end())
        {
            ranges::pop_heap(heap, greater_int_str);
            auto &curr = *it++;
            if (!greater_int_str(heap.back(), curr))
            {
                heap.back() = curr;
            }
            ranges::push_heap(heap, greater_int_str);
        }

        vector<string> ans;
        while (!heap.empty())
        {
            ranges::pop_heap(heap, greater_int_str);
            ans.push_back(heap.back().first);
            heap.pop_back();
        }
        ranges::reverse(ans);
        return ans;

        /*
        unordered_map<string, int> m; // string: negative count
        for (const string &word : words)
        {
            m[word]--;
        }

        vector<pair<int, string>> heap;
        heap.reserve(m.size());
        for (auto &[str, negative_cnt] : m)
        {
            heap.emplace_back(negative_cnt, str);
        }
        ranges::make_heap(heap, greater<>());

        vector<string> ans;
        while (k--)
        {
            ranges::pop_heap(heap, greater<>());
            ans.push_back(heap.back().second);
            heap.pop_back();
        }
        return ans;
        */
    }
};
// @lc code=end
