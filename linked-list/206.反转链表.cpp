/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (76.38%)
 * Likes:    4096
 * Dislikes: 0
 * Total Accepted:    2.8M
 * Total Submissions: 3.6M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
 * 
 * 
 */
#include "listnode.h"
// 1->2->3->4
// 1->nullptr 2->3->4
// 
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
// @lc code=end


// 递归
// 1->2->3->4->5->nullptr
// 递归到最后返回5，回溯时逐层反转：
// 4->5 变成 5->4->nullptr
// 3->4 变成 5->4->3->nullptr
// ...
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        // 结束条件：空节点或单节点，无需反转
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 递归反转后半部分，newHead 是反转后的新头节点
        ListNode* newHead = reverseList(head->next);
        // 反转当前节点：让 next 指向自己
        head->next->next = head;
        // 断开当前节点的原连接，防止循环
        head->next = nullptr;
        // 返回新头节点
        return newHead;
    }
};

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
    std::cout << "测试用例1: 示例1 [1,2,3,4,5]" << std::endl;
    ListNode* head = createList({1, 2, 3, 4, 5});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {5, 4, 3, 2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[5,4,3,2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testExample2() {
    std::cout << "测试用例2: 示例2 [1,2]" << std::endl;
    ListNode* head = createList({1, 2});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testEmptyList() {
    std::cout << "测试用例3: 空链表" << std::endl;
    ListNode* head = nullptr;

    Solution sol;
    ListNode* result = sol.reverseList(head);

    assert(result == nullptr && "空链表应返回nullptr");
    std::cout << "通过" << std::endl;
}

void testSingleNode() {
    std::cout << "测试用例4: 单节点链表 [1]" << std::endl;
    ListNode* head = createList({1});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testThreeNodes() {
    std::cout << "测试用例5: 三个节点 [1,2,3]" << std::endl;
    ListNode* head = createList({1, 2, 3});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {3, 2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[3,2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testDuplicates() {
    std::cout << "测试用例6: 重复元素 [1,2,2,1]" << std::endl;
    ListNode* head = createList({1, 2, 2, 1});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {1, 2, 2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[1,2,2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testNegativeNumbers() {
    std::cout << "测试用例7: 负数 [-1,-2,-3]" << std::endl;
    ListNode* head = createList({-1, -2, -3});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {-3, -2, -1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[-3,-2,-1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testMixedNumbers() {
    std::cout << "测试用例8: 正负混合 [0,-1,2,-3,4]" << std::endl;
    ListNode* head = createList({0, -1, 2, -3, 4});

    Solution sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {4, -3, 2, -1, 0};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[4,-3,2,-1,0]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testExample1_Solution2() {
    std::cout << "测试用例1 (Solution2): 示例1 [1,2,3,4,5]" << std::endl;
    ListNode* head = createList({1, 2, 3, 4, 5});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {5, 4, 3, 2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[5,4,3,2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testExample2_Solution2() {
    std::cout << "测试用例2 (Solution2): 示例2 [1,2]" << std::endl;
    ListNode* head = createList({1, 2});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testEmptyList_Solution2() {
    std::cout << "测试用例3 (Solution2): 空链表" << std::endl;
    ListNode* head = nullptr;

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    assert(result == nullptr && "空链表应返回nullptr");
    std::cout << "通过" << std::endl;
}

void testSingleNode_Solution2() {
    std::cout << "测试用例4 (Solution2): 单节点链表 [1]" << std::endl;
    ListNode* head = createList({1});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testThreeNodes_Solution2() {
    std::cout << "测试用例5 (Solution2): 三个节点 [1,2,3]" << std::endl;
    ListNode* head = createList({1, 2, 3});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {3, 2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[3,2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testDuplicates_Solution2() {
    std::cout << "测试用例6 (Solution2): 重复元素 [1,2,2,1]" << std::endl;
    ListNode* head = createList({1, 2, 2, 1});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {1, 2, 2, 1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[1,2,2,1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testNegativeNumbers_Solution2() {
    std::cout << "测试用例7 (Solution2): 负数 [-1,-2,-3]" << std::endl;
    ListNode* head = createList({-1, -2, -3});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {-3, -2, -1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[-3,-2,-1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testMixedNumbers_Solution2() {
    std::cout << "测试用例8 (Solution2): 正负混合 [0,-1,2,-3,4]" << std::endl;
    ListNode* head = createList({0, -1, 2, -3, 4});

    Solution2 sol;
    ListNode* result = sol.reverseList(head);

    std::vector<int> expected = {4, -3, 2, -1, 0};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "结果应为[4,-3,2,-1,0]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 206.反转链表 ==========" << std::endl;

    std::cout << "\n--- Solution (迭代) ---" << std::endl;
    testExample1();
    testExample2();
    testEmptyList();
    testSingleNode();
    testThreeNodes();
    testDuplicates();
    testNegativeNumbers();
    testMixedNumbers();

    std::cout << "\n--- Solution2 (递归) ---" << std::endl;
    testExample1_Solution2();
    testExample2_Solution2();
    testEmptyList_Solution2();
    testSingleNode_Solution2();
    testThreeNodes_Solution2();
    testDuplicates_Solution2();
    testNegativeNumbers_Solution2();
    testMixedNumbers_Solution2();

    std::cout << "\n========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}

