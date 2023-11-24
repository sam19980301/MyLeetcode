/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void findItinerary_helper(unordered_map<string, vector<string>>& m, string from, vector<string>& ans)
    {

        vector<string>& arr = m[from];
        while (arr.size())
        {
            string to = arr.back();
            arr.pop_back();
            findItinerary_helper(m, to, ans);
        }
        ans.push_back(from);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> m;
        for (vector<string>& ticket : tickets)
            m[ticket[0]].push_back(ticket[1]);
        for (auto& [_, arr] : m)
            sort(arr.begin(), arr.end(), greater<string>());
        vector<string> ans;
        findItinerary_helper(m, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

