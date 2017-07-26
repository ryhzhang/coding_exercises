#include "stdafx.h"
#include "CodeImpl.h"
#include <unordered_map>

/**************************************************************************************************************
Helpers
***************************************************************************************************************/
ListNode* CodeImpl::reverseList(ListNode* pList)
{
	ListNode* revHead = nullptr;
	ListNode* curNode = nullptr;
	ListNode* tmp = nullptr;

	revHead = curNode = pList;
	while (curNode != nullptr && curNode->next != nullptr)
	{
		tmp = curNode->next;
		curNode->next = tmp->next;
		tmp->next = revHead;
		revHead = tmp;
	}

	// [1, h, c]->[2]->[3]
	// [2, h]->[1, c]->[3]
	// [3, h]->[2]->[1,c]

	return revHead;
}

void CodeImpl::insertDigit(ListNode** ppInsertionPoint, int value)
{
	if (ppInsertionPoint == nullptr)
		return;

	if (*ppInsertionPoint == nullptr)
	{
		*ppInsertionPoint = new ListNode(value);
	}
	else
	{
		(*ppInsertionPoint)->next = new ListNode(value);
		*ppInsertionPoint = (*ppInsertionPoint)->next;
	}
}


/**************************************************************************************************************
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**************************************************************************************************************/
std::vector<int> CodeImpl::twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> result;
	std::unordered_map<int, uint32_t> visited;

	int pos = 0;
	for (int num : nums)
	{
		int pairing = target - num;
		auto match = visited.find(pairing);
		if (match != visited.cend())
		{
			// found it
			result.push_back(match->second);
			result.push_back(pos);
			break;
		}
		else
		{
			visited.insert({ num, pos });
		}

		++pos;
	}
	return result;
}

/**************************************************************************************************************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in
reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked
list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
***************************************************************************************************************/
ListNode* CodeImpl::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *llNumber = nullptr;
	ListNode *cur = llNumber;
	ListNode* l1Cur = l1;
	ListNode* l2Cur = l2;

	// reverse each list O(N)
	if (l1Cur != nullptr || l2Cur != nullptr)
	{
		// add every element to its counter part and remember the carry
		int carry = 0;
		while (l1Cur != nullptr || l2Cur != nullptr || carry)
		{
			int add1 = l1Cur == nullptr ? 0 : l1Cur->val;
			int add2 = l2Cur == nullptr ? 0 : l2Cur->val;
			int sum = add1 + add2 + carry;

			carry = sum / 10;
			if (llNumber == nullptr)
			{
				llNumber = new ListNode(sum % 10);
				cur = llNumber;
			}
			else
			{
				cur->next = new ListNode(sum % 10);
				cur = cur->next;
			}


			l1Cur = l1Cur == nullptr ? nullptr : l1Cur->next;
			l2Cur = l2Cur == nullptr ? nullptr : l2Cur->next;
		}
	}

	return llNumber;
}
