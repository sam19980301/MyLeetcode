/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sentinel = new ListNode(), *curr = sentinel;
        int n = 0;
        while (l1 || l2)
        {
            if (l1)
            {
                n += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                n += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(n%10);
            curr = curr->next;
            n /= 10;
        }
        if (n)
            curr->next = new ListNode(n);
        return sentinel->next;
    }
};
// @lc code=end

