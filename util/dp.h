#pragma once
#include <string>
#include <stdexcept>

class ENotFound : public std::exception
{
public:
	typedef std::exception _Mybase;

	explicit ENotFound(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{
	}

	explicit ENotFound(const char* _Message)
		: _Mybase(_Message)
	{
	}

};

template<typename T>
class DPData
{
public:
	DPData() = delete;
	DPData(size_t size) :size_(size) {
		data_ = (T * *)malloc(sizeof(T*) * size_);
		for (int i = 0; i < size_; i++)
			data_[i] = (T*)malloc(sizeof(T) * size_);
	}
	~DPData() {
		for (int i = 0; i < size_; i++)
			free(data_[i]);
		free(data_);
	}

	void set(size_t i1, size_t i2, T data) {
		if (i1 >= 0 && i1 < size_ && i2 >= 0 && i2 < size_)
		{
			data_[i1][i2] = data;
		}
	}

	T get(size_t i1, size_t i2) {
		if (i1 >= 0 && i1 < size_ && i2 >= 0 && i2 < size_)
			return data_[i1][i2];
		throw std::overflow_error("(" + to_string(i1) + "," + to_string(i2) + ") out of range.");
	}

	T get(size_t i1, size_t i2, T overflow_data) {
		if (i1 >= 0 && i1 < size_ && i2 >= 0 && i2 < size_)
			return data_[i1][i2];
		return overflow_data;
	}

private:
	size_t size_;
	T** data_;
};


