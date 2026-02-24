/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
#include "876.middle-of-the-linked-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head; // NOLINT(misc-const-correctness)
        const ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end
