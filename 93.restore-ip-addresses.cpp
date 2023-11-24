/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void restoreIpAddresses_helper(string& s, vector<string>& ans, vector<int>& curr, int index)
    {
        if (curr.size() > 4)
            return ;

        if (index == s.size())
        {
            if (curr.size() == 4)
            {
                string ip;
                for (int i = 0; i < curr.size(); i++)
                {
                    ip += to_string(curr[i]);
                    if (i != 3)
                        ip.push_back('.');
                }
                ans.push_back(ip);
            }
            return ;
        }

        if (s[index] == '0')
        {
            curr.push_back(0);
            restoreIpAddresses_helper(s, ans, curr, ++index);
            curr.pop_back();
        }
        else
        {
            int n = 0;
            while (index < s.size() && n <= 255)
            {
                n = n * 10 + (s[index++] - '0');
                if (n <= 255)
                {
                    curr.push_back(n);
                    restoreIpAddresses_helper(s, ans, curr, index);
                    curr.pop_back();
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> curr;
        restoreIpAddresses_helper(s, ans, curr, 0);
        return ans;
    }
};
// @lc code=end

