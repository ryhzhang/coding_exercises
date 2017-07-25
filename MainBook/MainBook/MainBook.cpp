// MainBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CodeDescription.h"
#include "CodeImpl.h"

int main()
{
	PRINT_DESCRIPTOR(twoSums);
	std::vector<int> input = { 2, 7, 10, 30 };
	int target = 9;
	std::vector<int> indexes = CodeImpl::twoSum(input, target);
	wprintf(L"result: %d, %d", indexes[0], indexes[1]);
	return 0;
}

