/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string simplifyPath(string path)
    {
        vector<string> dirs;

        auto it = path.begin();
        while (it != path.end())
        {
            while (it != path.end() && *it == '/')
            {
                it++;
            }

            string str;
            while (it != path.end() && *it != '/')
            {
                str.push_back(*it++);
            }

            if (str.empty() || str == ".")
            {
                // do nothing
            }
            else if (str == "..")
            {
                if (!dirs.empty())
                {
                    dirs.pop_back();
                }
            }
            else
            {
                dirs.push_back(str);
            }
        }

        if (dirs.empty())
        {
            return "/";
        }

        string ans;
        for (auto &dir : dirs)
        {
            ans.push_back('/');
            ans += dir;
        }
        return ans;
    }
};
// @lc code=end
