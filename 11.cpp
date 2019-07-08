#include "pch.h"

/*  ##description
	给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution
{
public:

	/*24 ms	9.8 MB*/
	int maxArea(vector<int>& height)
	{
		int left = 0, right = height.size() - 1;
		int rst = min(height[0], height[right]) * (height.size() - 1);

		while (left < right)
		{
			if (height[left] < height[right])
			{
				int tmp = height[left];
				while (++left < right && height[left] <= tmp)
					;
				rst = max(rst, min(height[left], height[right]) * (right - left));
			}
			else
			{
				int tmp = height[right];
				while (--right > left && height[right] <= tmp)
					;
				rst = max(rst, min(height[left], height[right]) * (right - left));
			}
		}
		return rst;
	}
};

TEST(leetcode, 11)
{
	Solution s;
	vector<int> a = {1, 8};
	cout << s.maxArea(a) << endl;
}
