/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    class Trie
    {
    public:
        struct TrieNode
        {
            TrieNode *children[26];
            bool is_terminal;
        };
    private:
        TrieNode *root;
    public:
        Trie(): root(new TrieNode()) { };

        void insert(string& s) {
            TrieNode *node = root;
            for (char ch : s)
            {
                TrieNode *&child = node->children[ch-'a'];
                if (!child)
                    child = new TrieNode();
                node = child;
            }
            node->is_terminal = true;
        }

        // bool search(string& s) { }

        TrieNode* get_root() { return root; }
    };

    void findWords_helper(vector<vector<char>>& board, vector<string>& ans, Trie::TrieNode* node, string& curr, int i, int j) {
        /*
            i, j : corrdinate to be visited
            node : trienode before visiting board[i][j]
        */
        int m = board.size(), n = board[0].size();
        if (!node || i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#')
            return ;


        node = node->children[board[i][j]-'a'];
        curr.push_back(board[i][j]);
        board[i][j] = '#';

        if (node && node->is_terminal)
        {
            ans.push_back(curr);
            node->is_terminal = false;
        }

        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int k = 0; k < 4; k++)
            findWords_helper(board, ans, node, curr, i + DIR[k],  j + DIR[k+1]);

        board[i][j] = curr.back();
        curr.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string& word : words)
            trie.insert(word);
        
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        string curr;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n;j ++)
                findWords_helper(board, ans, trie.get_root(), curr, i, j);
        return ans;
    }
};
// @lc code=end

