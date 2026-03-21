/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
#include "25.reverse-nodes-in-k-group.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int n = k;
        const ListNode *node = head;
        while (node && --n)
        {
            node = node->next;
        }
        if (!node)
        {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;
        n = k;
        while (n--)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
// @lc code=end
