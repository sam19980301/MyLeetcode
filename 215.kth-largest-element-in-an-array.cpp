/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    int findKthLargest_helper(vector<int>::iterator st_it, vector<int>::iterator ed_it, int k)
    {
        // parition (similar to 75.sort-colors)
        // [st_it, gt_it): > pivot
        // [gt_it, eq_it): = pivot
        // [eq_it, lt_it):
        // [lt_it, ed_it): < pivot

        const int pivot = *st_it;
        auto gt_it = st_it;
        auto eq_it = st_it + 1;
        auto lt_it = ed_it;
        while (eq_it < lt_it)
        {
            const int value = *eq_it;
            if (value > pivot)
            {
                swap(*gt_it++, *eq_it++);
            }
            else if (value == pivot)
            {
                eq_it++;
            }
            else // value < pivot
            {
                swap(*eq_it, *--lt_it);
            }
        }

        auto gt_len = static_cast<int>(distance(st_it, gt_it));
        if (gt_len >= k)
        {
            return findKthLargest_helper(st_it, gt_it, k);
        }
        k -= gt_len;

        auto eq_len = static_cast<int>(distance(gt_it, eq_it));
        if (eq_len >= k)
        {
            return pivot;
        }
        k -= eq_len;

        // auto lt_len = static_cast<int>(distance(lt_it, ed_it));
        return findKthLargest_helper(lt_it, ed_it, k);

        /*
        const int pivot = *st_it;

        // [   st_it, ge_ed_it): >= pivot (last value is pivot)
        // [ge_ed_it,    ed_it): <  pivot
        auto greater_equal_pivot = [pivot](const int num) { return num >= pivot; };
        auto ge_ed_it = partition(st_it + 1, ed_it, greater_equal_pivot);
        swap(*st_it, *(ge_ed_it - 1));

        // [   st_it, gt_ed_it): > pivot
        // [gt_ed_it, ge_ed_it]: = pivot
        // [ge_ed_it,    ed_it): < pivot
        auto greater_pivot = [pivot](const int num) { return num > pivot; };
        auto gt_ed_it = partition(st_it, ge_ed_it, greater_pivot);

        const int gt_len = static_cast<int>(distance(st_it, gt_ed_it));
        if (gt_len >= k)
        {
            return findKthLargest_helper(st_it, gt_ed_it, k);
        }
        k -= gt_len;
        const int eq_len = static_cast<int>(distance(gt_ed_it, ge_ed_it));
        if (eq_len < k)
        {
            return findKthLargest_helper(ge_ed_it, ed_it, k - eq_len);
        }
        return pivot;
        */
    }

  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return findKthLargest_helper(nums.begin(), nums.end(), k);

        /*
        auto target_it = nums.begin() + k - 1;
        ranges::nth_element(nums, target_it, greater<>());
        return *target_it;
        */

        /*
        vector<int> heap(k, numeric_limits<int>::min());
        for (const int num : nums)
        {
            ranges::pop_heap(heap, greater<>());
            heap.back() = max(heap.back(), num);
            ranges::push_heap(heap, greater<>());
        }
        return heap.front();
        */

        /*
        vector<int> heap(nums);
        ranges::make_heap(heap, less<>());
        while (--k)
        {
            ranges::pop_heap(heap, less<>());
            heap.pop_back();
        }
        return heap.front();
        */
    }
};
// @lc code=end
