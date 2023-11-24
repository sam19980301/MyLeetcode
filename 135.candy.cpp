/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        
        int sum = 0;
        for (int candy : candies)
            sum += candy;
        return sum;

        // vector<int> candies(ratings.size(), 0);
        // vector<int> arr; // index
        // for (int i = 0; i < ratings.size(); i++)
        //     arr.push_back(i);
        // auto less_index = [&](int a, int b) -> bool { return ratings[a] < ratings[b]; };
        // sort(arr.begin(), arr.end(), less_index);

        // for (int index : arr)
        // {
        //     int candy = 1;
        //     if (index > 0 && ratings[index] > ratings[index-1])
        //         candy = max(candy, candies[index-1] + 1);
        //     if (index < ratings.size() - 1 && ratings[index] > ratings[index+1])
        //         candy = max(candy, candies[index+1] + 1);
        //     candies[index] = candy;
        // }
        // int sum = 0;
        // for (int candy : candies)
        //     sum += candy;
        // return sum;
    }
};
// @lc code=end

