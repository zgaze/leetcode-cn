/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 *
 * https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (68.13%)
 * Likes:    2898
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.1M
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3'
 *
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
 * 
 * 图示两个链表在节点 c1 开始相交：
 * 
 * 
 * 
 * 题目数据 保证 整个链式结构中不存在环。
 * 
 * 注意，函数返回结果后，链表必须 保持其原始结构 。
 * 
 * 自定义评测：
 * 
 * 评测系统 的输入如下（你设计的程序 不适用 此输入）：
 * 
 * 
 * intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
 * listA - 第一个链表
 * listB - 第二个链表
 * skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
 * skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
 * 
 * 
 * 评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被
 * 视作正确答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2,
 * skipB = 3
 * 输出：Intersected at '8'
 * 解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
 * 从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
 * 在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 * — 请注意相交节点的值不为 1，因为在链表 A 和链表 B 之中值为 1 的节点 (A 中第二个节点和 B 中第三个节点)
 * 是不同的节点。换句话说，它们在内存中指向两个不同的位置，而链表 A 和链表 B 中值为 8 的节点 (A 中第三个节点，B 中第四个节点)
 * 在内存中指向相同的位置。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
 * = 1
 * 输出：Intersected at '2'
 * 解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
 * 从各自的表头开始算起，链表 A 为 [1,9,1,2,4]，链表 B 为 [3,2,4]。
 * 在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：No intersection
 * 解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
 * 由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 * 这两个链表不相交，因此返回 null 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * listA 中节点数目为 m
 * listB 中节点数目为 n
 * 1 <= m, n <= 3 * 10^4
 * 1 <= Node.val <= 10^5
 * 0 <= skipA <= m
 * 0 <= skipB <= n
 * 如果 listA 和 listB 没有交点，intersectVal 为 0
 * 如果 listA 和 listB 有交点，intersectVal == listA[skipA] == listB[skipB]
 * 
 * 
 * 
 * 
 * 进阶：你能否设计一个时间复杂度 O(m + n) 、仅用 O(1) 内存的解决方案？
 * 
 */
#include "listnode.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};
// @lc code=end

// =============== 单元测试 ===============

#include <cassert>
#include <iostream>
#include <utility>

// 辅助函数：创建相交链表
// listA: 链表A的节点值（交点之前）
// listB: 链表B的节点值（交点之前）
// common: 公共部分节点值
// 返回 pair<headA, headB>
std::pair<ListNode*, ListNode*> createIntersectingLists(
    const std::vector<int>& listA,
    const std::vector<int>& listB,
    const std::vector<int>& common
) {
    ListNode* commonHead = createList(common);

    ListNode* headA = createList(listA);
    ListNode* tailA = headA;
    while (tailA && tailA->next) {
        tailA = tailA->next;
    }
    if (tailA) {
        tailA->next = commonHead;
    } else {
        headA = commonHead;
    }

    ListNode* headB = createList(listB);
    ListNode* tailB = headB;
    while (tailB && tailB->next) {
        tailB = tailB->next;
    }
    if (tailB) {
        tailB->next = commonHead;
    } else {
        headB = commonHead;
    }

    return std::make_pair(headA, headB);
}

// 辅助函数：释放相交链表（只释放公共部分一次）
void deleteIntersectingLists(ListNode* headA, ListNode* headB, ListNode* intersection) {
    ListNode* cur = headA;
    while (cur && cur != intersection) {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }
    cur = headB;
    while (cur && cur != intersection) {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }
    deleteList(intersection);
}

void testIntersectionExists1() {
    std::cout << "测试用例1: 两个链表有交点 - 示例1" << std::endl;
    std::pair<ListNode*, ListNode*> lists = createIntersectingLists({4, 1}, {5, 6, 1}, {8, 4, 5});
    ListNode* headA = lists.first;
    ListNode* headB = lists.second;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result != nullptr && "应该找到交点");
    assert(result->val == 8 && "交点值应为8");

    deleteIntersectingLists(headA, headB, result);
    std::cout << "通过" << std::endl;
}

void testIntersectionExists2() {
    std::cout << "测试用例2: 两个链表有交点 - 示例2" << std::endl;
    std::pair<ListNode*, ListNode*> lists = createIntersectingLists({1, 9, 1}, {3}, {2, 4});
    ListNode* headA = lists.first;
    ListNode* headB = lists.second;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result != nullptr && "应该找到交点");
    assert(result->val == 2 && "交点值应为2");

    deleteIntersectingLists(headA, headB, result);
    std::cout << "通过" << std::endl;
}

void testNoIntersection() {
    std::cout << "测试用例3: 两个链表无交点" << std::endl;
    ListNode* headA = createList({2, 6, 4});
    ListNode* headB = createList({1, 5});

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result == nullptr && "不应该找到交点");

    deleteList(headA);
    deleteList(headB);
    std::cout << "通过" << std::endl;
}

void testOneEmptyList() {
    std::cout << "测试用例4: 其中一个链表为空" << std::endl;
    ListNode* headA = createList({1, 2, 3});
    ListNode* headB = nullptr;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result == nullptr && "空链表不应有交点");

    deleteList(headA);
    std::cout << "通过" << std::endl;
}

void testBothEmptyLists() {
    std::cout << "测试用例5: 两个链表都为空" << std::endl;
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result == nullptr && "两个空链表不应有交点");
    std::cout << "通过" << std::endl;
}

void testIntersectionAtHead() {
    std::cout << "测试用例6: 交点在头部" << std::endl;
    std::pair<ListNode*, ListNode*> lists = createIntersectingLists({}, {}, {1, 2, 3});
    ListNode* headA = lists.first;
    ListNode* headB = lists.second;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result != nullptr && "应该找到交点");
    assert(result->val == 1 && "交点值应为1");

    deleteIntersectingLists(headA, headB, result);
    std::cout << "通过" << std::endl;
}

void testSingleElementIntersection() {
    std::cout << "测试用例7: 单节点链表相交" << std::endl;
    std::pair<ListNode*, ListNode*> lists = createIntersectingLists({1}, {2}, {3});
    ListNode* headA = lists.first;
    ListNode* headB = lists.second;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result != nullptr && "应该找到交点");
    assert(result->val == 3 && "交点值应为3");

    deleteIntersectingLists(headA, headB, result);
    std::cout << "通过" << std::endl;
}

void testSingleElementNoIntersection() {
    std::cout << "测试用例8: 单节点链表不相交" << std::endl;
    ListNode* headA = createList({1});
    ListNode* headB = createList({2});

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result == nullptr && "不应该找到交点");

    deleteList(headA);
    deleteList(headB);
    std::cout << "通过" << std::endl;
}

void testSameSingleElement() {
    std::cout << "测试用例9: 两个链表只有一个相同节点" << std::endl;
    std::pair<ListNode*, ListNode*> lists = createIntersectingLists({}, {}, {5});
    ListNode* headA = lists.first;
    ListNode* headB = lists.second;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    assert(result != nullptr && "应该找到交点");
    assert(result->val == 5 && "交点值应为5");

    deleteIntersectingLists(headA, headB, result);
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 160.相交链表 ==========" << std::endl;

    testIntersectionExists1();
    testIntersectionExists2();
    testNoIntersection();
    testOneEmptyList();
    testBothEmptyLists();
    testIntersectionAtHead();
    testSingleElementIntersection();
    testSingleElementNoIntersection();
    testSameSingleElement();

    std::cout << "========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}

