/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    string decodeString_helper(string::iterator &it, string::iterator ed_it)
    {
        /*
            let es = encoded_string
            es = es es | n[es] | letter
        */

        string ans;
        while (it != ed_it && *it != ']')
        {
            if (isalpha(*it))
            {
                ans.push_back(*it++);
            }
            else // isdigit(*it)
            {
                int n = 0;
                while (isdigit(*it))
                {
                    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                    n = (10 * n) + *it++ - '0';
                }

                it++; // *it == [
                const string substr = decodeString_helper(it, ed_it);
                it++; // *it == ]

                while (n--)
                {
                    ans += substr;
                }
            }
        }
        return ans;
    }

  public:
    string decodeString(string s)
    {
        // TODO(sam): Review
        auto it = s.begin();
        return decodeString_helper(it, s.end());

        /*
        stack<string> stk;
        stk.emplace();

        auto it = s.rbegin();
        while (it != s.rend())
        {
            const char ch = *it++;
            if (ch == '[')
            {
                int base = 1;
                int n = 0;
                while (it != s.rend() && isdigit(*it))
                {
                    n += (*it++ - '0') * base;
                    base *= 10; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                }
                const string str = stk.top();
                stk.pop();
                while (n--)
                {
                    stk.top() += str;
                }
            }
            else if (ch == ']')
            {
                stk.emplace();
            }
            else // isalpha(ch)
            {
                stk.top().push_back(ch);
            }
        }
        ranges::reverse(stk.top());
        return stk.top();
        */
    }
};
// @lc code=end
