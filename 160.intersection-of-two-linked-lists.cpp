/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
// private:
//     pair<ListNode*, int> reverse_linked_list(ListNode *head)
//     {
//         int cnt = 0;
//         ListNode *curr = head, *prev = nullptr;
//         while (curr)
//         {
//             cnt++;
//             ListNode *next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return { prev, cnt };
//     }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto count_length = [](ListNode *head) -> int {
            int cnt = 0;
            while (head)
            {
                cnt++;
                head = head->next;
            }
            return cnt;
        };
        int cnt_ac = count_length(headA);
        int cnt_bc = count_length(headB);

        int bma = cnt_bc - cnt_ac;
        if (bma < 0)
            swap(headA, headB);
        bma = abs(bma);

        for (int i = 0; i < bma; i++)
            headB = headB->next;
        
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;

        /*
                  a1 -> a2 -> c1 -> c2 -> c3
                              ^
            b1 -> b2 -> b3 ---|

            B + C     = 6
            
            Reverse both lists:
                  a1 -> a2 -> c1 <- c2 <- c3
                              |
            b1 <- b2 <- b3 <--|

            A + C     = 5
            A + B + 1 = 6
        */

        // int cnt_bc = count_length(headB);
        // auto [tailA, cnt_ac] = reverse_linked_list(headA);
        // auto [tailB, cnt_ab] = reverse_linked_list(headB);
        // cnt_ab--;

        // reverse_linked_list(tailB);
        // reverse_linked_list(tailA);
        // if (tailB != headA)
        //     return nullptr;
        
        // int n = (cnt_ab + cnt_ac + cnt_bc) / 2 - cnt_bc;
        // ListNode *node = headA;
        // for (int i = 0; i < n; i++)
        //     node = node->next;
        // return node;
    }
};
// @lc code=end

