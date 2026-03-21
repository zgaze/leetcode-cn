/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 *
 * https://leetcode.cn/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (70.57%)
 * Likes:    1773
 * Dislikes: 0
 * Total Accepted:    599.8K
 * Total Submissions: 849.6K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
 * 
 * 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random
 * 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
 * 
 * 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random
 * --> y 。
 * 
 * 返回复制链表的头节点。
 * 
 * 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 * 
 * 
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 * 
 * 
 * 你的代码 只 接受原链表的头节点 head 作为传入参数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 1000
 * -10^4 <= Node.val <= 10^4
 * Node.random 为 null 或指向链表中的节点。
 * 
 * 
 * 
 * 
 */

#include <cstddef>
class Node {
  public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void printRandomList(Node* head, const char* name);
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// 1,4->2,1->4,1
// 1,4->1,4->2,1->2,1->4,1->4,1
// 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* phead = head;
        // 原节点后面复制一份
        while (phead) {
            Node* n = phead->next;
            Node* r = phead->random;
            Node* tmp = new Node(phead->val);
            tmp->next = n;
            tmp->random = r;
            phead->next = tmp;
            phead = n;
        }
        phead = head;
        int i = 0;
        while (phead) {
            if (i&1) { // 单数节点是复制来的。让它的random也等于复制的节点
                if (phead->random) {
                    phead->random = phead->random->next;
                }
            }
            i++;
            phead = phead->next;
        }
        phead = head;
        Node* ret = phead->next;
        Node* pret = nullptr;
        //拆分复制的节点
        while (phead) {
            Node* n = phead->next;
            if (pret) {
                pret->next = n;
                pret = n;
            } else {
                pret = n;
            }
            phead->next = n->next;
            phead = phead->next;
        }        
        return ret;
    }
};
// @lc code=end

// =============== 单元测试 ===============

#include <cassert>
#include <iostream>
#include <vector>

// 辅助函数：创建随机链表
// data: 每个元素是 pair<val, randomIndex>，randomIndex 为 -1 表示 null
Node* createRandomList(const std::vector<std::pair<int, int>>& data) {
    if (data.empty()) return nullptr;

    std::vector<Node*> nodes;
    for (const auto& p : data) {
        nodes.push_back(new Node(p.first));
    }
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (i < nodes.size() - 1) {
            nodes[i]->next = nodes[i + 1];
        }
        int randomIdx = data[i].second;
        if (randomIdx >= 0 && randomIdx < (int)nodes.size()) {
            nodes[i]->random = nodes[randomIdx];
        }
    }
    return nodes[0];
}

