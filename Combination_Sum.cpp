#include <vector>
#include <algorithm>
using namespace std;


void combination(vector< vector<int> > &result, vector<int> sub_ret, vector<int> candidates, int target, int index)
{
	if (index >= candidates.size() || target < 0)
		return;

	if (candidates[index] == target)
	{
		sub_ret.push_back(candidates[index]);
		sort(sub_ret.begin(), sub_ret.end());
		result.push_back(sub_ret);
	}
	else
	{
		sub_ret.push_back(candidates[index]);
		combination(result, sub_ret, candidates, target - candidates[index], index);
		combination(result, sub_ret, candidates, target - candidates[index], index + 1);
		sub_ret.pop_back();
		combination(result, sub_ret, candidates, target, index + 1);
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	vector<int> sub_ret;
	if (candidates.size() == 0)
		return result;

	combination(result, sub_ret, candidates, target, 0);

	sort(result.begin(), result.end());
	vector<vector<int>>::iterator iter;
	iter = unique(result.begin(), result.end());
	result.resize(distance(result.begin(), iter));
	return result;
}

int main()
{
	vector<int> data = { 8, 7, 4, 3 };
	vector<vector<int>> result = combinationSum(data, 11);
	return 0;
}
