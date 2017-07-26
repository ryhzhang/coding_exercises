// MainBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CodeDescription.h"
#include "CodeImpl.h"

ListNode* initializeList(int array[], int size)
{
	ListNode* list = nullptr;
	ListNode* cur = nullptr;
	for (int i = 0; i < size; ++i)
	{
		if (list == nullptr)
		{
			list = new ListNode(array[i]);
			cur = list;
		}
		else
		{
			cur->next = new ListNode(array[i]);
			cur = cur->next;
		}
	}
	return list;
}

void testAddTwoNumbers()
{
	PRINT_DESCRIPTOR(addTwoNumbers);
	int list1Entries[3] = { 2, 4, 3 };
	int list2Entries[3] = { 5, 6, 4 };
	ListNode* l1 = initializeList(list1Entries, 3);
	ListNode* l2 = initializeList(list2Entries, 3);
	ListNode* result = CodeImpl::addTwoNumbers(l1, l2);
	wprintf(L"Result: ");
	while (result != nullptr)
	{
		wprintf(L"%d", result->val);
		result = result->next;
	}
}

void testTwoSums()
{
	PRINT_DESCRIPTOR(twoSums);
	std::vector<int> input = { 2, 7, 10, 30 };
	int target = 9;
	std::vector<int> indexes = CodeImpl::twoSum(input, target);
	wprintf(L"result: %d, %d", indexes[0], indexes[1]);
}

int main()
{
	testAddTwoNumbers();
	return 0;
}

