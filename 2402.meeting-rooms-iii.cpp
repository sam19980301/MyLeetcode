/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        using pr = pair<long, int>; // endtime, room no
        priority_queue<pr, vector<pr>, greater<pr>> ongoing_meetings;

        priority_queue<int, vector<int>, greater<int>> available_rooms;
        for (int i = 0; i < n; i++)
            available_rooms.push(i);
        
        vector<int> cnts(n, 0);
        pair<int, int> ans = { 0, 0 }; // count, negative room no
        for (vector<int>& meeting : meetings)
        {
            long start_time = meeting[0], end_time = meeting[1];
            while (!ongoing_meetings.empty() && ongoing_meetings.top().first <= start_time)
            {
                available_rooms.push(ongoing_meetings.top().second);
                ongoing_meetings.pop();
            }

            if (available_rooms.empty())
            {
                end_time += ongoing_meetings.top().first - start_time;
                // start_time = ongoing_meetings.top().first;
                available_rooms.push(ongoing_meetings.top().second);
                ongoing_meetings.pop();
            }

            ongoing_meetings.push({ end_time, available_rooms.top() });
            ans = max(ans, { ++cnts[available_rooms.top()], -available_rooms.top() });
            available_rooms.pop();
        }
        return -ans.second;
    }
};
// @lc code=end

