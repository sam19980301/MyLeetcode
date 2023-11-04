/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class WordDictionary {
private:
    struct TrieNode
    {
        TrieNode *children[26];
        bool is_terminal;
    };

    TrieNode *root;        
public:
    WordDictionary(): root(new TrieNode()) { }
    
    void addWord(string word) {
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
    
    bool search(string word) { return search_helper(word, root, 0); }

    bool search_helper(string& word, TrieNode* node, int index) {
        if (!node)
            return false;

        if (word.size() == index)
            return node->is_terminal;
        
        char ch = word[index];
        if (ch != '.')
            return search_helper(word, node->children[ch-'a'], index+1);
        
        for (int i = 0; i < 26; i++)
            if (search_helper(word, node->children[i], index+1))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

