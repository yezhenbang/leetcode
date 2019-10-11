#include "pch.h"

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33]
 */

// @lc code=start
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		if (l > r)
			return -1;
		int m = find_rotate_point(nums, l, r);

		if (target >= nums[l])
			return search_sorted(nums, l, m, target);
		else
			return search_sorted(nums, m + 1, r, target);
	}

private:
	int find_rotate_point(vector<int>& nums, int l, int r)
	{
		if (l > r)
			return -1;
		
		int m = (l + r) / 2;
		if (m == 0 || nums[m - 1] < nums[m])
			if (m == nums.size() - 1 || nums[m] > nums[m + 1])
				return m;
		if (nums[l] <= nums[m])
			return find_rotate_point(nums, m + 1, r);
		else
			return find_rotate_point(nums, l, m - 1);
	}

	int search_sorted(vector<int>& nums, int l, int r, int target)
	{
		if (l > r)
			return -1;
		int m = (l + r) / 2;
		if (target == nums[m])
			return m;
		if (target > nums[m])
			return search_sorted(nums, m + 1, r, target);
		return search_sorted(nums, l, m - 1, target);
	}
};
// @lc code=end

TEST(leetcode, 33)
{
	vector<int> nums = {};
	vector<int> nums2 = { 1 };
	vector<int> nums3 = { 0 };
	vector<int> nums4 = { 7,0,1,2,3,4,5,6 };
	Solution s;
	cout << s.search(nums, 0) << endl;
	cout << s.search(nums2, 0) << endl;
	cout << s.search(nums3, 0) << endl;
	cout << s.search(nums4, 0) << endl;
}
