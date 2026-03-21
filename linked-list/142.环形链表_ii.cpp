/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode.cn/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (62.60%)
 * Likes:    3001
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.3M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos
 * 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 * 
 * 不允许修改 链表。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：返回索引为 1 的链表节点
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：返回索引为 0 的链表节点
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：head = [1], pos = -1
 * 输出：返回 null
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围在范围 [0, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * pos 的值为 -1 或者链表中的一个有效索引
 * 
 * 
 * 
 * 
 * 进阶：你是否可以使用 O(1) 空间解决此题？
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool has_cycle = false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                has_cycle = true;
                break;
            }
        }
        if (!has_cycle) return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

// =============== 单元测试 ===============

#include <cassert>
#include <iostream>

// 辅助函数：创建带环的链表，返回头节点和环入口节点
// vals: 节点值列表
// pos: 环的入口位置（-1 表示无环）
// 返回 pair<head, cycleEntry>
std::pair<ListNode*, ListNode*> createCycleListWithEntry(const std::vector<int>& vals, int pos) {
    if (vals.empty()) return {nullptr, nullptr};

    std::vector<ListNode*> nodes;
    for (int v : vals) {
        nodes.push_back(new ListNode(v));
    }
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }

    ListNode* cycleEntry = nullptr;
    if (pos >= 0 && pos < (int)nodes.size()) {
        nodes.back()->next = nodes[pos];
        cycleEntry = nodes[pos];
    }
    return std::make_pair(nodes[0], cycleEntry);
}

// 辅助函数：释放无环链表
void deleteNonCycleList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void testDetectCycle1() {
    std::cout << "测试用例1: 有环链表 - 示例1 [3,2,0,-4], pos=1" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({3, 2, 0, -4}, 1);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == expected && "应返回正确的环入口节点");
    assert(result->val == 2 && "环入口节点值应为2");
    std::cout << "通过" << std::endl;
}

void testDetectCycle2() {
    std::cout << "测试用例2: 有环链表 - 示例2 [1,2], pos=0" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1, 2}, 0);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == expected && "应返回正确的环入口节点");
    assert(result->val == 1 && "环入口节点值应为1");
    std::cout << "通过" << std::endl;
}

void testNoCycle() {
    std::cout << "测试用例3: 无环链表 - 示例3 [1], pos=-1" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1}, -1);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == nullptr && "无环应返回nullptr");

    deleteNonCycleList(head);
    std::cout << "通过" << std::endl;
}

void testEmptyList() {
    std::cout << "测试用例4: 空链表" << std::endl;
    ListNode* head = nullptr;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == nullptr && "空链表应返回nullptr");
    std::cout << "通过" << std::endl;
}

void testSingleSelfLoop() {
    std::cout << "测试用例5: 单节点自环 [1], pos=0" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1}, 0);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == expected && "应返回正确的环入口节点");
    assert(result->val == 1 && "环入口节点值应为1");
    std::cout << "通过" << std::endl;
}

void testLongNoCycle() {
    std::cout << "测试用例6: 长链表无环 [1,2,3,4,5,6,7,8,9,10], pos=-1" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, -1);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == nullptr && "无环应返回nullptr");

    deleteNonCycleList(head);
    std::cout << "通过" << std::endl;
}

void testCycleAtEnd() {
    std::cout << "测试用例7: 环在末尾（尾节点指向自己）[1,2,3], pos=2" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1, 2, 3}, 2);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == expected && "应返回正确的环入口节点");
    assert(result->val == 3 && "环入口节点值应为3");
    std::cout << "通过" << std::endl;
}

void testTwoNodesNoCycle() {
    std::cout << "测试用例8: 两个节点无环 [1,2], pos=-1" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1, 2}, -1);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == nullptr && "无环应返回nullptr");

    deleteNonCycleList(head);
    std::cout << "通过" << std::endl;
}

void testCycleAtMiddle() {
    std::cout << "测试用例9: 环在中间 [1,2,3,4,5], pos=2" << std::endl;
    std::pair<ListNode*, ListNode*> listInfo = createCycleListWithEntry({1, 2, 3, 4, 5}, 2);
    ListNode* head = listInfo.first;
    ListNode* expected = listInfo.second;

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    assert(result == expected && "应返回正确的环入口节点");
    assert(result->val == 3 && "环入口节点值应为3");
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 142.环形链表 II ==========" << std::endl;

    testDetectCycle1();
    testDetectCycle2();
    testNoCycle();
    testEmptyList();
    testSingleSelfLoop();
    testLongNoCycle();
    testCycleAtEnd();
    testTwoNodesNoCycle();
    testCycleAtMiddle();

    std::cout << "========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}


