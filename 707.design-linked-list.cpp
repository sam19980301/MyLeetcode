/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyLinkedList
{
  private:
    struct ListNode
    {
        // NOLINTBEGIN(misc-non-private-member-variables-in-classes)
        int value;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        // NOLINTEND(misc-non-private-member-variables-in-classes)
        explicit ListNode(int val) : value(val)
        {
        }
    };

    ListNode *sentinel;
    int size = 0;

    ListNode *get_node(int index)
    {
        if (index >= size)
        {
            return nullptr;
        }
        ListNode *node = sentinel; // NOLINT(misc-const-correctness)
        for (int i = 0; i <= index; i++)
        {
            node = node->next;
        }
        return node;
    }

    void insert(int val, ListNode *node)
    {
        auto *new_node = new ListNode(val); // NOLINT(cppcoreguidelines-owning-memory)
        new_node->next = node;
        new_node->prev = node->prev;

        node->prev->next = new_node;
        node->prev = new_node;
        size++;
    }

  public:
    // TODO(sam): Review
    MyLinkedList() : sentinel(new ListNode(-1))
    {
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    int get(int index)
    {
        const ListNode *node = get_node(index);
        return node ? node->value : -1;
    }

    void addAtHead(int val)
    {
        insert(val, sentinel->next);
    }

    void addAtTail(int val)
    {
        insert(val, sentinel);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }

        if (index == size)
        {
            addAtTail(val);
            return;
        }
        insert(val, get_node(index));
    }

    void deleteAtIndex(int index)
    {
        const ListNode *node = get_node(index);
        if (node)
        {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
