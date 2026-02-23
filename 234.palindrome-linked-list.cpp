/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
#include "234.palindrome-linked-list.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        const ListNode *fast = head;

        // slow: upper-mid node
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // prev: reverse list head for 2nd half (staring from slow)
        ListNode *curr = slow;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // compare
        const ListNode *list1 = head; // 1st half w. upper mid
        const ListNode *list2 = prev; // 2nd half
        while (list2 != nullptr)
        {
            if (list1->val != list2->val)
            {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
};
// @lc code=end
