/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
  private:
    stack<int> ms;
    stack<int> s;

  public:
    MinStack()
    {
        ms.push(numeric_limits<int32_t>::max());
    }

    void push(int val)
    {
        if (val <= ms.top())
        {
            ms.push(val);
        }
        s.push(val);
    }

    void pop()
    {
        if (ms.top() == s.top())
        {
            ms.pop();
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
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
