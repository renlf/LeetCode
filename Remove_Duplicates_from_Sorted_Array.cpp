#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 1)
		return nums.size();
	vector<int>::iterator iter = nums.begin() + 1;
	int val = nums[0];
	while (iter != nums.end())
	{
		if ((*iter) == val)
		{
			iter = nums.erase(iter);
		}
		else
		{
			val = *iter;
			iter++;
		}	
	}
	return nums.size();
}

int main()
{
	vector<int> data = {1,1};
	removeDuplicates(data);
	return 0;
}
