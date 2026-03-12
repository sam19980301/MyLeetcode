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
#ifdef LEETCODE_LOCAL_DEV
#include "2.add-two-numbers.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr int base = 10;

  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        unique_ptr<ListNode> sentinel = make_unique<ListNode>(0);
        ListNode *curr = sentinel.get();
        int c = 0;
        while (l1 || l2 || c)
        {
            int s = c;
            if (l1)
            {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                s += l2->val;
                l2 = l2->next;
            }

            if (s >= base)
            {
                c = 1;
                s -= base;
            }
            else
            {
                c = 0;
            }
            curr->next = new ListNode(s); // NOLINT(cppcoreguidelines-owning-memory)
            curr = curr->next;
        }
        return sentinel->next;
    }
};
// @lc code=end
