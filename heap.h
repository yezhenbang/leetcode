#pragma once
#include <functional>

template<typename T>
class Heap
{
public:
	Heap() = default;
	Heap(std::function<bool(const T&, const T&)> cmp) :comparator_(cmp) {}
	Heap(std::vector<T>& data, std::function<bool(const T&, const T&)> cmp = NULL) :data_(data)
	{
		if (cmp != NULL)
			comparator_ = cmp;
		build();
	}
	~Heap() = default;

	bool empty()
	{
		return data_.empty();
	}

	T& head()
	{
		if (data_.empty())
			throw std::invalid_argument("Heap empty");
		return data_[0];
	}

	void insert(const T& value)
	{
		data_.push_back(value);
		heap_up(data_.size() - 1);
	}

	T pop()
	{
		if (data_.empty())
			throw std::invalid_argument("Heap empty");
		T rst = std::move(data_[0]);
		data_[0] = std::move(data_[data_.size() - 1]);
		data_.pop_back();
		heap_down(0);
		return rst;
	}

	T pop_and_insert(const T& value)
	{
		if (data_.empty())
			throw std::invalid_argument("Heap empty");
		T rst = std::move(data_[0]);
		data_[0] = value;
		heap_down(0);
		return rst;
	}

	size_t size()
	{
		return data_.size();
	}

private:

	std::function<bool(const T&, const T&)> comparator_ = [](const T& a, const T& b) { return a < b; };

	static int father(size_t index) { return (index - 1) / 2; }

	void swap(size_t a, size_t b)
	{
		T tmp = std::move(data_[a]);
		data_[a] = std::move(data_[b]);
		data_[b] = std::move(tmp);
	}

	void build()
	{
		for (int index = data_.size() / 2 - 1; index >= 0; index--)
			heap_down(index);
	}

	void heap_up(size_t index)
	{
		if (index <= 0) 
			return;
		if (!comparator_(data_[father(index)], data_[index]))
		{
			swap(father(index), index);
			heap_up(father(index));
		}
	}

	void heap_down(size_t index)
	{
		if (index >= data_.size() / 2)
			return;
		size_t less_index;
		if (index * 2 + 2 >= data_.size())
			less_index = index * 2 + 1;
		else 
			less_index = comparator_(data_[index * 2 + 1], data_[index * 2 + 2]) ? index * 2 + 1 : index * 2 + 2;
		if (!comparator_(data_[index], data_[less_index]))
		{
			swap(index, less_index);
			heap_down(less_index);
		}
	}

	std::vector<T> data_;
};