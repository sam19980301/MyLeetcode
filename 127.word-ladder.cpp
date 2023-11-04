/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // indexing
        unordered_map<string, int> m; // word : index
        for (string& word: wordList)
            m.insert({ word , m.size() });
        if (m.insert({ beginWord, m.size() }).second)
            wordList.push_back(beginWord);
        if (m.insert({ endWord, m.size() }).second)
            return 0;

        // build graph
        auto is_connected = [](string& a, string &b) -> bool {
            auto it_a = a.begin(), it_b = b.begin();
            int n = 0;
            while (it_a != a.end() && n != 2)
                if (*it_a++ != *it_b++)
                    n++;
            return n == 1;
        };
        vector<vector<int>> graph(wordList.size(), vector<int>());
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                if (is_connected(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // bfs
        int begin = m[beginWord], end = m[endWord], ans = 1;
        vector<bool> visited(wordList.size(), false);
        queue<int> q;
        visited[begin] = true;
        q.push(begin);

        while (!q.empty() && !visited[end])
        {
            ans++;
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                int from = q.front();
                q.pop();
                for (int to : graph[from])
                {
                    if (!visited[to])
                    {
                        visited[to] = true;
                        q.push(to);
                    }
                }
            }
        }
        return visited[end] ? ans : 0;
    }
};
// @lc code=end

