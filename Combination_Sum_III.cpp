#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;
		vector<int> sub_ret;
		bfs(ret, sub_ret, 0, 1, k, n);
		return ret;

	}
private:
	void bfs(vector<vector<int>> &ret, vector<int> &sub_ret, int sum, int val, int k, int n)
	{
		if (sub_ret.size() == k)
		{
			if (sum == n)
				ret.push_back(sub_ret);
			return;
		}
		if (sum > n)
			return;

		for (int i = val; i <= 9; i++)
		{
			sum += i;
			if (sum > n)
			{
				sum -= i;
				break;
			}
			sub_ret.push_back(i);
			bfs(ret, sub_ret, sum, i + 1, k, n);
			sub_ret.pop_back();
			sum -= i;
		}
	}
};
