#include "pch.h"

/*  ##description
	给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution15 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> rst;
		if (nums.size() < 3)
			return rst;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[left] + nums[right] == 0)
				{
					vector<int> one = { nums[i], nums[left], nums[right] };
					rst.push_back(one);
					while (left < right && nums[++left] == nums[left - 1]) 
						;
					while (left < right && nums[--right] == nums[right + 1]) 
						;
					continue;
				}
				if (nums[i] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				if (nums[i] + nums[left] + nums[right] < 0)
				{
					left++;
				}
			}
		}

		return rst;
	}
};

TEST(leetcode, 15)
{
	vector<int> nums = { -1,0,1};
	Solution15 s;
	auto& rst = s.threeSum(nums);
	for (auto& i : rst)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}
