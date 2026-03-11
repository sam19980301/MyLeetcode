/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
#include "328.odd-even-linked-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *oddEvenList(ListNode *head)
    {
        // TODO(sam): Review
        if (!head)
        {
            return head;
        }
        ListNode *e_head = head->next;
        ListNode *o_node = head;
        ;
        ListNode *e_node = e_head;
        while (e_node && e_node->next)
        {
            o_node->next = e_node->next;
            o_node = o_node->next;
            e_node->next = o_node->next;
            e_node = e_node->next;
        }
        o_node->next = e_head;
        return head;
    }
};
// @lc code=end
