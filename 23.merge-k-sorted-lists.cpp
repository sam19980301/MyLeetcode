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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto listnode_greater = [](const ListNode* a, const ListNode* b) -> bool {
            return (a ? a->val : INT_MAX) > (b ? b->val : INT_MAX);
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(listnode_greater)> heap(lists.begin(), lists.end());
        
        ListNode *sentinel = new ListNode(), *curr = sentinel;
        while (!heap.empty() && heap.top())
        {
            ListNode *node = heap.top();
            heap.pop();
            heap.push(node->next);
            curr->next = node;
            curr = curr->next;
        }
        return sentinel->next;
    }
};
// @lc code=end

