/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        
        ListNode *sentinel = new ListNode(0, head), *curr = sentinel;
        int count = 0;
        while (curr->next)
        {
            count++;
            curr = curr->next;
        }
        curr->next = sentinel->next;
        
        k = count - k % count;
        for (int i = 0; i < k; i++)
            curr = curr->next;
        ListNode *ans = curr->next;
        curr->next = nullptr;
        return ans;
    }
};
// @lc code=end

