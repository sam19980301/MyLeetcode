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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *sentinel_o = new ListNode(), *sentinel_e = new ListNode();
        ListNode *curr_o = sentinel_o, *curr_e = sentinel_e;
        while (head && head->next)
        {
            curr_o->next = head;
            curr_o = curr_o->next;
            curr_e->next = head->next;
            curr_e = curr_e->next;
            head = head->next->next;
        }
        if (head)
        {
            curr_o->next = head;
            curr_o = curr_o->next;
        }
        curr_o->next = sentinel_e->next;
        curr_e->next = nullptr;
        return sentinel_o->next;
    }
};
// @lc code=end

