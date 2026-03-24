/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int guessNumber(int n)
    {
        int lo = 1;
        int hi = n;
        while (lo <= hi)
        {
            const int mid = lo + ((hi - lo) / 2);
            const int result = guess(mid);
            if (result == 1) // num < pick
            {
                lo = mid + 1;
            }
            else if (result == -1) // num > pick
            {
                hi = mid;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
