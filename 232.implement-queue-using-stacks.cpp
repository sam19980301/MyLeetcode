/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    stack<int> s_in;
    stack<int> s_out;
public:
    MyQueue():s_in(), s_out() { }
    
    void push(int x) {
        s_in.push(x);
    }
    
    int pop() {
        int front = peek();
        s_out.pop();
        return front;
    }
    
    int peek() {
        if (s_out.empty())
        {
            while (!s_in.empty())
            {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        return s_out.top();
    }
    
    bool empty() { return s_in.empty() && s_out.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

