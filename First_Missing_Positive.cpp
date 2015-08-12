#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	vector<int> tmp;
	tmp.resize(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0 && nums[i] <= nums.size())
			tmp[nums[i] - 1] = nums[i];
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] != i + 1)
			return i + 1;
	}
	return nums.size() + 1;
}

int firstMissingPositive2(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
    {
		while (nums[i] != i + 1)
		{
			if (nums[i] < 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
				break;
			swap(nums[i], nums[nums[i] - 1]);
		}
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;
}

int main()
{
	vector<int> data = {3, 4, -1, 1};
	int result = firstMissingPositive(data);
	return 0;
}
