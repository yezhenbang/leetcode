/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 *
 * https://leetcode-cn.com/problems/my-calendar-i/description/
 *
 * algorithms
 * Medium (43.22%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 3.4K
 * Testcase Example:  '["MyCalendar","book","book","book"]\n[[],[10,20],[15,25],[20,30]]'
 *
 * 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。
 * 
 * MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end
 * 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。
 * 
 * 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。
 * 
 * 每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true。否则，返回 false
 * 并且不要将该日程安排添加到日历中。
 * 
 * 请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar();
 * MyCalendar.book(start, end)
 * 
 * 示例 1:
 * 
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(15, 25); // returns false
 * MyCalendar.book(20, 30); // returns true
 * 解释: 
 * 第一个日程安排可以添加到日历中.  第二个日程安排不能添加到日历中，因为时间 15 已经被第一个日程安排预定了。
 * 第三个日程安排可以添加到日历中，因为第一个日程安排并不包含时间 20 。
 * 
 * 
 * 说明:
 * 
 * 
 * 每个测试用例，调用 MyCalendar.book 函数最多不超过 100次。
 * 调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。
 * 
 * 
 */

// @lc code=start
class MyCalendar {
public:
	MyCalendar() {
		root = nullptr;
	}

	~MyCalendar() {
		deleteTree(root);
	}

	bool book(int start, int end) {
		if (root == nullptr) {
			root = new SegTreeNode(start, end);
			return true;
		}
		SegTreeNode* node = root;
		while (node != nullptr) {
			int cross = judgeCrossRightOpen(node->start, node->end, start, end);
			if (cross == 0)
				return false;
			if (cross == -1) {
				if (node->left == nullptr) {
					node->left == new SegTreeNode(start, end);
					return true;
				}
				node = node->left;
			}
			else if (cross == 1) {
				if (node->right == nullptr) {
					node->right = new SegTreeNode(start, end);
					return true;
				}
				node = node->right;
			}
		}
        return false;
	}
	
private:
	struct SegTreeNode {
		int start, end;
		SegTreeNode* left;
		SegTreeNode* right;
		SegTreeNode(int start, int end) : start(start), end(end), left(nullptr), right(nullptr) {}
	};

	bool judgeCrossRightOpen(int al, int ar, int bl, int br) {
		if (br <= al)
			return -1;
		if (bl >= ar)
			return 1;
		return 0;
	}

	void deleteTree(SegTreeNode* node) {
		if (node == nullptr) return;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	SegTreeNode* root = nullptr;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

