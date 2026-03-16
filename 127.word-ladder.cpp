/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s(wordList.begin(), wordList.end());

        int ans = 1;
        queue<string> q({beginWord});
        while (!q.empty())
        {
            ans++;
            auto qs = q.size();
            while (qs--)
            {
                string str = q.front();
                q.pop();
                for (auto &curr_ch : str)
                {
                    const char orig_ch = curr_ch;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        curr_ch = ch;
                        if (curr_ch == orig_ch)
                        {
                            continue;
                        }

                        auto it = s.find(str);
                        if (it == s.end())
                        {
                            continue;
                        }
                        if (*it == endWord)
                        {
                            return ans;
                        }
                        q.push(str);
                        s.erase(it);
                    }

                    curr_ch = orig_ch;
                }
            }
        }
        return 0;
    }
};
// @lc code=end
