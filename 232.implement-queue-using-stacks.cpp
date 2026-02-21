/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
  private:
    stack<int> s_i;
    stack<int> s_o;

  public:
    MyQueue() = default;

    void push(int x)
    {
        s_i.push(x);
    }

    int pop()
    {
        const int value = peek();
        s_o.pop();
        return value;
    }

    int peek()
    {
        if (s_o.empty())
        {
            while (!s_i.empty())
            {
                s_o.push(s_i.top());
                s_i.pop();
            }
        }
        return s_o.top();
    }

    bool empty()
    {
        return s_i.empty() && s_o.empty();
    }
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
