/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode.cn/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (67.32%)
 * Likes:    2744
 * Dislikes: 0
 * Total Accepted:    600.8K
 * Total Submissions: 892.4K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
 * 
 * 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
 * 
 * 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,4,2,2]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,1,3,4,2]
 * 输出：3
 * 
 * 
 * 示例 3 :
 * 
 * 
 * 输入：nums = [3,3,3,3,3]
 * 输出：3
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如何证明 nums 中至少存在一个重复的数字?
 * 你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？
 * 
 * 
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = slow;
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    assert(sol.findDuplicate(nums) == 2);
    std::cout << "Test 1 passed: duplicate=2" << std::endl;
}

void test2() {
    // 示例 2
    Solution sol;
    vector<int> nums = {3, 1, 3, 4, 2};
    assert(sol.findDuplicate(nums) == 3);
    std::cout << "Test 2 passed: duplicate=3" << std::endl;
}

void test3() {
    // 示例 3 - 全部相同
    Solution sol;
    vector<int> nums = {3, 3, 3, 3, 3};
    assert(sol.findDuplicate(nums) == 3);
    std::cout << "Test 3 passed: duplicate=3 (all same)" << std::endl;
}

void test4() {
    // 最小情况 n=1
    Solution sol;
    vector<int> nums = {1, 1};
    assert(sol.findDuplicate(nums) == 1);
    std::cout << "Test 4 passed: duplicate=1 (min case)" << std::endl;
}

void test5() {
    // 重复多次
    Solution sol;
    // 1->2->3->4->5->6->3
    vector<int> nums = {1, 2, 3, 4, 5, 6, 3, 7};
    assert(sol.findDuplicate(nums) == 3);
    std::cout << "Test 5 passed: duplicate=3 (larger array)" << std::endl;
}

void test6() {
    // 重复数字在开头
    Solution sol;
    vector<int> nums = {2, 2, 1, 3};
    assert(sol.findDuplicate(nums) == 2);
    std::cout << "Test 6 passed: duplicate=2 (at beginning)" << std::endl;
}

void test7() {
    // 重复数字在末尾
    Solution sol;
    vector<int> nums = {1, 2, 4, 3, 4};
    assert(sol.findDuplicate(nums) == 4);
    std::cout << "Test 7 passed: duplicate=4 (at end)" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

