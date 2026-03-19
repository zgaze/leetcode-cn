/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (68.14%)
 * Likes:    3989
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
 * 
 */
#include "listnode.h"
// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode head;
        ListNode* curr = &head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        while(list1) {
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
        }
        while(list2) {
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        }
        return head.next;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({1, 1, 2, 3, 4, 4});
    assert(listsEqual(result, expected));
    std::cout << "Test 1 passed: [1,2,4]+[1,3,4]=[1,1,2,3,4,4]" << std::endl;
    // result 的节点来自 l1 和 l2 的拼接，只释放 result 和 expected
    deleteList(result); deleteList(expected);
}

void test2() {
    // 示例 2 - 两个空链表
    Solution sol;
    ListNode* l1 = createList({});
    ListNode* l2 = createList({});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({});
    assert(listsEqual(result, expected));
    std::cout << "Test 2 passed: []+[]=[]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test3() {
    // 示例 3 - 一个空链表
    Solution sol;
    ListNode* l1 = createList({});
    ListNode* l2 = createList({0});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({0});
    assert(listsEqual(result, expected));
    std::cout << "Test 3 passed: []+[0]=[0]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test4() {
    // 两个单元素链表
    Solution sol;
    ListNode* l1 = createList({1});
    ListNode* l2 = createList({2});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({1, 2});
    assert(listsEqual(result, expected));
    std::cout << "Test 4 passed: [1]+[2]=[1,2]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test5() {
    // 不同长度
    Solution sol;
    ListNode* l1 = createList({1, 3, 5});
    ListNode* l2 = createList({2, 4});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({1, 2, 3, 4, 5});
    assert(listsEqual(result, expected));
    std::cout << "Test 5 passed: different lengths" << std::endl;
    deleteList(result); deleteList(expected);
}

void test6() {
    // 有重叠元素
    Solution sol;
    ListNode* l1 = createList({1, 1, 1});
    ListNode* l2 = createList({1, 1, 1});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({1, 1, 1, 1, 1, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 6 passed: overlapping elements" << std::endl;
    deleteList(result); deleteList(expected);
}

void test7() {
    // 负数
    Solution sol;
    ListNode* l1 = createList({-5, -3, 0});
    ListNode* l2 = createList({-4, -2, 1});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({-5, -4, -3, -2, 0, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 7 passed: negative numbers" << std::endl;
    deleteList(result); deleteList(expected);
}

void test8() {
    // l1 全部小于 l2
    Solution sol;
    ListNode* l1 = createList({1, 2, 3});
    ListNode* l2 = createList({4, 5, 6});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({1, 2, 3, 4, 5, 6});
    assert(listsEqual(result, expected));
    std::cout << "Test 8 passed: l1 all smaller than l2" << std::endl;
    deleteList(result); deleteList(expected);
}

void test9() {
    // l2 全部小于 l1
    Solution sol;
    ListNode* l1 = createList({4, 5, 6});
    ListNode* l2 = createList({1, 2, 3});
    ListNode* result = sol.mergeTwoLists(l1, l2);
    ListNode* expected = createList({1, 2, 3, 4, 5, 6});
    assert(listsEqual(result, expected));
    std::cout << "Test 9 passed: l2 all smaller than l1" << std::endl;
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
    test9();

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

