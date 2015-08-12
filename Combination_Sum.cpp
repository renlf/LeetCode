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
		sub_ret.pop_back();
		combination(result, sub_ret, candidates, target, index + 1);
	}
}

void combination2(vector< vector<int> > &result, vector<int> &sub_ret, vector<int> candidates, int target, int index)
{
	if (index == candidates.size())
	{
		if (target == 0)
			result.push_back(sub_ret);
		return;
	}
	combination2(result, sub_ret, candidates, target, index + 1);
	if (candidates[index] <= target)
	{
		sub_ret.push_back(candidates[index]);
		combination2(result, sub_ret, candidates, target - candidates[index], index);
		sub_ret.pop_back();
	}
}

void combination3(vector< vector<int> > &result, vector<int> &sub_ret, vector<int> candidates, int sum, int target, int index)
{
	if (sum > target)
		return;
	if (sum == target)
	{
		result.push_back(sub_ret);
		return;
	}
	for (int i = index; i < candidates.size(); i++)
	{
		sub_ret.push_back(candidates[i]);
		combination3(result, sub_ret, candidates, sum + candidates[i], target, i);
		sub_ret.pop_back();
	}
}

void combination4(vector< vector<int> > &result, vector<int> sub_ret, vector<int> candidates, int target, int index)
{
	if (target == 0)
	{
		result.push_back(sub_ret);
		return;
	}
	for (int i = index; i < candidates.size(); i++)
	{
		if (target < candidates[i])
			return;
		sub_ret.push_back(candidates[i]);
		combination4(result, sub_ret, candidates, target - candidates[i], i);
		sub_ret.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	vector<int> sub_ret;
	if (candidates.size() == 0)
		return result;
	
	sort(candidates.begin(), candidates.end());
	combination(result, sub_ret, candidates, target, 0);
	
	return result;
}

int main()
{
	vector<int> data = { 8, 7, 4, 3 };
	vector<vector<int>> result = combinationSum(data, 11);
	return 0;
}
