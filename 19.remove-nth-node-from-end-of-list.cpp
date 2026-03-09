/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
#include "19.remove-nth-node-from-end-of-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        unique_ptr<ListNode> sentinel = make_unique<ListNode>(0, head);
        ListNode *slow = sentinel.get();
        ListNode *fast = head; // NOLINT(misc-const-correctness)
        while (n--)
        {
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next; // NOLINT(clang-analyzer-core.NullDereference)
        return sentinel->next;
    }
};
// @lc code=end
