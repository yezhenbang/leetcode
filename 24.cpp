#include "pch.h"
#include "heap.h"

/*  ##description
 *  城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。现在，假设您获得了城市风光照片（图A）上显示的所有建筑物的位置和高度，请编写一个程序以输出由这些建筑物形成的天际线（图B）。

每个建筑物的几何信息用三元组 [Li，Ri，Hi] 表示，其中 Li 和 Ri 分别是第 i 座建筑物左右边缘的 x 坐标，Hi 是其高度。可以保证 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX 和 Ri - Li > 0。您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。

例如，图A中所有建筑物的尺寸记录为：[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] 。

输出是以 [ [x1,y1], [x2, y2], [x3, y3], ... ] 格式的“关键点”（图B中的红点）的列表，它们唯一地定义了天际线。关键点是水平线段的左端点。请注意，最右侧建筑物的最后一个关键点仅用于标记天际线的终点，并始终为零高度。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

例如，图B中的天际线应该表示为：[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]。

说明:

任何输入列表中的建筑物数量保证在 [0, 10000] 范围内。
输入列表已经按左 x 坐标 Li  进行升序排列。
输出列表必须按 x 位排序。
输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-skyline-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
[[0,5,7],[5,10,7],[5,10,12],[10,15,7],[15,20,7],[15,20,12],[20,25,7]]
输出
[[0,7],[5,12],[10,0],[15,12],[20,7],[25,0]]
预期结果
[[0,7],[5,12],[10,7],[15,12],[20,7],[25,0]]
 */

enum b
{
	left = 0,
	right = 1,
	height = 2
};

class Solution
{
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
	{
		vector<vector<int>> rst;

		Heap<vector<int>> heap([](const vector<int>& a, const vector<int>& b) { return a[height] > b[height]; });
		sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b) {
			if (a[b::left] < b[b::left])
				return true;
			if (a[b::left] == b[b::left])
				return a[height] > b[height];
			return false;
		});
		buildings.push_back({ INT_MAX, INT_MAX, -1 });

		for (int i = 0; i < buildings.size(); i++)
		{
			while (!heap.empty() && (heap.head()[b::right] < buildings[i][b::left] || buildings[i][b::height] == -1))
			{
				vector<int> tmp = heap.pop();
				while (!heap.empty() && heap.head()[b::right] <= tmp[b::right])
					heap.pop();
				if (!heap.empty())
					rst.push_back({ tmp[b::right], heap.head()[b::height] });
				else
					rst.push_back({ tmp[b::right], 0 });
			}

			if (heap.empty() || buildings[i][b::height] > heap.head()[b::height])
			{
				rst.push_back({ buildings[i][b::left], buildings[i][b::height] });
			}
			heap.insert(buildings[i]);
		}

		rst.pop_back();
		return rst;

		vector<int> cover;

		for (int i = 0; i < buildings.size(); i++)
		{
			while (!heap.empty() && (heap.head()[b::right] < buildings[i][b::left] || buildings[i][b::left] == -1))
			{
				if (cover.empty())
				{
					cover = heap.pop();
					if (!heap.empty() && cover[b::right] >= heap.head()[b::left] && cover[b::right] < heap.head()[b::right])
						rst.push_back({ cover[b::right], heap.head()[b::height] });
					else
						rst.push_back({ cover[b::right], 0 });
				}
				else
				{
					if (cover[b::right] < heap.head()[b::right])
					{
						cover = heap.pop();
						 
						if (!heap.empty() && cover[b::right] >= heap.head()[b::left] && cover[b::right] < heap.head()[b::right])
							rst.push_back({ cover[b::right], heap.head()[b::height] });
						else
							rst.push_back({ cover[b::right], 0 });
					}
					else
					{
						heap.pop();
					}
				}
			}
			if (heap.empty())
			{
				if (!cover.empty())
					cover.clear();
				rst.push_back({ buildings[i][b::left], buildings[i][b::height] });
				heap.insert(buildings[i]);
			}
			else
			{
				if (heap.head()[b::height] < buildings[i][b::height])
					rst.push_back({ buildings[i][b::left], buildings[i][b::height] });
				heap.insert(buildings[i]);
			}
		}

		rst.pop_back();
		return rst;
	}
};

TEST(leetcode, testing_)
{
	// vector<vector<int>> data = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 25, 8} };
	vector<vector<int>> data = { {2, 9, 10}, {3, 25, 15}, {5, 25, 12}, {15, 25, 10}, {19, 25, 8} };
	// vector<vector<int>> data = { {2, 3, 10}, {3, 7, 10}, {5, 12, 10}, {15, 20, 10}, {19, INT_MAX, 8} };
	// vector<vector<int>> data = { {0, 5, 7}, {5, 10, 7}, {5, 10, 12}, {10, 15, 7}, {15, 20, 7} , {15, 20, 12} , {20, 25, 7} };
	// vector<vector<int>> data = {};
	Solution s;
	data = s.getSkyline(data);
	for (auto i : data)
	{
		showVector<int>(i);
		cout << endl;
	}
}
