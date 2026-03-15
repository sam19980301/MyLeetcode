/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
#include "148.sort-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {
        // merge sort
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *slow = head; // lower-mid
        const ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *r = sortList(slow->next);
        slow->next = nullptr;
        ListNode *l = sortList(head);

        unique_ptr<ListNode> sentinel = make_unique<ListNode>();
        ListNode *curr = sentinel.get();
        while (l && r)
        {
            if (l->val < r->val)
            {
                curr->next = l;
                l = l->next;
            }
            else
            {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }
        curr->next = l ? l : r;
        return sentinel->next;
    }
};
// @lc code=end
