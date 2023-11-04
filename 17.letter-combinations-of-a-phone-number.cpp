/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const char LETTERS[8][4];
    void letterCombinations_helper(string& digits, vector<string>& ans, string& curr, int index) {
        if (digits.size() == index)
        {
            ans.push_back(curr);
            return ;
        }

        curr.push_back('#');
        for (char ch : LETTERS[digits[index]-'2'])
        {
            if (ch)
            {
                curr.back() = ch;
                letterCombinations_helper(digits, ans, curr, index + 1);
            }
        }
        curr.pop_back();
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return { };
        vector<string> ans;
        string curr;
        letterCombinations_helper(digits, ans, curr, 0);
        return ans;
    }
};
const char Solution::LETTERS[8][4] = {
    { 'a', 'b', 'c' },
    { 'd', 'e', 'f' },
    { 'g', 'h', 'i' },
    { 'j', 'k', 'l' },
    { 'm', 'n', 'o' },
    { 'p', 'q', 'r', 's' },
    { 't', 'u', 'v' },
    { 'w', 'x', 'y', 'z'} 
};
// @lc code=end

