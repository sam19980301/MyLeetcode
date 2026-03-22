/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    using vec_it = vector<int>::iterator;
    void sortArray_helper(vec_it st_it, vec_it ed_it)
    {
        // quick sort
        // [st_it, lt_it): < pivot
        // [lt_it, eq_it): = pivot
        // [eq_it, gt_it)
        // [gt_it, ed_it): > pivot

        if (st_it == ed_it)
        {
            return;
        }

        const int pivot = *st_it;
        auto lt_it = st_it;
        auto eq_it = st_it + 1;
        auto gt_it = ed_it;
        while (eq_it < gt_it)
        {
            const int value = *eq_it;
            if (value < pivot)
            {
                swap(*lt_it++, *eq_it++);
            }
            else if (value == pivot)
            {
                eq_it++;
            }
            else // value > pivot
            {
                swap(*eq_it, *--gt_it);
            }
        }

        sortArray_helper(st_it, lt_it);
        sortArray_helper(gt_it, ed_it);

        // merge sort
        /*
        if (st_it + 1 == ed_it)
        {
            return;
        }

        auto mid_it = st_it + distance(st_it, ed_it) / 2;
        vector<int> vec_0(st_it, mid_it);
        sortArray_helper(vec_0.begin(), vec_0.end());
        vector<int> vec_1(mid_it, ed_it);
        sortArray_helper(vec_1.begin(), vec_1.end());

        auto it_0 = vec_0.begin();
        auto it_1 = vec_1.begin();
        for (auto it = st_it; it != ed_it; it++)
        {
            if (it_1 == vec_1.end() || (it_0 != vec_0.end() && *it_0 < *it_1))
            {
                *it = *it_0++;
            }
            else
            {
                *it = *it_1++;
            }
        }
        */
    }

  public:
    vector<int> sortArray(vector<int> &nums)
    {
        random_device rd;
        mt19937 gen(rd());
        ranges::shuffle(nums, gen);

        sortArray_helper(nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end
