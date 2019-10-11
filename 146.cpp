#include "pch.h"

/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 缓存容量 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include "util\hash_map.h"
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146]
 */

 // @lc code=start

class LRUCache {
public:
	LRUCache(int capacity) : hash_map_(HashMap<int, LinkNode*>(capacity)){
		size_ = capacity;
	}

	~LRUCache() {
		hash_map_.clear();
		while (head_ != nullptr)
		{
			tail_ = head_->next;
			delete head_;
			head_ = tail_;
		}
	}

	int get(int key) {
		LinkNode* p;
		if (hash_map_.try_get(key, p))
		{
			int value = p->value;
			touch(p);
			return value;
		}
		return -1;
	}

	void put(int key, int value) {
		LinkNode* p;
		if (hash_map_.try_get(key, p))  
		{
			p->value = value;
			touch(p);
			return;
		}
		
		LinkNode* tmp = new LinkNode;
		tmp->key = key;
		tmp->value = value;
		hash_map_.add(key, tmp);
		touch(tmp);
		if (hash_map_.size() > size_) {
			drop();
		}
	}
private:

	struct LinkNode {
		LinkNode* pre = nullptr;
		LinkNode* next = nullptr;
		int key;
		int value;
	};

	void touch(LinkNode* node) {
		if (head_ == nullptr) {
			head_ = node;
			tail_ = node;
			return;
		}
		if (hash_map_.size() == 1)
			return;

		if (head_ == node)
			return;

		if (node->pre != nullptr) {
			node->pre->next = node->next;
		}
		if (node->next != nullptr) {
			node->next->pre = node->pre;
		}

		if (tail_ == node)
			tail_ = node->pre;

		node->pre = nullptr;
		node->next = head_;
		if (head_ != nullptr) {
			head_->pre = node;
		}
		head_ = node;
	}

	void drop() {
		LinkNode* tmp = tail_;
		tail_ = tail_->pre;
		tail_->next = nullptr;
		hash_map_.erase(tmp->key);
		delete tmp;
	}

	int size_;
	LinkNode* head_ = nullptr;
	LinkNode* tail_ = nullptr;
	HashMap<int, LinkNode*> hash_map_;

};
// @lc code=end

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);

 ["LRUCache","get","put","get","put","put","get","get"]
[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
 */

TEST(leetcode, 146)
{
	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1);       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache.get(2);       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache.get(1);       // 返回 -1 (未找到)
	cout << cache.get(3);       // 返回  3
	cout << cache.get(4);       // 返回  4
	cout << endl;


	LRUCache cache2(2);

	cout << cache2.get(2);
	cache2.put(2, 6);
	cout << cache2.get(1);
	cache2.put(1, 5);
	cache2.put(1, 2);
	cout << cache2.get(1);
	cout << cache2.get(2);

}