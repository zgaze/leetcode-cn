/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode.cn/problems/majority-element/description/
 *
 * algorithms
 * Easy (67.17%)
 * Likes:    2644
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,2,3]
 * 输出：3
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,1,1,1,2,2]
 * 输出：2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 输入保证数组中一定有一个多数元素。
 * 
 * 
 * 
 * 
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 * 
 */
#include <vector>
using std::vector;
// @lc code=start

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = INT_MIN;
        int count = 0;
        for (auto n : nums) {
            if (n != element) {
                if (--count < 0) {
                    element = n;
                    count = 1;
                }
            } else {
                count ++;
            }
        }
        return element;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1
    Solution sol;
    vector<int> nums = {3, 2, 3};
    assert(sol.majorityElement(nums) == 3);
    std::cout << "Test 1 passed: [3,2,3] -> 3" << std::endl;
}

void test2() {
    // 示例 2
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    assert(sol.majorityElement(nums) == 2);
    std::cout << "Test 2 passed: [2,2,1,1,1,2,2] -> 2" << std::endl;
}

void test3() {
    // 单元素数组
    Solution sol;
    vector<int> nums = {1};
    assert(sol.majorityElement(nums) == 1);
    std::cout << "Test 3 passed: [1] -> 1" << std::endl;
}

void test4() {
    // 双元素数组
    Solution sol;
    vector<int> nums = {1, 1};
    assert(sol.majorityElement(nums) == 1);
    std::cout << "Test 4 passed: [1,1] -> 1" << std::endl;
}

void test5() {
    // 全部相同
    Solution sol;
    vector<int> nums = {5, 5, 5, 5, 5};
    assert(sol.majorityElement(nums) == 5);
    std::cout << "Test 5 passed: [5,5,5,5,5] -> 5" << std::endl;
}

void test6() {
    // 多数元素在开头
    Solution sol;
    vector<int> nums = {7, 1, 2, 3, 7, 7, 7};
    assert(sol.majorityElement(nums) == 7);
    std::cout << "Test 6 passed: majority at beginning" << std::endl;
}

void test7() {
    // 多数元素在末尾
    Solution sol;
    vector<int> nums = {1, 2, 3, 7, 7, 7, 7};
    assert(sol.majorityElement(nums) == 7);
    std::cout << "Test 7 passed: majority at end" << std::endl;
}

void test8() {
    // 包含负数
    Solution sol;
    vector<int> nums = {-1, -1, -1, 2, 3};
    assert(sol.majorityElement(nums) == -1);
    std::cout << "Test 8 passed: with negative numbers" << std::endl;
}

void test9() {
    // 正负数混合
    Solution sol;
    vector<int> nums = {-5, 3, -5, 1, -5, -5};
    assert(sol.majorityElement(nums) == -5);
    std::cout << "Test 9 passed: mixed positive/negative" << std::endl;
}

void test10() {
    // 较大数组
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 1, 4, 1, 5, 1, 1, 1};
    assert(sol.majorityElement(nums) == 1);
    std::cout << "Test 10 passed: larger array" << std::endl;
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

