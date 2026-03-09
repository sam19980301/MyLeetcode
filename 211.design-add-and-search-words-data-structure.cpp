/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class WordDictionary
{
  private:
    static constexpr size_t arr_size = 'z' - 'a' + 1;
    struct TrieNode
    {
        bool valid = false;
        array<TrieNode *, arr_size> arr{};
    };

    TrieNode root;

    enum class TraverseType : uint8_t
    {
        kAdd,
        kSearch,
    };
    TrieNode *traverse(string::iterator it, string::iterator ed_it, TrieNode *&node, const TraverseType traverse_type)
    {
        if (!node)
        {
            if (traverse_type == TraverseType::kSearch)
            {
                return nullptr;
            }
            node = new TrieNode(); // NOLINT(cppcoreguidelines-owning-memory)
        }

        if (it == ed_it)
        {
            if (traverse_type == TraverseType::kAdd || (node && node->valid))
            {
                node->valid = true;
                return node;
            }
            return nullptr;
        }

        const char st_ch = *it == '.' ? 'a' : *it;
        const char ed_ch = *it == '.' ? 'z' : *it;
        for (char ch = st_ch; ch <= ed_ch; ch++)
        {
            // NOLINTNEXTLINE(misc-const-correctness)
            TrieNode *const child_traverse = traverse(it + 1, ed_it, node->arr.at(ch - 'a'), traverse_type);
            if (child_traverse)
            {
                return child_traverse;
            }
        }
        return nullptr;
    }

  public:
    WordDictionary() = default;

    void addWord(string word)
    {
        TrieNode *root_ptr = &root; // NOLINT(misc-const-correctness)
        traverse(word.begin(), word.end(), root_ptr, TraverseType::kAdd);
    }

    bool search(string word)
    {
        TrieNode *root_ptr = &root; // NOLINT(misc-const-correctness)
        return traverse(word.begin(), word.end(), root_ptr, TraverseType::kSearch);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
