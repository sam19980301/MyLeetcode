/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 'z' - 'a' + 1;
    static constexpr int kUninitialized = -1;
    struct TrieNode
    {
        int index = kUninitialized;
        vector<int> valid_indices;
        array<TrieNode *, arr_size> arr{};
    };
    TrieNode root;

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) // NOLINT(readability-function-cognitive-complexity)
    {
        // TODO(sam): Review twice!
        vector<vector<int>> ans;

        auto is_palindrome = [](auto st_it, auto ed_it) {
            while (st_it < ed_it)
            {
                if (*st_it++ != *--ed_it)
                {
                    return false;
                }
            }
            return true;
        };

        auto add = [&](int index) {
            const string &word = words.at(index);
            TrieNode *node = &root;
            for (auto it = word.rbegin(); it != word.rend(); it++)
            {
                if (is_palindrome(it, word.rend()))
                {
                    node->valid_indices.push_back(index);
                }
                TrieNode *&child = node->arr.at(*it - 'a');
                if (!child)
                {
                    child = new TrieNode(); // NOLINT(cppcoreguidelines-owning-memory)
                }
                node = child;
            }
            node->index = index;
            node->valid_indices.push_back(index);
        };

        auto search = [&](int index) {
            const string &word = words.at(index);
            TrieNode *node = &root;
            for (auto it = word.begin(); it != word.end(); it++)
            {
                const int i = node->index;
                if (index != i && i != kUninitialized && is_palindrome(it, word.end()))
                {
                    ans.push_back({index, i});
                }
                node = node->arr.at(*it - 'a');
                if (!node)
                {
                    return;
                }
            }

            for (const int i : node->valid_indices)
            {
                if (index != i)
                {
                    ans.push_back({index, i});
                }
            }
        };
        const int sz = static_cast<int>(words.size());
        for (int i = 0; i < sz; i++)
        {
            add(i);
        }

        for (int i = 0; i < sz; i++)
        {
            search(i);
        }
        return ans;
    }
};
// @lc code=end
