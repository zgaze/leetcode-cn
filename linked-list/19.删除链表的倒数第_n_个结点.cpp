/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (52.98%)
 * Likes:    3287
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 3.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        //d->1-2-3-4-5-n
        //s    f
        //       s   f

        //s          f
        //s          f

        //s  f
        //        s  f
        while(n && fast) {
            n --;
            fast = fast->next;
        }
        if (fast == nullptr) {

        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        //ListNode* next = slow->next;
        slow->next = slow->next->next;
        return dummy.next;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = sol.removeNthFromEnd(head, 2);
    ListNode* expected = createList({1, 2, 3, 5});
    assert(listsEqual(result, expected));
    std::cout << "Test 1 passed: [1,2,3,4,5] n=2 -> [1,2,3,5]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test2() {
    // 示例 2 - 单元素删除
    Solution sol;
    ListNode* head = createList({1});
    ListNode* result = sol.removeNthFromEnd(head, 1);
    ListNode* expected = createList({});
    assert(listsEqual(result, expected));
    std::cout << "Test 2 passed: [1] n=1 -> []" << std::endl;
    deleteList(result); deleteList(expected);
}

void test3() {
    // 示例 3 - 两元素删除末尾
    Solution sol;
    ListNode* head = createList({1, 2});
    ListNode* result = sol.removeNthFromEnd(head, 1);
    ListNode* expected = createList({1});
    assert(listsEqual(result, expected));
    std::cout << "Test 3 passed: [1,2] n=1 -> [1]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test4() {
    // 删除头节点
    Solution sol;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = sol.removeNthFromEnd(head, 3);
    ListNode* expected = createList({2, 3});
    assert(listsEqual(result, expected));
    std::cout << "Test 4 passed: [1,2,3] n=3 -> [2,3]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test5() {
    // 删除尾节点
    Solution sol;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = sol.removeNthFromEnd(head, 1);
    ListNode* expected = createList({1, 2});
    assert(listsEqual(result, expected));
    std::cout << "Test 5 passed: [1,2,3] n=1 -> [1,2]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test6() {
    // 两元素删除第一个
    Solution sol;
    ListNode* head = createList({1, 2});
    ListNode* result = sol.removeNthFromEnd(head, 2);
    ListNode* expected = createList({2});
    assert(listsEqual(result, expected));
    std::cout << "Test 6 passed: [1,2] n=2 -> [2]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test7() {
    // 较长链表删除中间
    Solution sol;
    ListNode* head = createList({1, 2, 3, 4, 5, 6, 7});
    ListNode* result = sol.removeNthFromEnd(head, 4);
    ListNode* expected = createList({1, 2, 3, 5, 6, 7});
    assert(listsEqual(result, expected));
    std::cout << "Test 7 passed: [1,2,3,4,5,6,7] n=4 -> [1,2,3,5,6,7]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test8() {
    // 相同元素
    Solution sol;
    ListNode* head = createList({5, 5, 5, 5});
    ListNode* result = sol.removeNthFromEnd(head, 2);
    ListNode* expected = createList({5, 5, 5});
    assert(listsEqual(result, expected));
    std::cout << "Test 8 passed: [5,5,5,5] n=2 -> [5,5,5]" << std::endl;
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

