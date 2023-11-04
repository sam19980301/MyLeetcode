/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class FreqStack {
private:
    priority_queue<tuple<int, int, int>> heap; // freq, timestamp, value
    unordered_map<int, int> m; // value : count
    int ts;
public:
    FreqStack():heap(), m(), ts(INT_MIN) { }
    
    void push(int val) {
        heap.push({ ++m[val], ts++, val });
    }
    
    int pop() {
        auto [val_freq, val_ts, val] = heap.top();
        heap.pop();
        m[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

