/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        // TODO(sam): Review
        /*
            assuming subarray answer is (start, end)
            1. start is 0,        end is 0
            2. start is negative, end is 0
            3. start is 0,        end is negative
        */
        int ans = numeric_limits<int>::min();
        int prod = 1;
        for (auto num : nums)
        {
            prod *= num;
            ans = max(ans, prod);
            if (prod == 0)
            {
                prod = 1;
            }
        }

        prod = 1;
        for (auto num : ranges::reverse_view(nums))
        {
            prod *= num;
            ans = max(ans, prod);
            if (prod == 0)
            {
                prod = 1;
            }
        }
        return ans;

        /*
        int ans = nums.front();
        int max_dp = nums.front();
        int min_dp = nums.front();

        for (auto it = nums.begin() + 1; it != nums.end(); it++)
        {
            const int num = *it;
            const int max_dp_mul_num = max_dp * num;
            const int min_dp_mul_num = min_dp * num;
            const int next_max_dp = max({max_dp_mul_num, min_dp_mul_num, num});
            const int next_min_dp = min({max_dp_mul_num, min_dp_mul_num, num});
            max_dp = next_max_dp;
            min_dp = next_min_dp;
            ans = max(ans, max_dp);
        }
        return ans;
        */

        /*
            max_prod(i) = max{ max_pos_prod(i), for all i }
            max_pos_prod(i) = max(
                max(max_pos_prod(i-1), 1) * nums[i], if nums[i] is positive
                min(max_neg_prod(i-1), 1) * nums[i], otherwise
            )
            max_neg_prod(i) = max(
                min(max_neg_prod(i-1), 1) * nums[i], if nums[i] is positive
                max(max_pos_prod(i-1), 1) * nums[i], otherwise
            )
        */

        /*
        int ans = numeric_limits<int>::min(); // empty subarray is not allowed
        int pos_dp = numeric_limits<int>::min();
        int neg_dp = numeric_limits<int>::max();
        for (const int num : nums)
        {
            const int prev_pos_dp = max(pos_dp, 1);
            const int prev_neg_dp = min(neg_dp, 1);
            pos_dp = (num > 0 ? prev_pos_dp : prev_neg_dp) * num;
            neg_dp = (num > 0 ? prev_neg_dp : prev_pos_dp) * num;
            ans = max(ans, pos_dp);
        }
        return ans;
        */
    }
};
// @lc code=end
