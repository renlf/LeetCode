#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
	int maj = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (count == 0)
		{
			maj = i;
			count = 1;
		}
		else
		{
			if (nums[i] == nums[maj])
				count++;
			else
				count--;
		}
	}
	return nums[maj];
}
