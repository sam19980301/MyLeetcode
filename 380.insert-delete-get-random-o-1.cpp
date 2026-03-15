/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class RandomizedSet
{
  private:
    vector<int> arr;
    unordered_map<int, size_t> m; // val : array index

  public:
    RandomizedSet() = default;

    bool insert(int val)
    {
        auto [it, success] = m.emplace(val, arr.size());
        if (success)
        {
            arr.push_back(val);
        }
        return success;
    }

    bool remove(int val)
    {
        auto it = m.find(val);
        if (it == m.end())
        {
            return false;
        }
        m[arr.back()] = it->second;
        swap(arr.at(it->second), arr.back());
        arr.pop_back();
        m.erase(it);
        return true;
    }

    int getRandom()
    {
        return arr.at(rand() % arr.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
