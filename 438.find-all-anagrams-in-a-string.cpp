/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 128;

  public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
        {
            return {};
        }

        int unmatched_count = 0; // number of counts elements greater than 0
        array<int, arr_size> counts{};
        for (const char ch : p)
        {
            if (!counts.at(ch)++)
            {
                unmatched_count++;
            }
        }

        vector<int> ans;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (i >= p.size())
            {
                const int prev_count = ++counts.at(s.at(i - p.size()));
                /*
                // unmatched_count refers to number of counts elements not 0 if uncommented
                if (prev_count == 0)
                {
                    unmatched_count--;
                }
                else
                */
                if (prev_count == 1)
                {
                    unmatched_count++;
                }
            }

            const int curr_count = --counts.at(s.at(i));
            if (curr_count == 0)
            {
                unmatched_count--;
            }
            /*
            // unmatched_count refers to number of counts elements not 0 if uncommented
            else if (curr_count == -1)
            {
                unmatched_count++;
            }
            */

            if (!unmatched_count)
            {
                ans.push_back(static_cast<int>(i - p.size()) + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
