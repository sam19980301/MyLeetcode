/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(
            people.begin(),
            people.end(),
            [](vector<int>& a, vector<int>& b) -> bool {
                if (a[0] != b[0])
                    return a[0] < b[0];
                return a[1] > b[1];
            }
        );

        for (int i = people.size() - 1; i >= 0; i--)
        {
            int j = i, cnt = people[i][1];
            for (int k = 0; k < cnt; k++)
            {
                swap(people[j], people[j+1]);
                j++;
            }
        }
        return people;
    }
};
// @lc code=end

