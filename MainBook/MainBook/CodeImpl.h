#pragma once

#include <vector>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class CodeImpl
{
public:
	static std::vector<int> twoSum(std::vector<int>& nums, int target);
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

private:
	static ListNode* reverseList(ListNode* pList);
	static void insertDigit(ListNode** ppInsertionPoint, int value);
};

