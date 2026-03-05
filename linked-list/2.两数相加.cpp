/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (46.50%)
 * Likes:    11811
 * Dislikes: 0
 * Total Accepted:    2.7M
 * Total Submissions: 5.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */
#include "listnode.h"
// @lc code=start
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* idx = head;
        int flag = 0;
        while (l1 && l2) {
            int n = l1->val + l2->val + flag;
            flag = n / 10;
            idx->next = new ListNode(n % 10);
            idx = idx->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int n = l1->val  + flag;
            flag = n / 10;
            idx->next = new ListNode(n % 10);
            idx = idx->next;
            l1 = l1->next;
        }
        while (l2) {
            int n = l2->val  + flag;
            flag = n / 10;
            idx->next = new ListNode(n % 10);
            idx = idx->next;
            l2 = l2->next;
        }
        if (flag) {
            idx->next = new ListNode(flag);
        }

        return head->next;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({7, 0, 8});
    assert(listsEqual(result, expected));
    std::cout << "Test 1 passed: [2,4,3]+[5,6,4]=[7,0,8]" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

void test2() {
    // 示例 2 - 单节点
    Solution sol;
    ListNode* l1 = createList({0});
    ListNode* l2 = createList({0});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({0});
    assert(listsEqual(result, expected));
    std::cout << "Test 2 passed: [0]+[0]=[0]" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

void test3() {
    // 示例 3 - 进位到最高位
    Solution sol;
    ListNode* l1 = createList({9, 9, 9, 9, 9, 9, 9});
    ListNode* l2 = createList({9, 9, 9, 9});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({8, 9, 9, 9, 0, 0, 0, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 3 passed: large carry case" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

void test4() {
    // 不同长度，无进位
    Solution sol;
    ListNode* l1 = createList({1, 2, 3});
    ListNode* l2 = createList({4, 5});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({5, 7, 3});
    assert(listsEqual(result, expected));
    std::cout << "Test 4 passed: different lengths" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

void test5() {
    // l1 比 l2 短
    Solution sol;
    ListNode* l1 = createList({5});
    ListNode* l2 = createList({5, 5, 5});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({0, 6, 5});
    assert(listsEqual(result, expected));
    std::cout << "Test 5 passed: l1 shorter than l2" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

void test6() {
    // 连续进位
    Solution sol;
    ListNode* l1 = createList({9, 9, 9});
    ListNode* l2 = createList({1});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({0, 0, 0, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 6 passed: continuous carry" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

void test7() {
    // 一个为空（理论上不会出现，但测试边界）
    Solution sol;
    ListNode* l1 = createList({1, 2});
    ListNode* l2 = createList({});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    ListNode* expected = createList({1, 2});
    assert(listsEqual(result, expected));
    std::cout << "Test 7 passed: one empty list" << std::endl;
    deleteList(l1); deleteList(l2); deleteList(result); deleteList(expected);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    //test7();

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

