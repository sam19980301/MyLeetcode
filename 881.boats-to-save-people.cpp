/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        // TODO(sam): Review
        ranges::sort(people, less<>());
        int boat = 0;
        auto l_it = people.begin();
        auto r_it = people.end();
        while (l_it < r_it)
        {
            boat++;
            if (*l_it + *--r_it <= limit)
            {
                l_it++;
            }
        }
        return boat;
        
        /*
        map<int, int> m; // weight: count
        for (const int w : people)
        {
            m[w]++;
        }

        int boat = 0;
        while (!m.empty())
        {
            boat++;
            auto it_1 = --m.end();
            auto &[_, count1] = *it_1;
            const int w1 = it_1->first;
            if (!--count1)
            {
                m.erase(it_1);
            }
            auto it_2 = m.upper_bound(limit - w1);
            if (it_2 != m.begin())
            {
                auto &[w2, count2] = *--it_2;
                if (!--count2)
                {
                    m.erase(it_2);
                }
            }
        }
        return boat;
        */
    }
};
// @lc code=end
