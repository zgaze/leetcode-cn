/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    3326
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.8M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，使数组变为 [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始
 * 计数）。例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include <vector>
using std::vector;
// @lc code=start

class Solution {
public:
    int findMinIdx(vector<int>& nums) {
        int l = 0, r = nums.size() -1;
        while (l < r) {
            int mid = (r-l)/2 +l;
            if (nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int binaryFind(vector<int>& nums, int begin, int end, int target) {
        while (begin <= end) {
            int mid = (end - begin) / 2 + begin;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid -1;
            } else {
                begin = mid +1;
            }
        }
        return -1;

    }
    int search(vector<int>& nums, int target) {
        int min = findMinIdx(nums);
        int l = binaryFind(nums, 0, min-1, target);
        int r = binaryFind(nums, min, nums.size() -1, target);
        return std::max(l, r);
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1: 在旋转数组中找到 target
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, 0) == 4);
    std::cout << "Test 1 passed: target=0 found at index 4" << std::endl;
}

void test2() {
    // 示例 2: target 不存在
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, 3) == -1);
    std::cout << "Test 2 passed: target=3 not found" << std::endl;
}

void test3() {
    // 示例 3: 单元素数组，未找到
    Solution sol;
    vector<int> nums = {1};
    assert(sol.search(nums, 0) == -1);
    std::cout << "Test 3 passed: single element, target not found" << std::endl;
}

void test4() {
    // 单元素数组，找到
    Solution sol;
    vector<int> nums = {1};
    assert(sol.search(nums, 1) == 0);
    std::cout << "Test 4 passed: single element, target found" << std::endl;
}

void test5() {
    // 旋转点在开头（相当于未旋转）
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    assert(sol.search(nums, 3) == 2);
    assert(sol.search(nums, 1) == 0);
    assert(sol.search(nums, 5) == 4);
    std::cout << "Test 5 passed: sorted array (no rotation)" << std::endl;
}

void test6() {
    // 旋转点在中间
    Solution sol;
    vector<int> nums = {5, 6, 7, 1, 2, 3, 4};
    assert(sol.search(nums, 1) == 3);
    assert(sol.search(nums, 5) == 0);
    assert(sol.search(nums, 4) == 6);
    std::cout << "Test 6 passed: rotation at middle" << std::endl;
}

void test7() {
    // 旋转点在末尾（相当于整体右移一位）
    Solution sol;
    vector<int> nums = {2, 3, 4, 5, 1};
    assert(sol.search(nums, 1) == 4);
    assert(sol.search(nums, 2) == 0);
    std::cout << "Test 7 passed: rotation at end" << std::endl;
}

void test8() {
    // 双元素数组
    Solution sol;
    vector<int> nums = {2, 1};
    assert(sol.search(nums, 1) == 1);
    assert(sol.search(nums, 2) == 0);
    assert(sol.search(nums, 3) == -1);
    std::cout << "Test 8 passed: two elements" << std::endl;
}

void test9() {
    // target 为最小值
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, 0) == 4);
    std::cout << "Test 9 passed: target is minimum" << std::endl;
}

void test10() {
    // target 为最大值
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, 7) == 3);
    std::cout << "Test 10 passed: target is maximum" << std::endl;
}

void test11() {
    // target 小于所有元素
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, -5) == -1);
    std::cout << "Test 11 passed: target less than all elements" << std::endl;
}

void test12() {
    // target 大于所有元素
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, 10) == -1);
    std::cout << "Test 12 passed: target greater than all elements" << std::endl;
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
    test11();
    test12();

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

