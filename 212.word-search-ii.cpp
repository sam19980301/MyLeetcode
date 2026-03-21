/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 'z' - 'a' + 1;
    struct TrieNode
    {
        bool valid = false;
        array<TrieNode *, arr_size> arr{};
    };

    static constexpr char kVisited = '.';

    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};

    TrieNode root;

    void findWords_helper(TrieNode *node, int r, int c, vector<vector<char>> &board, string &curr_str,
                          vector<string> &ans)
    {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board.front().size());

        if (r < 0 || r >= m || c < 0 || c >= n)
        {
            return;
        }

        char &ch = board.at(r).at(c);
        if (ch == kVisited)
        {
            return;
        }

        node = node->arr.at(ch - 'a');
        if (!node)
        {
            return;
        }

        curr_str.push_back(ch);
        ch = kVisited;
        if (node->valid)
        {
            node->valid = false;
            ans.push_back(curr_str);
        }
        for (auto [dr, dc] : dirs)
        {
            findWords_helper(node, r + dr, c + dc, board, curr_str, ans);
        }
        ch = curr_str.back();
        curr_str.pop_back();
    }

  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (const string &word : words)
        {
            TrieNode *node = &root;
            for (const char ch : word)
            {
                TrieNode *&child = node->arr.at(ch - 'a');
                if (!child)
                {
                    child = new TrieNode(); // NOLINT(cppcoreguidelines-owning-memory)
                }
                node = child;
            }
            node->valid = true;
        }

        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board.front().size());

        vector<string> ans;
        string curr_str;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                findWords_helper(&root, r, c, board, curr_str, ans);
            }
        }
        return ans;
    }
};
// @lc code=end
