/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    int remained;
    list<pair<int, int>> ls; // key-value pair list
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key : list iterator
public:
    LRUCache(int capacity): remained(capacity), ls(), mp() { }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        ls.push_front({ key, it->second->second });
        ls.erase(it->second);
        it->second = ls.begin();
        return ls.front().second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it == mp.end()) // not found
        {
            if (remained == 0) // no enough capacity
            {
                mp.erase(ls.back().first);
                ls.pop_back();
                remained++;
            }
            ls.push_front({ key, value });
            mp.insert({ key, ls.begin() });
            remained--;
        }
        else // found
        {
            ls.erase(it->second);
            ls.push_front({ key, value });
            it->second = ls.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

