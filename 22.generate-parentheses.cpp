/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void generateParenthesis_helper(int l, int r, string &curr, vector<string> &ans)
    {
        if (!l && !r)
        {
            ans.push_back(curr);
            return;
        }

        if (l)
        {
            curr.push_back('(');
            generateParenthesis_helper(l - 1, r, curr, ans);
            curr.pop_back();
        }

        if (l < r)
        {
            curr.push_back(')');
            generateParenthesis_helper(l, r - 1, curr, ans);
            curr.pop_back();
        }
    }

  public:
    vector<string> generateParenthesis(int n)
    {
        // TODO(sam): Review
        vector<string> ans;
        string curr;
        generateParenthesis_helper(n, n, curr, ans);
        return ans;
    }
};
// @lc code=end
