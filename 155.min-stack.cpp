/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<int> s;
    stack<int> ms; // non ascending stack
public:
    MinStack():s(), ms() {
        s.push(INT_MAX);
        ms.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        if (ms.top() >= val)
            ms.push(val);
    }
    
    void pop() {
        if (ms.top() == s.top())
            ms.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

