#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
	int red_index = 0;
	int blue_index = nums.size() - 1;
	for (int i = 0; i <= blue_index;)
	{
		if (nums[i] == 0)
		{
			swap(nums[i], nums[red_index]);
			red_index++;
			i++;
		}
		else if (nums[i] == 1)
		{
			i++;
			continue;
		}
		else
		{
			swap(nums[i], nums[blue_index]);
			blue_index--;
		}
	}
}

int main()
{
	vector<int> color = {1, 0};
	sortColors(color);
	return 0;
}
