#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	if (nums.size() == 0)
		return 0;
	int index = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val)
			continue;
		
		nums[index] = nums[i];
		index++;
	}
	nums.resize(index);
	return index;
}

int main()
{
	vector<int> data = { 1, 2 };
	removeElement(data, 1);
	return 0;
}
