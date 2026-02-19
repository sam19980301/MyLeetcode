/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
#include "21.merge-two-sorted-lists.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        unique_ptr<ListNode> sentinel = make_unique<ListNode>(std::numeric_limits<int>::min());
        ListNode *curr = sentinel.get();
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1)
            curr->next = list1;
        if (list2)
            curr->next = list2;
        return sentinel->next;
    }
};
// @lc code=end
