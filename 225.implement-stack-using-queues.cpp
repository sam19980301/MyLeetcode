/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
  private:
    queue<int> q;

  public:
    // TODO(sam): Review
    MyStack() = default;

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        size_t qs = q.size();
        while (--qs)
        {
            q.push(q.front());
            q.pop();
        }
        const int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        const int x = pop();
        q.push(x);
        return x;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
