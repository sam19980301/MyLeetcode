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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find lower-mid + 1 : slow
        ListNode *sentinel = new ListNode(0, head);
        ListNode *slow = sentinel, *fast = sentinel;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;

        // reverse from lower-mid + 1
        ListNode *curr = slow, *prev = nullptr;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // check equality of prev & head (excluding mid-node for odd-length ones)
        while (prev)
        {
            if (prev->val != head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

