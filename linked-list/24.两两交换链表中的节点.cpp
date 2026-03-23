/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (74.98%)
 * Likes:    2580
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
 * 
 * 
 */
#include "listnode.h"

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode dummy(0, head);                                                                             
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* n = prev->next;
            ListNode* nn = prev->next->next;
            prev->next = nn;
            n->next = nn->next;
            nn->next = n;
            prev = n;
        }
        return dummy.next;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({2, 1, 4, 3});
    assert(listsEqual(result, expected));
    std::cout << "Test 1 passed: [1,2,3,4] -> [2,1,4,3]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test2() {
    // 示例 2 - 空链表
    Solution sol;
    ListNode* head = createList({});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({});
    assert(listsEqual(result, expected));
    std::cout << "Test 2 passed: [] -> []" << std::endl;
    deleteList(result); deleteList(expected);
}

void test3() {
    // 示例 3 - 单元素
    Solution sol;
    ListNode* head = createList({1});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({1});
    assert(listsEqual(result, expected));
    std::cout << "Test 3 passed: [1] -> [1]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test4() {
    // 两个元素
    Solution sol;
    ListNode* head = createList({1, 2});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({2, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 4 passed: [1,2] -> [2,1]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test5() {
    // 三个元素 - 奇数长度
    Solution sol;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({2, 1, 3});
    assert(listsEqual(result, expected));
    std::cout << "Test 5 passed: [1,2,3] -> [2,1,3]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test6() {
    // 五个元素 - 奇数长度
    Solution sol;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({2, 1, 4, 3, 5});
    assert(listsEqual(result, expected));
    std::cout << "Test 6 passed: [1,2,3,4,5] -> [2,1,4,3,5]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test7() {
    // 六个元素 - 偶数长度
    Solution sol;
    ListNode* head = createList({1, 2, 3, 4, 5, 6});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({2, 1, 4, 3, 6, 5});
    assert(listsEqual(result, expected));
    std::cout << "Test 7 passed: [1,2,3,4,5,6] -> [2,1,4,3,6,5]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test8() {
    // 相同元素
    Solution sol;
    ListNode* head = createList({1, 1, 1, 1});
    ListNode* result = sol.swapPairs(head);
    ListNode* expected = createList({1, 1, 1, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 8 passed: [1,1,1,1] -> [1,1,1,1]" << std::endl;
    deleteList(result); deleteList(expected);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

