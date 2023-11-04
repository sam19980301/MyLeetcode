/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> cumsum;
public:
    Solution(vector<int>& w): cumsum(w) {
        for (int i = 1; i < cumsum.size(); i++)
            cumsum[i] += cumsum[i-1];
    }
    
    int pickIndex() {
        int rand_num = rand() % cumsum.back();
        return upper_bound(cumsum.begin(), cumsum.end(), rand_num) - cumsum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

