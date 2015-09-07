#include <vector>
#include <algorithm>

using namespace std;

void bt_subsetWithDup(vector<vector<int>> &ret, vector<int> sub_ret, vector<int> nums, int index)
{
	for (int i = index; i < nums.size(); i++)
	{
		if (i > index && nums[i] == nums[i - 1])
			continue;
		sub_ret.push_back(nums[i]);
		ret.push_back(sub_ret);
		bt_subsetWithDup(ret, sub_ret, nums, i + 1);
		sub_ret.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ret;
	vector<int> sub_ret;
	ret.push_back(sub_ret);
	sort(nums.begin(), nums.end());
	bt_subsetWithDup(ret, sub_ret, nums, 0);
	return ret;
}

int main()
{
	vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 0 };
	vector<vector<int>> ret = subsetsWithDup(data);
	return 0;
}
