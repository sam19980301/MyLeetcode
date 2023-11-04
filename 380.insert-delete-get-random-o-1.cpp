/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> m; // value : index of arr
public:
    RandomizedSet(): arr(), m() { }
    
    bool insert(int val) {
        if (!m.insert({ val, arr.size() }).second)
            return false;
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end())
            return false;
        m[arr.back()] = it->second;
        arr[it->second] = arr.back();
        arr.pop_back();
        m.erase(it);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
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

