/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyHashSet
{
  private:
    using Element = int;
    static constexpr uint32_t prime = 7919;
    static constexpr uint32_t bits = 8;
    array<list<Element>, 1U << bits> table{};

    pair<list<Element> &, list<Element>::iterator> find_key(int key)
    {
        auto &ls = table.at((static_cast<uint32_t>(key) * prime) & ((1U << bits) - 1));
        auto it = ranges::find_if(ls, [&key](Element &data) { return data == key; });
        return {ls, it};
    }

  public:
    // TODO(sam): Review
    MyHashSet() = default;

    void add(int key)
    {
        auto [ls, it] = find_key(key);
        if (it == ls.end())
        {
            ls.push_back(key);
        }
    }

    void remove(int key)
    {
        auto [ls, it] = find_key(key);
        if (it != ls.end())
        {
            ls.erase(it);
        }
    }

    bool contains(int key)
    {
        auto [ls, it] = find_key(key);
        return it != ls.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
