/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (46.33%)
 * Likes:    3209
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include <vector>
#include <stdio.h>
using std::vector;
// @lc code=start

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int l = 0, r = nums.size();
        // 找到第一个大于等于target的位置
        while (l < r) {
            int mid = l + (r -l)/2;
            
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        vector<int> res;
        if (l >= nums.size() || nums[l] != target) return {-1, -1};
        res.push_back(l);
        // 找到第一个大于target的位置，前面说明至少target存在，所以后续r-1可以不判断
        r = nums.size();
        while (l < r) {
            int mid = l + (r -l)/2;
            if (nums[mid] <= target) {
                l = mid +1;
            } else {
                r = mid;
            }
        }
        res.push_back(r-1);
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{4,5,6,7,7,8,9};
    vector<int> res = s.searchRange(nums ,7);
    printf("res:[%d,%d]\n", res[0], res[1]);
    return 0;
}
