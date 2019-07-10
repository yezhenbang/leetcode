#include "pch.h"

/*  ##description
	给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution18 {
public:
	void threeSum2(vector<int>& nums, int left, int right, int target, vector<vector<int>>& rst) {
		if (right - left + 1 < 3)
			return;

		for (int i = left; i < right - 1; i++)
		{
			if (i > left && nums[i] == nums[i - 1])
				continue;
			int l = i + 1, r = right;
			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == target)
				{
					vector<int> one = { nums[i], nums[l], nums[r] };
					rst.push_back(one);
					while (l < r && nums[++l] == nums[l - 1])
						;
					while (l < r && nums[--r] == nums[r + 1])
						;
					continue;
				}
				if (sum > target)
					r--;
				else
					l++;
			}
		}
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> rst;
		if (nums.size() < 4)
			return rst;

		for (int i = 0; i < nums.size() - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			vector<vector<int>> sub_rst;
			threeSum2(nums, i + 1, nums.size() - 1, target - nums[i], sub_rst);
			for (vector<int>& sub : sub_rst)
			{
				sub.push_back(nums[i]);
				rst.push_back(sub);
			}
		}

		return rst;
	}
};

TEST(leetcode, 18)
{
	vector<int> nums = { 0,0,0,0};
	Solution18 s;
	auto rst = s.fourSum(nums, 0);
	for (auto& i : rst)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}
