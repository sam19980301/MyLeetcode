/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include "23.merge-k-sorted-lists.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // TODO(sam): Review
        auto greater_listnode = [](const ListNode *lhs, const ListNode *rhs) {
            if (!lhs)
            {
                return true;
            }
            if (!rhs)
            {
                return false;
            }
            return lhs->val > rhs->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(greater_listnode)> q(lists.begin(), lists.end());
        unique_ptr<ListNode> sentinel = make_unique<ListNode>();
        ListNode *curr = sentinel.get();
        while (!q.empty() && q.top())
        {
            ListNode *node = q.top();
            q.pop();
            curr->next = node;
            curr = curr->next;
            q.push(node->next);
        }
        return sentinel->next;
    }
};
// @lc code=end
