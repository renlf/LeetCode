#include <vector>

using namespace std;

void reverse(vector<int>& nums, int left, int right)
{
	while (right > left)
	{
		swap(nums[left], nums[right]);
		left++;
		right--;
	}
}

void nextPermutation(vector<int>& nums) {
	if (nums.size() < 2)
		return;
	int i;
	int j;
	bool flag = false;
	for (i = nums.size() - 2; i >= 0 && flag == false; i--)
	{
		if (nums[i] > nums[i + 1])
			continue;
		for (j = nums.size() - 1; j > i; j--)
		{
			if (nums[j] > nums[i])
			{
				swap(nums[j], nums[i]);
				flag = true;
				break;
			}
		}
	}
	if (flag)
	{
		reverse(nums, i + 2, nums.size() - 1);
	}
	else
	{
		reverse(nums, 0, nums.size() - 1);
	}
}

int main()
{
	vector<int> data;
	for (int i = 1; i < 6; i++)
	{
		data.push_back(i);
	}
	while (true)
	{
		nextPermutation(data);
	}
	return 0;
}
