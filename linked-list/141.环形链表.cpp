/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 *
 * https://leetcode.cn/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (54.46%)
 * Likes:    2461
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 3.4M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 * 
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
 * 
 * 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 10^4]
 * -10^5 <= Node.val <= 10^5
 * pos 为 -1 或者链表中的一个 有效索引 。
 * 
 * 
 * 
 * 
 * 进阶：你能用 O(1)（即，常量）内存解决此问题吗？
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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
// @lc code=end

// =============== 单元测试 ===============

#include <cassert>
#include <iostream>

// 辅助函数：创建带环的链表
// vals: 节点值列表
// pos: 环的入口位置（-1 表示无环）
ListNode* createCycleList(const std::vector<int>& vals, int pos) {
    if (vals.empty()) return nullptr;

    std::vector<ListNode*> nodes;
    for (int v : vals) {
        nodes.push_back(new ListNode(v));
    }
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    if (pos >= 0 && pos < (int)nodes.size()) {
        nodes.back()->next = nodes[pos];
    }
    return nodes[0];
}

// 辅助函数：释放无环链表
void deleteNonCycleList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void testHasCycle1() {
    std::cout << "测试用例1: 有环链表 - 示例1 [3,2,0,-4], pos=1" << std::endl;
    ListNode* head = createCycleList({3, 2, 0, -4}, 1);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == true && "应该检测到环");
    std::cout << "通过" << std::endl;

    // 注意：带环链表无法简单释放，这里省略
}

void testHasCycle2() {
    std::cout << "测试用例2: 有环链表 - 示例2 [1,2], pos=0" << std::endl;
    ListNode* head = createCycleList({1, 2}, 0);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == true && "应该检测到环");
    std::cout << "通过" << std::endl;
}

void testNoCycle1() {
    std::cout << "测试用例3: 无环链表 - 示例3 [1], pos=-1" << std::endl;
    ListNode* head = createCycleList({1}, -1);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == false && "不应该检测到环");

    deleteNonCycleList(head);
    std::cout << "通过" << std::endl;
}

void testEmptyList() {
    std::cout << "测试用例4: 空链表" << std::endl;
    ListNode* head = nullptr;

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == false && "空链表不应该有环");
    std::cout << "通过" << std::endl;
}

void testSingleSelfLoop() {
    std::cout << "测试用例5: 单节点自环 [1], pos=0" << std::endl;
    ListNode* head = createCycleList({1}, 0);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == true && "应该检测到环");
    std::cout << "通过" << std::endl;
}

void testLongNoCycle() {
    std::cout << "测试用例6: 长链表无环 [1,2,3,4,5,6,7,8,9,10], pos=-1" << std::endl;
    ListNode* head = createCycleList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, -1);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == false && "不应该检测到环");

    deleteNonCycleList(head);
    std::cout << "通过" << std::endl;
}

void testCycleAtEnd() {
    std::cout << "测试用例7: 环在末尾（尾节点指向自己）[1,2,3], pos=2" << std::endl;
    ListNode* head = createCycleList({1, 2, 3}, 2);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == true && "应该检测到环");
    std::cout << "通过" << std::endl;
}

void testTwoNodesNoCycle() {
    std::cout << "测试用例8: 两个节点无环 [1,2], pos=-1" << std::endl;
    ListNode* head = createCycleList({1, 2}, -1);

    Solution sol;
    bool result = sol.hasCycle(head);

    assert(result == false && "不应该检测到环");

    deleteNonCycleList(head);
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 141.环形链表 ==========" << std::endl;

    testHasCycle1();
    testHasCycle2();
    testNoCycle1();
    testEmptyList();
    testSingleSelfLoop();
    testLongNoCycle();
    testCycleAtEnd();
    testTwoNodesNoCycle();

    std::cout << "========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}

