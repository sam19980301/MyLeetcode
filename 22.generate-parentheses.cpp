/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void generateParenthesis_helper(vector<string>& ans, string& curr, int l, int r) {
        if (l == 0 && r == 0)
        {
            ans.push_back(curr);
            return ;
        }

        if (l)
        {
            curr.push_back('(');
            generateParenthesis_helper(ans, curr, l-1, r);
            curr.pop_back();
        }

        if (r > l)
        {
            curr.push_back(')');
            generateParenthesis_helper(ans, curr, l, r-1);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        /*
            X = (X') | ()X'
            
            ( -> () -> ()()
              -> (( -> (())
        */
        vector<string> ans;
        string curr;
        generateParenthesis_helper(ans, curr, n, n);
        return ans;
    }
};
// @lc code=end

