/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*
            A ...x... B ...y... C
                      .         .
                      ...........

            let n step:
                (n - x) % (y + 1) == (2n - x) % (y + 1)
                n % (y + 1) = 0
                n = 0, (y + 1), 2(y + 1), ...
            
            reach at -x % (y + 1)
        */

        ListNode *slow = head, *fast = head;
        bool reach = false;
        while (fast && fast->next && !reach)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                reach = true;
        }
        if (!reach)
            return nullptr;
        
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end

