/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        int cnt = 1;
        visited[0] = true;
        q.push(0);
        while (!q.empty() && cnt != rooms.size())
        {
            int room = q.front();
            q.pop();
            for (int key : rooms[room])
            {
                if (!visited[key])
                {
                    visited[key] = true;
                    cnt++;
                    q.push(key);
                }
            }
        }
        return cnt == rooms.size();
    }
};
// @lc code=end

