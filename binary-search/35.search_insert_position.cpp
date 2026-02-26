/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <vector>
using std::vector;
 
// @lc code=start

class Solution {
public:
    // 找到第一个大于等于target的数
    int searchInsert(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int mid = l + ((r - l) / 2);
        while (l < r) {
            mid = l + ((r - l) / 2);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid; 
            }
        }
        return l;
    }
};
// @lc code=end

