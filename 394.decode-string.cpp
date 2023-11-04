/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    string decodeString_helper(string& s, int& index) {
        /*
            encoded_string =    k[encoded_string] |
                                char + encoded_string
        */

        string ans;
        while (index < s.size() && s[index] != ']')
        {
            if (isalpha(s[index]))
                ans += s[index++];
            else // digit
            {
                int n = 0;
                while (isdigit(s[index]))
                    n = 10*n+s[index++]-'0';
                index++; // [
                string substr = decodeString_helper(s, index);
                index++; // ]
                for (int i = 0; i < n; i++)
                    ans += substr;
            }
        }
        return ans;
    }
    
    // void decodeString_helper(string& s, string& ans, int& index) {
    //     if (index == s.size() || s[index] == ']')
    //         return ;
        
    //     if (isdigit(s[index]))
    //     {
    //         int n = 0;
    //         while (isdigit(s[index]))
    //             n = n * 10 + s[index++] - '0';
    //         string substr;
    //         index++; // [
    //         decodeString_helper(s, substr, index);
    //         index++; // ]
    //         for (int i = 0; i < n; i++)
    //             ans += substr;
    //     }
    //     else // char or ]
    //         ans.push_back(s[index++]);
    //     decodeString_helper(s, ans, index);
    // }
public:
    string decodeString(string s) {
        /*
            encoded-string =    n [ encoded-string' ] |
                                char encoded-string'
        */

        int index = 0;
        return decodeString_helper(s, index);

        // string ans;
        // int index = 0;
        // decodeString_helper(s, ans, index);
        // return ans;
    }
};
// @lc code=end

