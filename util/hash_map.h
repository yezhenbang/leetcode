#pragma once
#include <functional>

template <typename TKey, typename TValue>
class HashMap
{
public:
	HashMap(long capacity, std::function<long(const TKey&)> hashFun = nullptr) : m_maxSize(capacity)
	{
		m_data.resize(capacity);
		for (int i = 0; i < capacity; i++)
			m_data[i] = nullptr;

		m_hashFun = hashFun == nullptr ? default_hashFun : hashFun;
	}

	~HashMap()
	{
	}

	void clear()
	{
		for (int i = 0; i < m_maxSize; i++)
			if (m_data[i] != nullptr)
			{
				auto p = m_data[i];
				while (p != nullptr)
				{
					auto tmp = p->next;
					p.reset();
					p = tmp;
				}
				m_data[i] = nullptr;
			}
	}

	void add(const TKey& key, const TValue& value)
	{
		long i = m_hashFun(key);
		if (m_data[i] == nullptr)
		{
			m_data[i] = std::make_shared<HashData>();
			m_data[i]->key = key;
			m_data[i]->value = value;
			m_data[i]->next = nullptr;
			m_size++;
			return;
		}

		auto p = m_data[i];
		while (p->key != key && p->next != nullptr)
			p = p->next;
		if (p->key == key)
		{
			p->value = value;
			return;
		}
		p->next = std::make_shared<HashData>();
		p->next->key = key;
		p->next->value = value;
		p->next->next = nullptr;
		m_size++;
	}

	bool try_get(const TKey& key, TValue& value)
	{
		long i = m_hashFun(key);
		auto p = m_data[i];
		while (p != nullptr)
		{
			if (p->key == key)
				break;
			p = p->next;
		}
		if (p == nullptr)
			return false;

		value = p->value;
		return true;
	}

	void erase(const TKey& key)
	{
		long i = m_hashFun(key);
		auto p = m_data[i];
		if (p == nullptr)
			return;
		if (p->key == key)
		{
			m_data[i] = p->next;
			p.reset();
			m_size--;
			return;
		}

		while (p->next != nullptr && p->next->key != key)
			p = p->next;
		if (p->next == nullptr)
			return;
		if (p->next->key == key)
		{
			auto tmp = p->next;
			p->next = tmp->next;
			tmp.reset();
			m_size--;
		}
	}

	long size()
	{
		return m_size;
	}

private:

	template <typename TpKey, typename TpValue>
	struct LinkNode
	{
		std::shared_ptr<LinkNode<TpKey, TpValue>> next;
		TpKey key;
		TpValue value;
	};
	typedef LinkNode<TKey, TValue> HashData;

	long m_maxSize = 32767;
	long m_size = 0;
	std::vector<std::shared_ptr<HashData>> m_data;
	std::function<long(const TKey&)> m_hashFun;
	std::function<long(const TKey&)> default_hashFun = [&](const TKey& value) { return value % m_maxSize; };
};