// 辅助函数：释放随机链表
void deleteRandomList(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

// 辅助函数：验证两个链表是否是深拷贝关系
// 检查：值相同、结构相同、但节点地址不同
bool verifyDeepCopy(Node* original, Node* copied) {
    Node* p1 = original;
    Node* p2 = copied;

    while (p1 && p2) {
        // 值必须相同
        if (p1->val != p2->val) return false;
        // 节点地址必须不同（深拷贝）
        if (p1 == p2) return false;

        p1 = p1->next;
        p2 = p2->next;
    }
    // 长度必须相同
    if (p1 != nullptr || p2 != nullptr) return false;

    // 检查 random 指针
    p1 = original;
    p2 = copied;
    while (p1 && p2) {
        // random 指针状态必须一致（都为空或都不为空）
        if ((p1->random == nullptr) != (p2->random == nullptr)) return false;
        // 如果都不为空，random 指向的节点值必须相同，但地址必须不同
        if (p1->random && p2->random) {
            if (p1->random->val != p2->random->val) return false;
            if (p1->random == p2->random) return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

// 辅助函数：打印链表信息（用于调试）
void printRandomList(Node* head, const char* name) {
    std::cout << name << ": ";
    std::vector<Node*> nodes;
    Node* p = head;
    while (p) {
        nodes.push_back(p);
        p = p->next;
    }
    for (size_t i = 0; i < nodes.size(); ++i) {
        std::cout << "[" << nodes[i]->val << ",";
        if (nodes[i]->random) {
            for (size_t j = 0; j < nodes.size(); ++j) {
                if (nodes[j] == nodes[i]->random) {
                    std::cout << j;
                    break;
                }
            }
        } else {
            std::cout << "null";
        }
        std::cout << "]";
        if (i < nodes.size() - 1) std::cout << "->";
    }
    std::cout << std::endl;
}

void testExample1() {
    std::cout << "测试用例1: 示例1 [[7,null],[13,0],[11,4],[10,2],[1,0]]" << std::endl;
    // [[7,null],[13,0],[11,4],[10,2],[1,0]]
    // random: 节点1->null, 节点2->节点0, 节点3->节点4, 节点4->节点2, 节点5->节点0
    Node* head = createRandomList({
        {7, -1},   // 节点0: val=7, random=null
        {13, 0},   // 节点1: val=13, random=节点0
        {11, 4},   // 节点2: val=11, random=节点4
        {10, 2},   // 节点3: val=10, random=节点2
        {1, 0}     // 节点4: val=1, random=节点0
    });

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testExample2() {
    std::cout << "测试用例2: 示例2 [[1,1],[2,1]]" << std::endl;
    // [[1,1],[2,1]]
    // random: 节点0->节点1, 节点1->节点1
    Node* head = createRandomList({
        {1, 1},    // 节点0: val=1, random=节点1
        {2, 1}     // 节点1: val=2, random=节点1
    });

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testExample3() {
    std::cout << "测试用例3: 示例3 [[3,null],[3,0],[3,null]]" << std::endl;
    // [[3,null],[3,0],[3,null]]
    Node* head = createRandomList({
        {3, -1},   // 节点0: val=3, random=null
        {3, 0},    // 节点1: val=3, random=节点0
        {3, -1}    // 节点2: val=3, random=null
    });

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testEmptyList() {
    std::cout << "测试用例4: 空链表" << std::endl;
    Node* head = nullptr;

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied == nullptr && "空链表应返回nullptr");
    std::cout << "通过" << std::endl;
}

void testSingleNodeNoRandom() {
    std::cout << "测试用例5: 单节点无random" << std::endl;
    Node* head = createRandomList({{5, -1}});

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testSingleNodeSelfRandom() {
    std::cout << "测试用例6: 单节点自指向random" << std::endl;
    Node* head = createRandomList({{7, 0}});

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testAllRandomNull() {
    std::cout << "测试用例7: 多节点全部random为null" << std::endl;
    Node* head = createRandomList({
        {1, -1},
        {2, -1},
        {3, -1},
        {4, -1}
    });

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testRandomPointsToHead() {
    std::cout << "测试用例8: 所有random都指向头节点" << std::endl;
    Node* head = createRandomList({
        {1, 0},
        {2, 0},
        {3, 0}
    });

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

void testRandomPointsToTail() {
    std::cout << "测试用例9: 所有random都指向尾节点" << std::endl;
    Node* head = createRandomList({
        {1, 2},
        {2, 2},
        {3, 2}
    });

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    assert(copied != nullptr && "应返回复制的链表");
    assert(verifyDeepCopy(head, copied) && "深拷贝验证失败");

    deleteRandomList(head);
    deleteRandomList(copied);
    std::cout << "通过" << std::endl;
}

int main() {
    std::cout << "========== 开始测试 138.随机链表的复制 ==========" << std::endl;

    testExample1();
    testExample2();
    testExample3();
    testEmptyList();
    testSingleNodeNoRandom();
    testSingleNodeSelfRandom();
    testAllRandomNull();
    testRandomPointsToHead();
    testRandomPointsToTail();

    std::cout << "========== 所有测试用例通过 ==========" << std::endl;
    return 0;
}

