#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums) {
	if (nums.size() <= 1)
		return true;
	vector<int>::iterator iter = nums.begin();
	while (iter != nums.end())
	{
		vector<int>::iterator finder = find(iter, nums.end(), 0);
		if (finder == nums.end())
			return true;
		vector<int>::iterator jter = nums.begin();
		for (; jter != finder; jter++)
		{
			if (*jter >= nums.end() - jter - 1)
				return true;
			if (*jter > finder - jter)
				break;
		}
		if (jter == finder)
			return false;
		iter = finder + 1;
	}
}

bool canJump2(vector<int>& nums)
{
	int max_jmp = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (max_jmp >= nums.size() - 1)
			return true;
		if (i > max_jmp)
			return false;
		max_jmp = max(max_jmp, i + nums[i]);
	}
	return false;
}

int main()
{
	vector<int> nums = { 2, 0, 0 };
	bool ret = canJump(nums);
	return 0;
}
