#include "pch.h"

/*
 *给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * 执行用时 :
16 ms
内存消耗 :
9.6 MB
 */
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		len1 = nums1.size();
		len2 = nums2.size();
		int mid = (len1 + len2 + 1) / 2;
		bool is_odd = ((len1 + len2) % 2 == 1);

		for (int i = 0; i < mid - 1; i++)
		{
			getNextNum(nums1, nums2);
		}

		if (is_odd)
			return getNextNum(nums1, nums2);
		else
			return (getNextNum(nums1, nums2) + getNextNum(nums1, nums2)) / 2.0;
	}

private:
	int len1, len2;
	int i1 = 0, i2 = 0;

	int getNextNum(vector<int>& nums1, vector<int>& nums2)
	{
		if (i1 >= len1)
			return nums2[i2++];
		else if (i2 >= len2)
			return nums1[i1++];
		else if (nums1[i1] < nums2[i2])
			return nums1[i1++];
		else
			return nums2[i2++];
	}
};

TEST(leetcode, 4)
{
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(4);

	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2);
}