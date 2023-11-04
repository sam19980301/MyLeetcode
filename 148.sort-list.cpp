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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        // merge sort
        // lower-mid
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l = head, *r = slow->next;
        slow->next = nullptr;
        l = sortList(l);
        r = sortList(r);

        if (l->val < r->val)
        {
            head = l;
            l = l->next;
        }
        else
        {
            head = r;
            r = r->next;
        }

        ListNode *node = head;
        while (l && r)
        {
            if (l->val < r->val)
            {
                node->next = l;
                l = l->next;
            }
            else
            {
                node->next = r;
                r = r->next;
            }
            node = node->next;
        }
        if (l)
            node->next = l;
        else
            node->next = r;
        return head;
    }
};
// @lc code=end

