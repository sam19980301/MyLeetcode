/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        ListNode *sentinel = new ListNode(0, head), *slow = sentinel, *fast = sentinel;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse
        ListNode *curr = slow->next, *prev = nullptr;
        slow->next = nullptr;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // interleave head and prev
        while (prev)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = prev->next;
            head->next->next = next;
            head = head->next->next;
        }
    }
};
// @lc code=end

