/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            ans = max{ max_prod(i) }

            max_prod(i) =   max(1, max_prod(i-1)) * num, if num > 0
                            0,                                  = 0
                            min(1, min_prod(i-1)) * num,        < 0
            
            min_prod(i) =   min(1, min_prod(i-1)) * num, if num > 0
                            0,                                  = 0
                            max(1, max_prod(i-1)) * num,        < 0
        */

        int maxprod = nums[0], minprod = nums[0], ans = maxprod;
        for (int i = 1; i < nums.size(); i++)
        {
            int num = nums[i];
            int nextmaxprod = num * (num >= 0 ? max(1, maxprod) : min(1, minprod));
            int nextminprod = num * (num >= 0 ? min(1, minprod) : max(1, maxprod));
            maxprod = nextmaxprod;
            minprod = nextminprod;
            ans = max(ans, maxprod);
        }
        return ans;
    }
};
// @lc code=end

