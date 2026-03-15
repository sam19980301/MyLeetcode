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
#ifdef LEETCODE_LOCAL_DEV
#include "143.reorder-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void reorderList(ListNode *head)
    {
        // slow: lower mid
        ListNode *slow = head;
        const ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // reorder
        ListNode *node_0 = head;
        ListNode *node_1 = prev;
        while (/* node_0 && */ node_1)
        {
            ListNode *node_0_next = node_0->next;
            ListNode *node_1_next = node_1->next;
            node_0->next = node_1;
            node_1->next = node_0_next;
            node_0 = node_0_next;
            node_1 = node_1_next;
        }
    }
};
// @lc code=end
