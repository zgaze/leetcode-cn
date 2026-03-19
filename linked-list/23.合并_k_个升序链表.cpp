/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (63.38%)
 * Likes:    3169
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */
#include "listnode.h"
#include <vector>
using std::vector;
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
    ListNode* mergeKLists(vector<ListNode*>& lists, int begin, int end) {
        if (begin == end) {
            return lists[begin];
        } else if (begin == end - 1) {
            return mergeTwoLists(lists[begin], lists[end]);
        }
        int mid = (begin + end) / 2;
        ListNode* l = mergeKLists(lists, begin, mid);
        ListNode* r = mergeKLists(lists, mid+1, end);
        return mergeTwoLists(l, r);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeKLists(lists, 0, lists.size()-1);
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };
    ListNode* result = sol.mergeKLists(lists);
    ListNode* expected = createList({1, 1, 2, 3, 4, 4, 5, 6});
    assert(listsEqual(result, expected));
    std::cout << "Test 1 passed: [[1,4,5],[1,3,4],[2,6]]" << std::endl;
    deleteList(result); deleteList(expected);
}

void test2() {
    // 示例 2 - 空数组
    Solution sol;
    vector<ListNode*> lists = {};
    ListNode* result = sol.mergeKLists(lists);
    assert(result == nullptr);
    std::cout << "Test 2 passed: [] -> nullptr" << std::endl;
}

void test3() {
    // 示例 3 - 包含空链表
    Solution sol;
    vector<ListNode*> lists = {
        createList({})
    };
    ListNode* result = sol.mergeKLists(lists);
    assert(result == nullptr);
    std::cout << "Test 3 passed: [[]] -> nullptr" << std::endl;
    deleteList(result);
}

void test4() {
    // 单个链表
    Solution sol;
    vector<ListNode*> lists = {
        createList({1, 2, 3})
    };
    ListNode* result = sol.mergeKLists(lists);
    ListNode* expected = createList({1, 2, 3});
    assert(listsEqual(result, expected));
    std::cout << "Test 4 passed: single list" << std::endl;
    deleteList(result); deleteList(expected);
}

void test5() {
    // 两个链表
    Solution sol;
    vector<ListNode*> lists = {
        createList({1, 3, 5}),
        createList({2, 4, 6})
    };
    ListNode* result = sol.mergeKLists(lists);
    ListNode* expected = createList({1, 2, 3, 4, 5, 6});
    assert(listsEqual(result, expected));
    std::cout << "Test 5 passed: two lists" << std::endl;
    deleteList(result); deleteList(expected);
}

void test6() {
    // 多个空链表
    Solution sol;
    vector<ListNode*> lists = {
        createList({}),
        createList({}),
        createList({})
    };
    ListNode* result = sol.mergeKLists(lists);
    assert(result == nullptr);
    std::cout << "Test 6 passed: multiple empty lists" << std::endl;
}

void test7() {
    // 包含负数
    Solution sol;
    vector<ListNode*> lists = {
        createList({-5, -3, 0}),
        createList({-4, -2, 1}),
        createList({-6, -1, 2})
    };
    ListNode* result = sol.mergeKLists(lists);
    ListNode* expected = createList({-6, -5, -4, -3, -2, -1, 0, 1, 2});
    assert(listsEqual(result, expected));
    std::cout << "Test 7 passed: with negative numbers" << std::endl;
    deleteList(result); deleteList(expected);
}

void test8() {
    // 所有元素相同
    Solution sol;
    vector<ListNode*> lists = {
        createList({1, 1}),
        createList({1, 1}),
        createList({1, 1})
    };
    ListNode* result = sol.mergeKLists(lists);
    ListNode* expected = createList({1, 1, 1, 1, 1, 1});
    assert(listsEqual(result, expected));
    std::cout << "Test 8 passed: all same elements" << std::endl;
    deleteList(result); deleteList(expected);
}

void test9() {
    // 一个链表很长
    Solution sol;
    vector<ListNode*> lists = {
        createList({1, 2, 3, 4, 5}),
        createList({10}),
        createList({6, 7})
    };
    ListNode* result = sol.mergeKLists(lists);
    ListNode* expected = createList({1, 2, 3, 4, 5, 6, 7, 10});
    assert(listsEqual(result, expected));
    std::cout << "Test 9 passed: one long list" << std::endl;
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

