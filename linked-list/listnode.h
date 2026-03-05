#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>
#include <cstdio>

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 创建链表（从 vector）
inline ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// 释放链表
inline void deleteList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

// 比较两个链表是否相等
inline bool listsEqual(ListNode* a, ListNode* b) {
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return a == nullptr && b == nullptr;
}

// 打印链表
inline void printList(ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]");
}

// 打印链表（换行）
inline void printListWithNewline(ListNode* head) {
    printList(head);
    printf("\n");
}

// 获取链表长度
inline int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

#endif // LISTNODE_H
