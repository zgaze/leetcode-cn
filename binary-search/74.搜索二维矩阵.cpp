/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (52.27%)
 * Likes:    1129
 * Dislikes: 0
 * Total Accepted:    693.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 * 
 * 
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 *  N=3,M=4
 * 输入：matrix = [
 * [1, 3, 5,  7],
 * [10,11,16,20],
 * [23,30,34,60]
 * ],
 *  target = 13
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
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */
#include <vector>
#include <cassert>
using std::vector;
// @lc code=start

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int N = matrix.size();
        int M = matrix[0].size();
        int l = 0, r = M * N - 1;
        while (l <= r) {
            int mid = (r - l)/2 +l;
            int n = mid / M;
            int m = mid % M;
            if (matrix[n][m] < target) {
                l = mid + 1;
            } else if (matrix[n][m] == target) {
               return true;
            } else {
                 r = mid -1;
            }
         }
         return false;
    }
};
// @lc code=end

int main() {
    Solution s;

    // 示例 1: target 存在
    vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    assert(s.searchMatrix(matrix1, 3) == true);
    assert(s.searchMatrix(matrix1, 1) == true);
    assert(s.searchMatrix(matrix1, 60) == true);

    // 示例 2: target 不存在
    assert(s.searchMatrix(matrix1, 13) == false);
    assert(s.searchMatrix(matrix1, 0) == false);
    assert(s.searchMatrix(matrix1, 100) == false);

    // 单行矩阵
    vector<vector<int>> matrix2 = {{1,3,5,7}};
    assert(s.searchMatrix(matrix2, 5) == true);
    assert(s.searchMatrix(matrix2, 2) == false);

    // 单列矩阵
    vector<vector<int>> matrix3 = {{1},{10},{23}};
    assert(s.searchMatrix(matrix3, 10) == true);
    assert(s.searchMatrix(matrix3, 5) == false);

    // 单元素矩阵
    vector<vector<int>> matrix4 = {{1}};
    assert(s.searchMatrix(matrix4, 1) == true);
    assert(s.searchMatrix(matrix4, 2) == false);

    return 0;
}