/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Trie
{
  private:
    constexpr static size_t arr_size = 'z' - 'a' + 1;
    struct TrieNode
    {
        bool valid = false;
        array<TrieNode *, arr_size> arr{};
    };
    TrieNode root;

    TrieNode *traverse(const string &word, bool insert)
    {
        TrieNode *node = &root;
        for (const char ch : word)
        {
            TrieNode *&child = node->arr.at(ch - 'a');
            if (!child)
            {
                if (!insert)
                {
                    return nullptr;
                }
                // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
                child = new TrieNode();
            }
            node = child;
        }
        return node;
    }

  public:
    Trie() = default;

    void insert(string word)
    {
        TrieNode *node = traverse(word, true);
        node->valid = true;
    }

    bool search(string word)
    {
        const TrieNode *node = traverse(word, false);
        return (node && node->valid);
    }

    bool startsWith(string prefix)
    {
        const TrieNode *node = traverse(prefix, false);
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
