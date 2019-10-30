/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 *
 * https://leetcode-cn.com/problems/my-calendar-ii/description/
 *
 * algorithms
 * Medium (42.10%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    750
 * Total Submissions: 1.8K
 * Testcase Example:  '["MyCalendarTwo","book","book","book","book","book","book"]\n[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
 *
 * 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。
 * 
 * MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end
 * 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。
 * 
 * 当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。
 * 
 * 每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。否则，返回 false
 * 并且不要将该日程安排添加到日历中。
 * 
 * 请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar();
 * MyCalendar.book(start, end)
 * 
 * 
 * 
 * 示例：
 * 
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(50, 60); // returns true
 * MyCalendar.book(10, 40); // returns true
 * MyCalendar.book(5, 15); // returns false
 * MyCalendar.book(5, 10); // returns true
 * MyCalendar.book(25, 55); // returns true
 * 解释： 
 * 前两个日程安排可以添加至日历中。 第三个日程安排会导致双重预订，但可以添加至日历中。
 * 第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
 * 第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
 * 第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40] 将和第三个日程安排双重预订；
 * 时间 [40,50] 将单独预订，时间 [50,55）将和第二个日程安排双重预订。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个测试用例，调用 MyCalendar.book 函数最多不超过 1000次。
 * 调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。
 * 
 * 
 */
#include "pch.h"
// @lc code=start

/*
const int MAX_LEN = 1000000000;
const int MAX_VAL = 2;
class MyCalendarTwo {
public:
	MyCalendarTwo() {
		root = new SegTreeNode(0, MAX_LEN, 0);
	}

	~MyCalendarTwo() {
		deleteTree(root);
	}

	bool book(int start, int end) {
		if (check(root, start, end - 1) >= MAX_VAL)
			return false;
		update(root, start, end - 1, 1);
		return true;
	}

private:
	struct SegTreeNode {
		int start;
		int end;
		int val;
		bool can_stop;
		SegTreeNode* left;
		SegTreeNode* right;
		SegTreeNode(int s, int e, int v) :start(s), end(e), val(v), left(nullptr), right(nullptr), can_stop(true) {}
		SegTreeNode* Left() {
			if (left == nullptr)
				left = new SegTreeNode(start, (start + end) / 2, 0);
			return left;
		}
		SegTreeNode* Right() {
			if (right == nullptr)
				right = new SegTreeNode((start + end) / 2 + 1, end, 0);
			return right;
		}
	};

	int check(SegTreeNode* node, int start, int end) {
		if (start > end) return 0;
		if (node->start == start && node->end == end)
			return node->val;
		if (node->can_stop)
			return node->val;
		int m = (node->start + node->end) / 2;
		if (m >= end) {
			return check(node->Left(), start, end);
		}
		if (m < start)
			return check(node->Right(), start, end);
		return max(check(node->Left(), start, m), check(node->Right(), m + 1, end));
	}

	int update(SegTreeNode* node, int start, int end, int offset) {
		if (start > end) return 0;
		if (node->can_stop && node->start == start && node->end == end) {
			node->val += offset;
			return node->val;
		}
		int m = (node->start + node->end) / 2;
		if (node->can_stop) {
			update(node->Left(), start, m, node->val);
			update(node->Right(), m + 1, end, node->val);
			node->can_stop = false;
		}
		if (m >= end) {
			node->val = max(node->val, update(node->Left(), start, end, offset));
		}
		else if (m < start) {
			node->val = max(node->val, update(node->Right(), start, end, offset));
		}
		else
			node->val = max(node->val, max(update(node->Left(), start, m, offset), update(node->Right(), m + 1, end, offset)));
		return node->val;
	}

	void deleteTree(SegTreeNode* node) {
		if (node == nullptr) return;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	SegTreeNode* root;
};
*/

//
//int query(int start, int end) {
//	if (s == start && e == end) return val;
//	if (tag) return val;
//	if (end <= m) return Left()->query(start, end);
//	if (start >= m + 1) return Right()->query(start, end);
//	return max(Left()->query(start, m), Right()->query(m + 1, end));
//}
//
//void update(int start, int end, int offset) {
//	if (tag && s == start && e == end) {
//		val += offset;
//		return;
//	}
//	if (tag) {
//		Left()->update(s, m, val);
//		Right()->update(m + 1, e, val);
//		tag = false;
//	}
//	if (end <= m) Left()->update(start, end, offset);
//	else if (start >= m + 1) Right()->update(start, end, offset);
//	else {
//		Left()->update(start, m, offset);
//		Right()->update(m + 1, end, offset);
//	}
//	val = max(Left()->val, Right()->val);
//}
//};

/*
const int times_limit = 2;

class MyCalendarTwo {
public:
	MyCalendarTwo() {
	}

	~MyCalendarTwo() {
		for (auto plan : schedule) {
			delete plan.second;
		}
		schedule.clear();
	}

	bool book(int start, int end) {
		auto pStart = lower_bound(schedule.begin(), schedule.end(), pair<int, Plan*>(start, nullptr), [](pair<int, Plan*> a, pair<int, Plan*> b) {return a.first < b.first; });
		auto pEnd = lower_bound(schedule.begin(), schedule.end(), pair<int, Plan*>(end, nullptr), [](pair<int, Plan*> a, pair<int, Plan*> b) {return a.first < b.first; });
		if (pStart == schedule.begin() && pEnd == schedule.begin()) {
			schedule[start] = new Plan(start, end, 1);
			return true;
		}
		
		if (pStart != schedule.begin()) 
			pStart--;
		for (auto p = pStart; p != pEnd; p++) {
			if (p->second->end > start&& p->second->times == times_limit)
				return false;
		}

		vector<Plan*> insert_que;
		for (auto& p = pStart; p != pEnd; p++) {
			auto& plan = p->second;
			if (plan->end > start&& plan->start < start) {
				int last_end = plan->end;
				plan->end = start;
				if (last_end > end) {
					insert_que.push_back(new Plan(start, end, plan->times + 1));
					insert_que.push_back(new Plan(end, last_end, plan->times));
					start = end;
				}
				else {
					insert_que.push_back(new Plan(start, last_end, plan->times + 1));
					start = last_end;
				}
			}
			else {
				if (plan->start > start) {
					insert_que.push_back(new Plan(start, plan->start, 1));
					start = plan->start;
				}
				if (plan->start == start) {
					if (plan->end > end) {
						insert_que.push_back(new Plan(end, plan->end, plan->times));
						plan->times++;
						plan->end = end;
						start = end;
					}
					else {
						plan->times++;
						start = plan->end;
					}
				}
			}
		}
		for (Plan* plan : insert_que) {
			schedule[plan->start] = plan;
		}
		if (start < end)
			schedule[start] = new Plan(start, end, 1);
		return true;
	}

private:
	struct Plan {
		int start;
		int end;
		int times;
		Plan(int s, int e, int t) : start(s), end(e), times(t) {}
	};

	map<int, Plan*> schedule;
};
*/

struct Node {
    int s;
    int e;
    bool tag;
    int val;
    int m;
    Node* l;
    Node* r;
    Node(int s, int e) : l(nullptr), r(nullptr), s(s), e(e), m((s+e)/2), val(0), tag(true) {}
    Node* Left() {
        if (s == e) return nullptr;
        return l = (l ? l : new Node(s, m));
    }
    Node* Right() {
        if (s == e) return nullptr;
        return r = (r ? r : new Node(m+1, e));
    }
    int query(int start, int end) {
        if (s == start && e == end) return val;
        if (tag) return val;
        if (end <= m) return Left()->query(start, end);
        if (start >= m+1) return Right()->query(start, end);
        return max(Left()->query(start, m), Right()->query(m+1, end));
    }
    void update(int start, int end, int offset) {
        if (tag && s == start && e == end) {
            val += offset;
            return;
        }
        if (tag) {
            Left()->update(s, m, val);
            Right()->update(m+1, e, val);
            tag = false;
        }
        if (end <= m) Left()->update(start, end, offset);
        else if (start >= m+1) Right()->update(start, end, offset);
        else {
            Left()->update(start, m, offset);
            Right()->update(m+1, end, offset);
        }
        val = max(Left()->val, Right()->val);
    }
};

class MyCalendarTwo {
public:
    Node* root;
    MyCalendarTwo() {
        root = new Node(0, 1000000000);
    }
    
    bool book(int start, int end) {
        if (root->query(start, end-1) >= 2) return false;
        root->update(start, end-1, 1);
        return true;
    }
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

TEST(leetcode, testing_731)
{
	MyCalendarTwo obj;
	cout << obj.book(10, 20);
	cout << obj.book(30, 40);
	cout << obj.book(39, 41);
	cout << obj.book(10, 40);
	cout << obj.book(40, 60);
	cout << obj.book(10, 35);
}