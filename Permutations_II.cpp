#include <vector>
#include <algorithm>

using namespace std;

void permute_bk(vector<vector<int>> &ret, vector<int> sub_ret, vector<int> nums)
{
	if (nums.size() == 0)
	{
		ret.push_back(sub_ret);
		return;
	}
	vector<int>::iterator iter = nums.begin();
	for (; iter != nums.end(); iter++)
	{
		if (iter != nums.begin() && (*(iter - 1)) == (*iter))
			continue;
		int val = *iter;
		sub_ret.push_back(*iter);
		iter = nums.erase(iter);
		permute_bk(ret, sub_ret, nums);
		sub_ret.pop_back();
		iter = nums.insert(iter, val);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> ret;
	vector<int> sub_ret;
	sort(nums.begin(), nums.end());
	permute_bk(ret, sub_ret, nums);
	return ret;
}

