#include <vector>
#include <iostream>

using namespace std;

int binary_search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> result;
	int pos = binary_search(nums, target);
	if (pos == -1)
	{
		result.push_back(-1);
		result.push_back(-1);
	}
	else
	{
		int left = pos;
		int right = pos;
		while (left >= 0 && nums[pos] == nums[left])
			left--;
		left++;
		while (right < nums.size() && nums[pos] == nums[right])
			right++;
		right--;
		result.push_back(left);
		result.push_back(right);
	}

	return result;
}

vector<int> searchRange2(vector<int>& nums, int target)
{
	vector<int> result;
	int left = 0;
	int right = nums.size() - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
			continue;
		}
		right = mid - 1;
	}
	if (nums[left] != target)
	{
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
	result.push_back(left);

	right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] > target)
		{
			right = mid - 1;
			continue;
		}
		left = mid + 1;
	}
	if (nums[right] != target)
		result.push_back(result[0]);
	else
		result.push_back(right);

	return result;
}

int main()
{
	vector<int> data = { 5, 7, 7, 8, 8, 10 };
	vector<int> result = searchRange(data, 8);
	return 0;
}
