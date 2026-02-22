/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    template <typename T> using MinHeap = priority_queue<T, vector<T>, greater<>>;

  public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        // TODO(sam): Review
        using Time = int64_t;
        using ActiveMeeting = pair<Time, int>; // end time, room id

        ranges::sort(meetings, less<>{});
        MinHeap<ActiveMeeting> active_meetings;
        vector<int> rooms(n);
        iota(rooms.begin(), rooms.end(), 0);
        MinHeap<int> available_rooms(rooms.begin(), rooms.end());

        vector<int> cnts(n);
        for (auto &meeting : meetings)
        {
            const Time st_t = meeting.front();
            Time ed_t = meeting.back();

            // active meetings end before meeting starts
            while (!active_meetings.empty() && active_meetings.top().first <= st_t)
            {
                auto [_, room_id] = active_meetings.top();
                available_rooms.push(room_id);
                active_meetings.pop();
            }

            // no available room, delay meeting
            if (available_rooms.empty())
            {
                auto [avail_t, room_id] = active_meetings.top();
                available_rooms.push(room_id);
                active_meetings.pop();
                ed_t = avail_t + ed_t - st_t;
            }

            // start meeting
            const int room_id = available_rooms.top();
            active_meetings.emplace(ed_t, room_id);
            available_rooms.pop();
            cnts.at(room_id)++;
        }
        return static_cast<int>(distance(cnts.begin(), ranges::max_element(cnts, less<>{})));
    }
};
// @lc code=end
