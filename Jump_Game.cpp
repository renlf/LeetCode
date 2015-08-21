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

int main()
{
	vector<int> nums = { 2, 0, 0 };
	bool ret = canJump(nums);
	return 0;
}
