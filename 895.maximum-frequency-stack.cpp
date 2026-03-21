/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class FreqStack
{
  private:
    int max_freq = 0;
    unordered_map<int, int> m_value_freq;        // value : count
    unordered_map<int, stack<int>> m_freq_stack; // count: stack

    /*
    using Tuple = tuple<int, int, int>; // count, timestamp, value
    int timestamp = 0;
    unordered_map<int, int> m; // value : count
    set<Tuple> s;              // element tuple
    */

  public:
    FreqStack() = default;

    void push(int val)
    {
        const int freq = ++m_value_freq[val];
        max_freq = max(max_freq, freq);
        m_freq_stack[freq].push(val);
        /*
        s.emplace(++m[val], timestamp++, val);
        */
    }

    int pop()
    {
        auto &s = m_freq_stack[max_freq];
        const int val = s.top();
        s.pop();
        m_value_freq[val]--;
        if (s.empty())
        {
            max_freq--;
        }
        return val;
        /*
        auto it = --s.end();
        auto [count, timestamp, val] = *it;
        s.erase(it);
        m[val]--;
        return val;
        */
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
