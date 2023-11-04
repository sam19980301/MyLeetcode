/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static bool is_palindrome(string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }

    class Trie
    {
    private:
        struct TrieNode
        {
            TrieNode *children[26];
            int index; // is_terminal
            vector<int> indexes;
            TrieNode(): children{ }, index(-1), indexes() { }
        };
        
        TrieNode *root;
    public:
        Trie(): root(new TrieNode()) { }

        void insert(string& s, int index)
        {
            TrieNode *node = root;
            for (int i = 0; i < s.size(); i++)
            {
                if (is_palindrome(s, i, s.size() - 1))
                    node->indexes.push_back(index);
                TrieNode *&child = node->children[s[i]-'a'];
                if (!child)
                    child = new TrieNode();
                node = child;
            }
            node->index = index;
            node->indexes.push_back(index);
        }

        void search(string &s, vector<vector<int>>& ans, int index)
        {
            reverse(s.begin(), s.end());

            TrieNode *node = root;
            for (int i = 0; i < s.size(); i++)
            {
                if (node->index >= 0 && node->index != index && is_palindrome(s, i, s.size() - 1))
                    ans.push_back({ node->index, index });
                node = node->children[s[i]-'a'];
                if (!node)
                    return ;
            }
            for (int i : node->indexes)
                if (i != index)
                    ans.push_back({ i, index });
            
            reverse(s.begin(), s.end());
        }
    };
        
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        /*
            XXXXX + YYY
            XXX + YYYYY
        */

        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], i);

        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
            trie.search(words[i], ans, i);
        return ans;
    }
};
// @lc code=end

