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
#ifdef LEETCODE_LOCAL_DEV
#include "61.rotate-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head /* || !head->next */)
        {
            return head;
        }

        int size = 1;
        ListNode *node = head;
        while (node->next)
        {
            node = node->next;
            size++;
        }
        node->next = head;

        k = size - (k % size);
        ListNode *rotate_tail = head;
        while (--k)
        {
            rotate_tail = rotate_tail->next;
        }

        ListNode *rotate_head = rotate_tail->next; // NOLINT(misc-const-correctness)
        rotate_tail->next = nullptr;
        return rotate_head;

        /*
        int size = 0;
        const ListNode *node = head;
        while (node)
        {
            node = node->next;
            size++;
        }
        if (!head)
        {
            return nullptr;
        }
        k %= size;
        if (!k || size == 1)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while (k--)
        {
            fast = fast->next; // NOLINT(clang-analyzer-core.NullDereference)
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *rotate_head = slow->next; // NOLINT(misc-const-correctness)
        slow->next = nullptr;
        fast->next = head;
        return rotate_head;
        */
    }
};
// @lc code=end
