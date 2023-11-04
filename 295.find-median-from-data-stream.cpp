/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> small_heap; // including median
    priority_queue<int> large_heap; // excluding median (in negative symbol)
public:
    MedianFinder():small_heap(), large_heap() {
        small_heap.push(INT_MIN);
        large_heap.push(-INT_MAX);
    }
    
    void addNum(int num) {
        bool same_size = small_heap.size() == large_heap.size();
        priority_queue<int>& incr_heap = same_size ? small_heap : large_heap;
        priority_queue<int>& same_heap = same_size ? large_heap : small_heap;
        num = same_size ? num : -num;
        
        if (num < -same_heap.top())
        {
            incr_heap.push(num);
        }
        else
        {
            incr_heap.push(-same_heap.top());
            same_heap.pop();
            same_heap.push(-num);
        }
    }
    
    double findMedian() {
        if (small_heap.size() != large_heap.size())
            return small_heap.top();
        return ((double) small_heap.top() - large_heap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

