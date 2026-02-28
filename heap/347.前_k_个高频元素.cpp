/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (65.44%)
 * Likes:    2131
 * Dislikes: 0
 * Total Accepted:    873.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,2,2,3], k = 2
 * 
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,1,2,1,2,3,1,3,2], k = 2
 * 
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */
#include <vector>
#include <unordered_map>
#include <queue>
using std::vector;
// 本质是LFU
// @lc code=start
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_count;
        struct CmpStruct{
            bool operator()(std::pair<int, int>&a, std::pair<int, int>&b){
                return a.first > b.first;
            }
        } cmp;
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, CmpStruct> q;
        // 最小堆，保存K个元素
        for (auto n : nums) {
            freq_count[n] ++;
        }
        for (auto& kv : freq_count) {
            int num = kv.first;
            int count = kv.second;
            if (q.size() < k) {
                q.push({count, num});
            } else {
                if (q.top().first < count) {
                    q.pop();
                    q.push({count, num});
                }
            }
        }
        vector<int> res;
        res.reserve(k);
        while (q.size()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;

    }
};
// @lc code=end

#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>

bool hasSameElements(const vector<int>& a, const vector<int>& b) {
    std::set<int> sa(a.begin(), a.end());
    std::set<int> sb(b.begin(), b.end());
    return sa == sb;
}

void printResult(const vector<int>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void test1() {
    // 示例 1
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 2);
    assert(hasSameElements(result, {1, 2}));
    std::cout << "Test 1 passed: k=2, result=";
    printResult(result);
    std::cout << std::endl;
}

void test2() {
    // 示例 2 - 单元素
    Solution sol;
    vector<int> nums = {1};
    int k = 1;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 1);
    assert(result[0] == 1);
    std::cout << "Test 2 passed: k=1, single element, result=";
    printResult(result);
    std::cout << std::endl;
}

void test3() {
    // 示例 3
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 2);
    assert(hasSameElements(result, {1, 2}));
    std::cout << "Test 3 passed: k=2, multiple duplicates, result=";
    printResult(result);
    std::cout << std::endl;
}

void test4() {
    // k 等于不同元素个数
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 5);
    std::cout << "Test 4 passed: k equals unique count, result=";
    printResult(result);
    std::cout << std::endl;
}

void test5() {
    // k=1，找频率最高的
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 3};
    int k = 1;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 1);
    assert(result[0] == 2);
    std::cout << "Test 5 passed: k=1, most frequent, result=";
    printResult(result);
    std::cout << std::endl;
}

void test6() {
    // 负数
    Solution sol;
    vector<int> nums = {-1, -1, -2, -2, -2, -3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 2);
    assert(hasSameElements(result, {-2, -1}));
    std::cout << "Test 6 passed: k=2, negative numbers, result=";
    printResult(result);
    std::cout << std::endl;
}

void test7() {
    // 正负数混合，答案唯一
    Solution sol;
    vector<int> nums = {-3, -3, -3, 1, 1, 1, 1, 2};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    assert(result.size() == 2);
    assert(hasSameElements(result, {1, -3}));
    std::cout << "Test 7 passed: k=2, mixed positive/negative, result=";
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

