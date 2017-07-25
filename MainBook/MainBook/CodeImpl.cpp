#include "stdafx.h"
#include "CodeImpl.h"
#include <unordered_map>

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
