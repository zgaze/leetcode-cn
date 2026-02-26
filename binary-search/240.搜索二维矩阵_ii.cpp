/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (56.80%)
 * Likes:    1773
 * Dislikes: 0
 * Total Accepted:    776.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix =
 * [[1, 4, 7, 11,15],
 *  [2, 5, 8, 12,19],
 *  [3, 6, 9, 16,22],
 *  [10,13,14,17,24],
 *  [18,21,23,26,30]],
 * target = 20
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * 每行的所有元素从左到右升序排列
 * 每列的所有元素从上到下升序排列
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int M = matrix.size();
        int N = matrix[0].size() ;
        int m = 0, n = N-1;
        while (m < M && n >= 0) {
            if (matrix[m][n] > target) {
                n --;
            } else if (matrix[m][n] < target) {
                m ++;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

#include <iostream>
#include <cassert>

void test1() {
    // 示例 1: 找到目标值
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    assert(sol.searchMatrix(matrix, 5) == true);
    std::cout << "Test 1 passed: target=5 found" << std::endl;
}

void test2() {
    // 示例 2: 未找到目标值
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    assert(sol.searchMatrix(matrix, 20) == false);
    std::cout << "Test 2 passed: target=20 not found" << std::endl;
}

void test3() {
    // 测试 1x1 矩阵，找到
    Solution sol;
    vector<vector<int>> matrix = {{5}};
    assert(sol.searchMatrix(matrix, 5) == true);
    std::cout << "Test 3 passed: 1x1 matrix, target found" << std::endl;
}

void test4() {
    // 测试 1x1 矩阵，未找到
    Solution sol;
    vector<vector<int>> matrix = {{5}};
    assert(sol.searchMatrix(matrix, 3) == false);
    std::cout << "Test 4 passed: 1x1 matrix, target not found" << std::endl;
}

void test5() {
    // 测试单行矩阵
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7, 9}};
    assert(sol.searchMatrix(matrix, 5) == true);
    assert(sol.searchMatrix(matrix, 6) == false);
    std::cout << "Test 5 passed: single row matrix" << std::endl;
}

void test6() {
    // 测试单列矩阵
    Solution sol;
    vector<vector<int>> matrix = {{1}, {3}, {5}, {7}, {9}};
    assert(sol.searchMatrix(matrix, 5) == true);
    assert(sol.searchMatrix(matrix, 6) == false);
    std::cout << "Test 6 passed: single column matrix" << std::endl;
}

void test7() {
    // 测试负数
    Solution sol;
    vector<vector<int>> matrix = {
        {-5, -3, 0},
        {-2, 0, 3},
        {1, 4, 7}
    };
    assert(sol.searchMatrix(matrix, -3) == true);
    assert(sol.searchMatrix(matrix, -5) == true);
    assert(sol.searchMatrix(matrix, 7) == true);
    assert(sol.searchMatrix(matrix, 2) == false);
    std::cout << "Test 7 passed: negative numbers" << std::endl;
}

void test8() {
    // 测试 target 小于最小值
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    assert(sol.searchMatrix(matrix, 0) == false);
    std::cout << "Test 8 passed: target less than min" << std::endl;
}

void test9() {
    // 测试 target 大于最大值
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    assert(sol.searchMatrix(matrix, 10) == false);
    std::cout << "Test 9 passed: target greater than max" << std::endl;
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

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}

