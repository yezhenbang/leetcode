#include "pch.h"
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (50.27%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    47.8K
 * Total Submissions: 95.2K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        raw_.push_back(x);
		if (min_.empty() || x <= min_.back())
			min_.push_back(x);
    }
    
    void pop() {
		if (raw_.empty())
			return;
		int x = raw_.back();
		raw_.pop_back();
		if (!min_.empty() && min_.back() == x)
			min_.pop_back();
    }
    
    int top() {
		if (!raw_.empty())
			return raw_.back();
		return -1;
    }
    
    int getMin() {
		if (!min_.empty())
			return min_.back();
		return -1;
    }

private:
    vector<int> raw_;
    vector<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

