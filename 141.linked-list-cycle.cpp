/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#ifdef LEETCODE_LOCAL_DEV
#include "141.linked-list-cycle.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        const ListNode *slow = head;
        const ListNode *fast = head->next;
        while (fast && fast->next && slow != fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow == fast;
    }
};
// @lc code=end
