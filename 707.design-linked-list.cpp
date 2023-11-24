/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyLinkedList {
private:
    struct ListNode
    {
        int value;
        ListNode* next;
        ListNode* prev;
        ListNode(int v = 0, ListNode *n = nullptr, ListNode *p = nullptr): value(v), next(n), prev(p) { }
    };

    /*
        sentinel -- head -- ... -- tail
            |                       |
            -------------------------
    */
    ListNode *sentinel;

    void add(ListNode *node, int val) // add new with value val after node
    {
        ListNode *newnode = new ListNode(val, node->next, node);
        node->next->prev = newnode;
        node->next = newnode;
    }

    ListNode* get_node(int index) // n-th node not considering sentinel (0-indexed)
    {
        ListNode *node = sentinel;
        for (int i = 0; i <= index; i++)
        {
            if (node->next == sentinel)
                return nullptr;
            node = node->next;
        }
        return node;
    }

public:
    MyLinkedList():sentinel(new ListNode()) { sentinel->next = sentinel->prev = sentinel; }
    
    int get(int index) {
        ListNode *node = get_node(index);
        return (!node) ? -1 : node->value;
    }
    
    void addAtHead(int val) {
        add(sentinel, val);
    }
    
    void addAtTail(int val) {
        add(sentinel->prev, val);
    }
    
    void addAtIndex(int index, int val) {
        ListNode *node = get_node(index - 1);
        if (!node)
            return ;
        add(node, val);
    }
    
    void deleteAtIndex(int index) {
        ListNode *node = get_node(index);
        if (!node)
            return ;
        node->prev->next = node->next;
        node->next->prev = node->prev;
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

