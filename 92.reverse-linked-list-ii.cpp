/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
#include "92.reverse-linked-list-ii.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // TODO(sam): Review
        unique_ptr<ListNode> sentinel = make_unique<ListNode>(0, head);
        ListNode *prev_left_node = sentinel.get();
        for (int i = 1; i < left; i++)
        {
            prev_left_node = prev_left_node->next;
        }
        ListNode *left_node = prev_left_node->next;

        ListNode *prev = nullptr;
        ListNode *curr = left_node;
        for (int i = left; i < right + 1; i++)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        prev_left_node->next = prev;
        left_node->next = curr;
        return sentinel->next;
    }
};
// @lc code=end
