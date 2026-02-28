/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode.cn/problems/two-sum/description/
 *
 * algorithms
 * Easy (55.07%)
 * Likes:    20677
 * Dislikes: 0
 * Total Accepted:    7.2M
 * Total Submissions: 13M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 只会存在一个有效答案
 * 
 * 
 * 
 * 
 * 进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？
 * 
 */
#include <vector>
#include <map>
using std::vector;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> num_idx;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = num_idx.find(target - nums[i]);
            if (it != num_idx.end()) {
                return {it->second, i};
            }
            num_idx[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void printResult(const vector<int>& result) {
    std::cout << "[" << result[0] << ", " << result[1] << "]";
}

void test1() {
    // 示例 1
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 1 passed: target=9, indices=";
    printResult(result);
    std::cout << std::endl;
}

void test2() {
    // 示例 2
    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 2 passed: target=6, indices=";
    printResult(result);
    std::cout << std::endl;
}

void test3() {
    // 示例 3 - 两个相同元素
    Solution sol;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 3 passed: target=6, indices=";
    printResult(result);
    std::cout << std::endl;
}

void test4() {
    // 负数
    Solution sol;
    vector<int> nums = {-1, -2, -3, -4, -5};
    int target = -8;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 4 passed: target=-8, indices=";
    printResult(result);
    std::cout << std::endl;
}

void test5() {
    // 正负数混合
    Solution sol;
    vector<int> nums = {-3, 4, 3, 90};
    int target = 0;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 5 passed: target=0, indices=";
    printResult(result);
    std::cout << std::endl;
}

void test6() {
    // 较大数组
    Solution sol;
    vector<int> nums = {1, 5, 3, 7, 9, 2, 8, 4};
    int target = 10;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 6 passed: target=10, indices=";
    printResult(result);
    std::cout << std::endl;
}

void test7() {
    // 最小数组 (长度为 2)
    Solution sol;
    vector<int> nums = {1, 2};
    int target = 3;
    vector<int> result = sol.twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
    std::cout << "Test 7 passed: target=3, indices=";
    printResult(result);
    std::cout << std::endl;
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

