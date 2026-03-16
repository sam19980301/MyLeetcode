/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
  private:
    priority_queue<int, vector<int>, less<>> max_heap;    // first half
    priority_queue<int, vector<int>, greater<>> min_heap; // second half

  public:
    MedianFinder()
    {
        max_heap.push(numeric_limits<int>::min());
        min_heap.push(numeric_limits<int>::max());
    }

    void addNum(int num)
    {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if (max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        /*
        auto addNum_helper = [&]() {
            if (max_heap.top() > min_heap.top())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        };
        if (max_heap.size() == min_heap.size())
        {
            max_heap.push(num);
            addNum_helper();
        }
        else // max_heap.size() == min_heap.size() + 1
        {
            min_heap.push(num);
            addNum_helper();
        }
        */
    }

    double findMedian()
    {
        if (max_heap.size() != min_heap.size())
        {
            return max_heap.top();
        }
        return static_cast<double>((max_heap.top() + min_heap.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
