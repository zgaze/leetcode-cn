/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (74.98%)
 * Likes:    2584
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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while(curr->next && curr->next->next) {
            ListNode* next = curr->next;
            ListNode* nnext = curr->next->next;
            next->next = nnext->next;
            nnext->next = next;
            curr->next = nnext;
            curr = next;
        }
        return dummy.next;
    }
};
// @lc code=end

ListNode* swapPairs2(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = head->next;
    head->next = swapPairs2(newHead->next);
    newHead->next = head;
    return newHead;
}

// =============== 单元测试 ===============

#include <cassert>
#include <iostream>

// 辅助函数：链表转vector（用于验证结果）
std::vector<int> listToVector(ListNode* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void testExample1() {
    std::cout << "测试用例1: 示例1 [1,2,3,4]" << std::endl;
    ListNode* head = createList({1, 2, 3, 4});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {2, 1, 4, 3};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[2,1,4,3]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testExample2() {
    std::cout << "测试用例2: 示例2 空链表" << std::endl;
    ListNode* head = nullptr;

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    assert(result == nullptr && "空链表应返回nullptr");
    std::cout << "通过" << std::endl;
}

void testExample3() {
    std::cout << "测试用例3: 示例3 单节点 [1]" << std::endl;
    ListNode* head = createList({1});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testTwoNodes() {
    std::cout << "测试用例4: 两个节点 [1,2]" << std::endl;
    ListNode* head = createList({1, 2});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testThreeNodes() {
    std::cout << "测试用例5: 三个节点 [1,2,3]" << std::endl;
    ListNode* head = createList({1, 2, 3});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {2, 1, 3};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[2,1,3]，最后一个节点不交换");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testFiveNodes() {
    std::cout << "测试用例6: 五个节点 [1,2,3,4,5]" << std::endl;
    ListNode* head = createList({1, 2, 3, 4, 5});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {2, 1, 4, 3, 5};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[2,1,4,3,5]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testDuplicates() {
    std::cout << "测试用例7: 重复元素 [1,1,2,2]" << std::endl;
    ListNode* head = createList({1, 1, 2, 2});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {1, 1, 2, 2};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[1,1,2,2]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testBoundaryValues() {
    std::cout << "测试用例8: 边界值 [0,100,50,99]" << std::endl;
    ListNode* head = createList({0, 100, 50, 99});

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    std::vector<int> expected = {100, 0, 99, 50};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[100,0,99,50]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 24.两两交换链表中的节点 ==========" << std::endl;

    testExample1();
    testExample2();
    testExample3();
    testTwoNodes();
    testThreeNodes();
    testFiveNodes();
    testDuplicates();
    testBoundaryValues();

    std::cout << "========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}

