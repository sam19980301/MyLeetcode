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

        unique_ptr<ListNode> sentinel = make_unique<ListNode>();
        ListNode *curr = sentinel.get();
        priority_queue<ListNode *, vector<ListNode *>, decltype(greater_listnode)> q(lists.begin(), lists.end());
        while (!q.empty() && q.top())
        {
            ListNode *node = q.top();
            q.pop();
            curr->next = node;
            curr = curr->next;
            q.push(node->next);
        }
        /*
        ranges::make_heap(lists, greater_listnode);
        while (!lists.empty() && lists.front())
        {
            ranges::pop_heap(lists, greater_listnode);
            ListNode *&node = lists.back();
            curr->next = node;
            curr = curr->next;
            node = node->next;
            ranges::push_heap(lists, greater_listnode);
        }
        */
        return sentinel->next;
    }
};
// @lc code=end
