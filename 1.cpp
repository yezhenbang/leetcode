#include "pch.h"

/*
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> rst;
		map<int, int> map_num_index;
		int index = 0;

		for (auto i : nums)
		{
			auto p = map_num_index.find(target - i);
			if (p != map_num_index.end())
			{
				rst.push_back(p->second);
				rst.push_back(index);
				return rst;
			}
			map_num_index[i] = index;
            ++index;
		}
        return rst;
	}
};
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> rst;
		map<int, int> map_num_index;

		for (int i = 0; i < nums.size(); i++)
		{
			auto p = map_num_index.find(target - nums[i]);
			if (p != map_num_index.end())
			{
				rst.push_back(p->second);
				rst.push_back(i);
				break;
			}
			map_num_index[nums[i]] = i;
		}
		return rst;
	}
};

TEST(leetcode, 1)
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	// nums.push_back(19);
	Solution s;
	auto rst = s.twoSum(nums, 6);
	for (auto i: rst)
	{
		cout << i << " ";
	}
}