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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *sentinel = new ListNode(0, head);
        ListNode *back = sentinel, *front = head;

        while (n--)
            front = front->next;
        
        while (front)
        {
            back = back->next;
            front = front->next;
        }

        back->next = back->next->next;
        return sentinel->next;
    }
};
// @lc code=end

