/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    /*
        Notes: types of relation between intervals

        1. 
            [   ]
                  [   ]
        2.
            [   ]
              [   ]
        3. 
              [   ]
            [   ]
        4. 
                  [   ]
            [   ]
        
        overlap(p, q) = ! non_overlap(p, q) = ! ( p[1] < q[0] || q[1] < p[0] ) ( De Morgan's laws )
        bool overlap(vector<int>& p, vector<int>q ) { return (p[1] >= q[0]) && (q[1] >= p[0]); }
    */
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        /*
            newInterval:        -----
            interval:       ^    ^      ^
                            |    |      |
                            1.   2.     3.
        */
        
        vector<vector<int>> ans;
        auto it = intervals.begin();

        // 1. 
        while (it != intervals.end() && (*it)[1] < newInterval[0])
            ans.push_back(*it++);
        // 2.
        while (it != intervals.end() && newInterval[1] >= (*it)[0])
        {
            newInterval[0] = min(newInterval[0], (*it)[0]);
            newInterval[1] = max(newInterval[1], (*it)[1]);
            it++;
        }
        ans.push_back(newInterval);
        // 3.
        while (it != intervals.end())
            ans.push_back(*it++);
        return ans;
    }
};
// @lc code=end

