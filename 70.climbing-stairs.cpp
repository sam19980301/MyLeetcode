/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
/*
constexpr size_t max_n = 45;
using Arr = array<int, max_n + 1>;
consteval Arr climbStairs_helper()
{
    Arr arr{};
    arr[0] = 1;
    arr[1] = 1;
    for (size_t i = 2; i <= max_n; i++)
    {
        arr.at(i) = arr.at(i - 1) + arr.at(i - 2);
    }
    return arr;
}
*/
class Solution
{
    /*
      private:
        constexpr static Arr arr = climbStairs_helper();
    */
  public:
    int climbStairs(int n)
    {
        int prev = 1;
        int curr = 1;
        for (int i = 1; i < n; i++)
        {
            const int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
        /*
        return arr.at(n);
        */
    }
};
// @lc code=end
