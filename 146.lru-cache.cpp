/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
  private:
    using PairInt = pair<int, int>; // key, value
    using List = list<PairInt>;
    size_t capacity;
    List ls;
    unordered_map<int /* key */, List::iterator> mp;

  public:
    explicit LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        auto mp_it = mp.find(key);
        if (mp_it == mp.end())
        {
            return -1;
        }
        auto ls_it = mp_it->second;
        ls.splice(ls.begin(), ls, ls_it);
        return ls_it->second;
    }

    void put(int key, int value)
    {
        auto mp_it = mp.find(key);
        if (mp_it == mp.end())
        {
            if (ls.size() == capacity)
            {
                const int lsu_key = ls.back().first;
                ls.pop_back();
                mp.erase(lsu_key);
            }
            ls.emplace_front(key, value);
            mp.emplace(key, ls.begin());
        }
        else
        {
            auto ls_it = mp_it->second;
            ls_it->second = value;
            ls.splice(ls.begin(), ls, ls_it);
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
