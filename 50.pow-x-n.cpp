/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    double myPow_helper(double x, int64_t n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 1 / myPow_helper(x, -n);
        }

        const double sqr = myPow_helper(x, n / 2);
        double ans = sqr * sqr;
        if (n % 2)
        {
            ans *= x;
        }
        return ans;
    }

  public:
    double myPow(double x, int n)
    {
        return myPow_helper(x, n);
    }
};
// @lc code=end
