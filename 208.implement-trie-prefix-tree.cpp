/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Trie {
private:
    struct TrieNode
    {
        bool is_terminal;
        TrieNode *children[26];
        // TrieNode(): is_terminal(false), children{ } { }
    };
    TrieNode *root;

public:
    Trie(): root(new TrieNode()) { }
    
    void insert(string word) {
        TrieNode *node = root;
        for (char ch : word)
        {
            TrieNode *&child = node->children[ch-'a'];
            if (!child)
                child = new TrieNode();
            node = child;
        }
        node->is_terminal = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for (char ch : word)
        {
            node = node->children[ch-'a'];
            if (!node)
                return false;
        }
        return node->is_terminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            node = node->children[ch-'a'];
            if (!node)
                return false;
        }
        for (int i = 0; i < 26; i++)
            if (node->children[i])
                return true;
        return node->is_terminal;
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

