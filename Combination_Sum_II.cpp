#include <vector>
#include <algorithm>

using namespace std;

void combination(vector<vector<int>> &result, vector<int> &sub_ret, vector<int> candidates, int target, int index)
{
    if (target == 0)
    {
        result.push_back(sub_ret);
        return;
    }
    int pr = -1;
    for (int i = index; i < candidates.size(); i++)
    {
        if (pr == candidates[i])
            continue;
        if (target < candidates[i])
            return;
        pr = candidates[i];
        sub_ret.push_back(candidates[i]);
        combination(result, sub_ret, candidates, target - candidates[i], i + 1);
        sub_ret.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector< vector<int> > result;
    vector<int> sub_ret;
    sort(candidates.begin(), candidates.end());
    combination(result, sub_ret, candidates, target, 0);
    return result;
}
