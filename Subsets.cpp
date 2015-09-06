#include <vector>
#include <algorithm>

using namespace std;

void bt_subsets(vector<vector<int>> &ret, vector<int> sub_ret, vector<int> nums,int index)
{
	if (index == nums.size())
	{
		ret.push_back(sub_ret);
		return;
	}
	bt_subsets(ret, sub_ret, nums, index + 1);
	sub_ret.push_back(nums[index]);
	bt_subsets(ret, sub_ret, nums, index + 1);
	sub_ret.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> ret;
	vector<int> sub_ret;
	sort(nums.begin(), nums.end());
	bt_subsets(ret, sub_ret, nums, 0);
	return ret;
}

int main()
{
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> ret = subsets(nums);
	return 0;
}
