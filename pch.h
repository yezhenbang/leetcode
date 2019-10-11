//
// pch.h
// Header for standard system include files.
//

#pragma once

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include "gtest/gtest.h"
#include "common_define.h"

using namespace std;


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

