#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		//if (mid > 1 && nums[mid] > target && nums[mid - 1] < target)
		//	return mid;
		if (nums[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	vector<int> data = { 1, 3, 5, 6 };
	for (int i = 0; i < 8; i++)
	{
		int result = searchInsert(data, i);
		cout << i << " " << result << endl;
	}
	return 0;
}
