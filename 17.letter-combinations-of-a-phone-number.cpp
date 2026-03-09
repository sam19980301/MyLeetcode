/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  private:
    static constexpr array<string_view, 10> arr{
        /* 0 */ "",
        /* 1 */ "",
        /* 2 */ "abc",
        /* 3 */ "def",
        /* 4 */ "ghi",
        /* 5 */ "jkl",
        /* 6 */ "mno",
        /* 7 */ "pqrs",
        /* 8 */ "tuv",
        /* 9 */ "wxyz",
    };

    void letterCombinations_helper(string::iterator it, string::iterator ed_it, string &curr, vector<string> &ans)
    {
        if (it == ed_it)
        {
            ans.push_back(curr);
            return;
        }

        for (const char ch : arr.at(*it - '0'))
        {
            curr.push_back(ch);
            letterCombinations_helper(it + 1, ed_it, curr, ans);
            curr.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string curr;
        letterCombinations_helper(digits.begin(), digits.end(), curr, ans);
        return ans;

        /*
        if (digits.empty())
        {
            return {};
        }
        vector<string> ans{""};
        for (auto digit : digits)
        {
            vector<string> curr_ans;
            curr_ans.swap(ans);
            for (const char ch : arr.at(digit - '0'))
            {
                for (auto &str : curr_ans)
                {
                    ans.push_back(str + ch);
                }
            }
        }
        return ans;
        */
    }
};
// @lc code=end
