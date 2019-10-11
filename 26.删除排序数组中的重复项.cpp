/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int head = 0; int tail = 1;
		for (; tail < nums.size(); tail++)
		{
			if (nums[head] == nums[tail])
				continue;

			head++;
			nums[head] = nums[tail];
		}

		return head + 1;
	}
};
// @lc code=end

