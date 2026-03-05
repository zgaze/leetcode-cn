/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (48.81%)
 * Likes:    2516
 * Dislikes: 0
 * Total Accepted:    700.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 解释：范围 [1,2] 中的数字都在数组中。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 解释：1 在数组中，但 2 没有。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 解释：最小的正数 1 没有出现。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */
#include <vector>
using std::vector;
// @lc code=start

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            // 让数字 x（如果 1 <= x <= n）回到它应该在的位置——索引 x-1
            while (nums[i] <= N && nums[i] > 0 && nums[i] != nums[nums[i]-1]) {
                std::swap(nums[i], nums[nums[i]-1]);
                
            }
        }
        int i = 0;
        for (; i < N; ++i) {
            if (nums[i] != i +1) return i +1;
        }
        return i + 1;
     }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    vector<int> nums = {1, 2, 0};
    assert(sol.firstMissingPositive(nums) == 3);
    std::cout << "Test 1 passed: [1,2,0] -> 3" << std::endl;
}

void test2() {
    // 示例 2
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    assert(sol.firstMissingPositive(nums) == 2);
    std::cout << "Test 2 passed: [3,4,-1,1] -> 2" << std::endl;
}

void test3() {
    // 示例 3
    Solution sol;
    vector<int> nums = {7, 8, 9, 11, 12};
    assert(sol.firstMissingPositive(nums) == 1);
    std::cout << "Test 3 passed: [7,8,9,11,12] -> 1" << std::endl;
}

void test4() {
    // 单元素数组，包含 1
    Solution sol;
    vector<int> nums = {1};
    assert(sol.firstMissingPositive(nums) == 2);
    std::cout << "Test 4 passed: [1] -> 2" << std::endl;
}

void test5() {
    // 单元素数组，不包含 1
    Solution sol;
    vector<int> nums = {2};
    assert(sol.firstMissingPositive(nums) == 1);
    std::cout << "Test 5 passed: [2] -> 1" << std::endl;
}

void test6() {
    // 连续正整数
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    assert(sol.firstMissingPositive(nums) == 6);
    std::cout << "Test 6 passed: [1,2,3,4,5] -> 6" << std::endl;
}

void test7() {
    // 包含重复元素
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3};
    assert(sol.firstMissingPositive(nums) == 4);
    std::cout << "Test 7 passed: [1,1,2,2,3,3] -> 4" << std::endl;
}

void test8() {
    // 全部是负数
    Solution sol;
    vector<int> nums = {-1, -2, -3};
    assert(sol.firstMissingPositive(nums) == 1);
    std::cout << "Test 8 passed: [-1,-2,-3] -> 1" << std::endl;
}

void test9() {
    // 包含 0 和负数
    Solution sol;
    vector<int> nums = {0, -1, 2};
    assert(sol.firstMissingPositive(nums) == 1);
    std::cout << "Test 9 passed: [0,-1,2] -> 1" << std::endl;
}

void test10() {
    // 缺失中间的数字
    Solution sol;
    vector<int> nums = {1, 2, 3, 5, 6};
    assert(sol.firstMissingPositive(nums) == 4);
    std::cout << "Test 10 passed: [1,2,3,5,6] -> 4" << std::endl;
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
    test10();

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

