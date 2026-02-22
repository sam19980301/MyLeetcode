/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
constexpr static size_t arr_size = 128;
using Arr = array<int, arr_size>;
consteval Arr romanToInt_helper()
{
    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    Arr arr{};
    arr['I'] = 1;
    arr['V'] = 5;
    arr['X'] = 10;
    arr['L'] = 50;
    arr['C'] = 100;
    arr['D'] = 500;
    arr['M'] = 1000;
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    return arr;
}
class Solution
{
  private:
    constexpr static Arr arr = romanToInt_helper();

  public:
    int romanToInt(string s)
    {
        int val = 0;
        int prev = 0;
        for (const char ch : ranges::reverse_view(s))
        {
            const int curr = arr.at(ch);
            if (curr >= prev)
            {
                val += curr;
            }
            else
            {
                val -= curr;
            }
            prev = curr;
        }
        return val;
    }
};
// @lc code=end
