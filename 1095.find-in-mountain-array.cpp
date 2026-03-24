/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
#ifdef LEETCODE_LOCAL_DEV
#include "1095.find-in-mountain-array.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        // TODO(sam): Review
        enum class Pass : uint8_t
        {
            kFindPeak,
            kLeftSide,
            kRightSide,
        };
        auto binary_search = [&mountainArr, &target](int lo, int hi, Pass pass) {
            while (lo < hi)
            {
                const int mid = lo + ((hi - lo) / 2);
                const int mid_value = mountainArr.get(mid);
                bool cond = true;
                if (pass == Pass::kFindPeak)
                {
                    cond = mid_value < mountainArr.get(mid + 1);
                }
                else if (pass == Pass::kLeftSide)
                {
                    cond = less<>()(mid_value, target);
                }
                else if (pass == Pass::kRightSide)
                {
                    cond = greater<>()(mid_value, target);
                }

                if (cond)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid;
                }
            }
            return lo;
        };

        const int peak_index = binary_search(0, mountainArr.length() - 1, Pass::kFindPeak);
        auto l_index = binary_search(0, peak_index, Pass::kLeftSide);
        if (mountainArr.get(l_index) == target)
        {
            return l_index;
        }
        auto r_index = binary_search(peak_index, mountainArr.length() - 1, Pass::kRightSide);
        if (mountainArr.get(r_index) == target)
        {
            return r_index;
        }
        return -1;
    }
};
// @lc code=end
