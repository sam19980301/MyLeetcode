/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums;
        }
        if (nums.size() == 3)
        {
            const int num_0 = nums.at(0);
            const int num_1 = nums.at(1);
            const int num_2 = nums.at(2);
            if (num_0 == num_1 || num_0 == num_2)
            {
                return {num_0};
            }
            if (num_1 == num_2)
            {
                return {num_1};
            }
            return {};
        }

        const int index_1 = (((static_cast<int>(nums.size()) / 3) + 1) * 1) - 1;
        ranges::nth_element(nums, nums.begin() + index_1, less<>());
        const int m1 = *(nums.begin() + index_1);

        const int index_2 = (((static_cast<int>(nums.size()) / 3) + 1) * 2) - 1;
        ranges::nth_element(nums, nums.begin() + index_2, less<>());
        const int m2 = *(nums.begin() + index_2);
        int count1 = 0;
        int count2 = 0;
        vector<int> ans;
        for (const int num : nums)
        {
            if (num == m1)
            {
                count1++;
            }
            if (num == m2)
            {
                count2++;
            }
        }

        if (cmp_greater(count1, nums.size() / 3))
        {
            ans.push_back(m1);
        }
        if (cmp_greater(count2, nums.size() / 3))
        {
            if (ans.empty() || ans.front() != m2)
            {
                ans.push_back(m2);
            }
        }
        return ans;

        /*
        int m1 = numeric_limits<int>::min();
        int m2 = numeric_limits<int>::min();
        int count1 = 0;
        int count2 = 0;
        for (const int num : nums)
        {
            if (m1 == num)
            {
                count1++;
            }
            else if (m2 == num)
            {
                count2++;
            }
            else if (!count1)
            {
                m1 = num;
                count1++;
            }
            else if (!count2)
            {
                m2 = num;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for (const int num : nums)
        {
            if (num == m1)
            {
                count1++;
            }
            if (num == m2)
            {
                count2++;
            }
        }
        if (cmp_greater(count1, nums.size() / 3))
        {
            ans.push_back(m1);
        }
        if (cmp_greater(count2, nums.size() / 3))
        {
            ans.push_back(m2);
        }
        return ans;
        */
    }
};
// @lc code=end
