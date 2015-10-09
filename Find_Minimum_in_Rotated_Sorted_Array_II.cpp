#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
	int left = 0;
	int right = nums.size() - 1;
	while (left < right)
	{
		if (nums[left] < nums[right])
			break;

		int mid = (left + right) / 2;
		if (nums[mid] > nums[right])
			left = mid + 1;
		else if (nums[mid] < nums[right])
		{
			right = mid;
		}
		else
		{
			right--;
		}
	}
	return nums[left];
}
