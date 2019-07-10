//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

inline void showAndDeleteList(ListNode* head)
{
	auto i = head;
	while (i)
	{
		cout << i->val << "->";
		auto tmp = i;
		i = i->next;
		delete tmp;
	}
}

template <typename T>
void showVector(vector<T> vec)
{
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

