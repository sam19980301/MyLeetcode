/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int calPoints(vector<string> &operations)
    {
        vector<int> scores;
        for (const string &operation : operations)
        {
            if (operation == "C")
            {
                scores.pop_back();
            }
            else if (operation == "D")
            {
                scores.push_back(scores.back() * 2);
            }
            else if (operation == "+")
            {
                scores.push_back(*scores.rbegin() + *(scores.rbegin() + 1));
            }
            else
            {
                scores.push_back(stoi(operation));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
// @lc code=end
