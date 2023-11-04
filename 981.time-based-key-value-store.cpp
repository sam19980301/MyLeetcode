/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class TimeMap {
private:
    unordered_map<string, map<int, string>> m; // key : { ts : value }
public:
    TimeMap():m() { }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int, string>& subm = m[key];
        auto it = subm.upper_bound(timestamp);
        if (it == subm.begin())
            return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

