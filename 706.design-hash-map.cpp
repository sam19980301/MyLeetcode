/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
  private:
    using Element = pair<int, int>;
    static constexpr uint32_t prime = 7919;
    static constexpr uint32_t bits = 8;
    array<list<Element>, 1U << bits> table{};

    pair<list<Element> &, list<Element>::iterator> find_key(int key)
    {
        auto &ls = table.at((static_cast<uint32_t>(key) * prime) & ((1U << bits) - 1));
        auto it = ranges::find_if(ls, [&key](Element &pair) { return pair.first == key; });
        return {ls, it};
    }

  public:
    MyHashMap() = default;

    void put(int key, int value)
    {
        auto [ls, it] = find_key(key);
        if (it == ls.end())
        {
            ls.emplace_back(key, value);
        }
        else
        {
            it->second = value;
        }
    }

    int get(int key)
    {
        auto [ls, it] = find_key(key);
        if (it == ls.end())
        {
            return -1;
        }
        return it->second;
    }

    void remove(int key)
    {
        auto [ls, it] = find_key(key);
        if (it != ls.end())
        {
            ls.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
