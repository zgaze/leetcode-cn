/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (67.72%)
 * Likes:    2727
 * Dislikes: 0
 * Total Accepted:    891.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
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
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
    // 合并两个已排序的链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);  // 虚拟头节点
        ListNode* tail = &dummy;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        // 拼接剩余部分
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        // 递归结束条件：空链表或单节点
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 快慢指针找中点（slow 停在中点或左中点）
        ListNode* fast = head->next;  // fast 先走一步，让 slow 停在左中点
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 分割链表
        ListNode* right = slow->next;
        slow->next = nullptr;

        // 递归排序左右两半，然后合并
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);
        return merge(leftSorted, rightSorted);
    }
};;
// @lc code=end

// =============== 单元测试 ===============

#include <cassert>
#include <iostream>

// 辅助函数：检查链表是否升序排列
bool isSorted(ListNode* head) {
    while (head && head->next) {
        if (head->val > head->next->val) return false;
        head = head->next;
    }
    return true;
}

// 辅助函数：获取链表长度
int getListLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

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
    std::cout << "测试用例1: 示例1 [4,2,1,3]" << std::endl;
    ListNode* head = createList({4, 2, 1, 3});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 4 && "链表长度应为4");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testExample2() {
    std::cout << "测试用例2: 示例2 [-1,5,3,4,0]" << std::endl;
    ListNode* head = createList({-1, 5, 3, 4, 0});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 5 && "链表长度应为5");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testEmptyList() {
    std::cout << "测试用例3: 空链表" << std::endl;
    ListNode* head = nullptr;

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result == nullptr && "空链表应返回nullptr");
    std::cout << "通过" << std::endl;
}

void testSingleNode() {
    std::cout << "测试用例4: 单节点链表 [1]" << std::endl;
    ListNode* head = createList({1});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(result->val == 1 && "节点值应为1");
    assert(result->next == nullptr && "应只有一个节点");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testAlreadySorted() {
    std::cout << "测试用例5: 已排序链表 [1,2,3,4,5]" << std::endl;
    ListNode* head = createList({1, 2, 3, 4, 5});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 5 && "链表长度应为5");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testReverseSorted() {
    std::cout << "测试用例6: 逆序链表 [5,4,3,2,1]" << std::endl;
    ListNode* head = createList({5, 4, 3, 2, 1});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 5 && "链表长度应为5");

    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "排序结果应为[1,2,3,4,5]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testDuplicates() {
    std::cout << "测试用例7: 重复元素 [3,1,2,3,1]" << std::endl;
    ListNode* head = createList({3, 1, 2, 3, 1});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 5 && "链表长度应为5");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testAllSame() {
    std::cout << "测试用例8: 所有元素相同 [2,2,2,2]" << std::endl;
    ListNode* head = createList({2, 2, 2, 2});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 4 && "链表长度应为4");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testNegativeNumbers() {
    std::cout << "测试用例9: 负数 [-5,-1,-3,-2,-4]" << std::endl;
    ListNode* head = createList({-5, -1, -3, -2, -4});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(getListLength(result) == 5 && "链表长度应为5");

    std::vector<int> expected = {-5, -4, -3, -2, -1};
    std::vector<int> actual = listToVector(result);
    assert(actual == expected && "排序结果应为[-5,-4,-3,-2,-1]");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

void testTwoNodes() {
    std::cout << "测试用例10: 两个节点 [2,1]" << std::endl;
    ListNode* head = createList({2, 1});

    Solution sol;
    ListNode* result = sol.sortList(head);

    assert(result != nullptr && "结果不应为空");
    assert(isSorted(result) && "链表应该升序排列");
    assert(result->val == 1 && "第一个节点值应为1");
    assert(result->next->val == 2 && "第二个节点值应为2");

    deleteList(result);
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 148.排序链表 ==========" << std::endl;

    testExample1();
    testExample2();
    testEmptyList();
    testSingleNode();
    testAlreadySorted();
    testReverseSorted();
    testDuplicates();
    testAllSame();
    testNegativeNumbers();
    testTwoNodes();

    std::cout << "========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}

